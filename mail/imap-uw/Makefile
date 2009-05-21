# New ports collection makefile for:	imap-uw
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap
PORTVERSION=	2007e
PORTEPOCH=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/%SUBDIR%/ \
		http://atreides.freenix.no/~anders/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	-uw
DISTNAME=	imap-${PORTVERSION}
DISTFILES=	${DISTNAME}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}

MAINTAINER=	anders@FreeBSD.org
COMMENT=	University of Washington IMAP4rev1/POP2/POP3 mail servers

# This port must have the same SSL settings as mail/cclient, which it depends on
# To make MBX format the default mailbox format, change the settings of cclient

OPTIONS=	SSL "Compile with SSL support" on \
		SSL_AND_PLAINTEXT "Allow plain text passwords and SSL" off \
		DRAC "Dynamically open MTA for relaying" off \
		NETSCAPE_BRAIN_DAMAGE "See Makefile for documentation" off

.include <bsd.port.pre.mk>

LIB_DEPENDS=	c-client4.9:${PORTSDIR}/mail/cclient
.if defined(WITH_DRAC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
MAKE_ARGS+=	WITH_DRAC=yes
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/${DISTNAME}

MAN1=		dmail.1 mailutil.1 tmail.1
MAN8=		ipopd.8 imapd.8

ALL_TARGET=	bsf
.if defined(WITHOUT_SSL)
MAKE_ARGS+=	SSLTYPE=none SSLDIR=${OPENSSLBASE}
.else
USE_OPENSSL=	yes
.if defined(WITH_SSL_AND_PLAINTEXT)
MAKE_ARGS+=	SSLTYPE=unix
.else
MAKE_ARGS+=	SSLTYPE=unix.nopwd
.endif
.endif

# Define this to get somewhat better interoperability with Netscape.
.if defined(WITH_NETSCAPE_BRAIN_DAMAGE)
MAKE_ARGS+=	WITH_NETSCAPE_BRAIN_DAMAGE=yes
.endif
# See src/imapd/Makefile for more information about these three options.

pre-build:
	@${SH} ${PKGREQ}.rev ${LOCALBASE}/include/c-client/portrevision.h ${PORTVERSION}
.if !defined(WITHOUT_SSL)
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h yes
.else
	@${SH} ${PKGREQ}.ssl ${LOCALBASE}/include/c-client/portrevision.h no
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapd/imapd ${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop2d ${PREFIX}/libexec/
	${INSTALL_PROGRAM} ${WRKSRC}/ipopd/ipop3d ${PREFIX}/libexec/
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g mail -m 2711 \
		${WRKSRC}/mlock/mlock ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/mtest/mtest ${PREFIX}/bin/mboxtest
	${INSTALL_MAN} \
		${WRKSRC}/src/imapd/imapd.8 ${PREFIX}/man/man8/imapd.8
	${INSTALL_MAN} \
		${WRKSRC}/src/ipopd/ipopd.8 ${PREFIX}/man/man8/ipopd.8
	${INSTALL_PROGRAM} ${WRKSRC}/dmail/dmail ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/mailutil/mailutil ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tmail/tmail ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/src/dmail/dmail.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/src/mailutil/mailutil.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/src/tmail/tmail.1 ${PREFIX}/man/man1/

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
.if !defined(WITHOUT_SSL)
	@${ECHO}
	@${ECHO} "To create and install a new SSL certificate for imapd and ipop3d, type \"make"
	@${ECHO} "cert\". Or install manually in ${PREFIX}/certs."
	@${ECHO}
	@${ECHO} "Example inetd config for SSL only services:"
	@${ECHO}
	@${ECHO} "pop3s   stream  tcp     nowait  root    ${PREFIX}/libexec/ipop3d       ipop3d"
	@${ECHO} "imaps   stream  tcp     nowait  root    ${PREFIX}/libexec/imapd        imapd"
	@${ECHO} "================================================================================"
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} -m 0755 -p ${DOCSDIR}
	@${TAR} -C ${WRKSRC}/docs -cf - . | \
		(umask 022; ${TAR} -C ${DOCSDIR} -xf -)
.endif

cert:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/certs
	@openssl req -new -x509 -days 365 -nodes -config ${FILESDIR}/imap-uw.cnf -out ${PREFIX}/certs/imapd.pem -keyout ${PREFIX}/certs/imapd.pem
	@openssl x509 -subject -dates -fingerprint -noout -in ${PREFIX}/certs/imapd.pem
	@${CHMOD} 700 ${PREFIX}/certs/imapd.pem
	@${LN} -s ${PREFIX}/certs/imapd.pem ${PREFIX}/certs/ipop3d.pem

.include <bsd.port.post.mk>
