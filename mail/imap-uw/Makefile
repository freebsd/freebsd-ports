# New ports collection makefile for:	imap-uw
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap
PORTVERSION=	2002
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/ \
		http://atreides.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/%SUBDIR%/
PKGNAMESUFFIX=	-uw
DISTNAME=	imap-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.Z imap-utils.tar.Z

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient
.if defined(WITH_DRAC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

MAN8=		ipopd.8 imapd.8

ALL_TARGET=	bsf
.if defined(WITH_SSL)
MAKE_ARGS+=	SSLTYPE=unix.nopwd
USE_OPENSSL=	yes
.endif

# RFC 1730 (IMAP4 as opposed to IMAP4rev1) support
.if defined(WITH_RFC1730)
MAKE_ARGS+=	RFC1730="-DRFC1730"
FORBIDDEN=	"RFC 1730 support enables remote buffer overflow."
.endif
# Define this to get somewhat better interoperability with Netscape.
.if defined(WITH_NETSCAPE_BRAIN_DAMAGE)
MAKE_ARGS+=	WITH_NETSCAPE_BRAIN_DAMAGE=yes
.endif
# Define this to get somewhat better interoperability with Microsoft
# Outlook and Outlook Express.
.if defined(WITH_MICROSOFT_BRAIN_DAMAGE)
MAKE_ARGS+=	MSBD="-DMICROSOFT_BRAIN_DAMAGE"
.endif
# See src/imapd/Makefile for more information about these three options.

SOURCEDIRS_IMAPUTILS=	chkmail dmail icat ifrom imapcopy imapxfer mbxcopy \
			mbxcreat mbxcvt tmail
.if defined(WITH_ALL_IMAPUTILS)
MAN1=	chkmail.1 dmail.1 icat.1 ifrom.1 imapcopy.1 imapxfer.1 mbxcopy.1 \
	mbxcreat.1 mbxcvt.1 tmail.1
PLIST_SUB+=	IMAPUTILS=''
.else
PLIST_SUB+=	IMAPUTILS='@comment '
.endif

.include <bsd.port.pre.mk>

pre-extract:
	@${SH} ${PKGREQ}.rev ${LOCALBASE}/include/c-client/portrevision.h ${PORTVERSION}

pre-build:
.if defined(WITH_SSL)
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h yes
.else
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h no
.endif

post-build:
	@(cd ${WRKDIR}/mlock; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)
.if defined(WITH_ALL_IMAPUTILS)
.for d in ${SOURCEDIRS_IMAPUTILS}
	@${ECHO} "Building ${d}."
	(cd ${WRKDIR}/${d}; ${CC} ${CFLAGS} -I${LOCALBASE}/include/c-client \
	-o ${d} ${d}.c -L${LOCALBASE}/lib -lc-client4 -lssl -lcrypto)
.endfor
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g mail -m 2711 \
		${WRKDIR}/mlock/mlock ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8c ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8c ${PREFIX}/man/man8/ipopd.8
.if defined(WITH_ALL_IMAPUTILS)
.for d in ${SOURCEDIRS_IMAPUTILS}
	@${ECHO} "Installing ${d}."
	${INSTALL_PROGRAM} ${WRKDIR}/${d}/${d} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKDIR}/${d}/${d}.1 ${PREFIX}/man/man1
.endfor
	(cd ${PREFIX}/bin; ${LN} -s imapcopy imapmove)
	(cd ${PREFIX}/bin; ${LN} -s mbxcopy mbxmove)
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
.if defined(WITH_DRAC)
	@${ECHO} "================================================================================"
	@${ECHO} "To have DRAC working, you must create ${PREFIX}/etc/dracd.host, containing"
	@${ECHO} "the hostname of the DRAC server:"
	@${ECHO}
	@${ECHO} "localhost"
	@${ECHO} "================================================================================"
.endif
.if defined(WITH_SSL)
	@${ECHO} "To create and install a new SSL certificate for imapd and ipop3d, type \"make"
	@${ECHO} "cert\". Or install manually in ${PREFIX}/certs."
	@${ECHO}
	@${ECHO} "Example inetd config for SSL only services:"
	@${ECHO}
	@${ECHO} "pop3s   stream  tcp     nowait  root    ${PREFIX}/libexec/ipop3d       ipop3d"
	@${ECHO} "imaps   stream  tcp     nowait  root    ${PREFIX}/libexec/imapd        imapd"
	@${ECHO}
	@${ECHO} "Remember to recompile and reinstall your cclient port with SSL support too, if"
	@${ECHO} "you had it installed without SSL support."
	@${ECHO} "================================================================================"
.endif

cert:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/certs
	@openssl req -new -x509 -days 365 -nodes -config ${FILESDIR}/imap-uw.cnf -out ${PREFIX}/certs/imapd.pem -keyout ${PREFIX}/certs/imapd.pem
	@openssl x509 -subject -dates -fingerprint -noout -in ${PREFIX}/certs/imapd.pem
	@${CHMOD} 700 ${PREFIX}/certs/imapd.pem
	@${LN} -s ${PREFIX}/certs/imapd.pem ${PREFIX}/certs/ipop3d.pem

.include <bsd.port.post.mk>
