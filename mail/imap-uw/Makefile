# New ports collection makefile for:	imap-uw
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap
PORTVERSION=	0104031813
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/%SUBDIR%/ \
		http://mirror.nucba.ac.jp/mirror/imap/%SUBDIR%/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	-uw
DISTNAME=	imap-2001.BETA.SNAP-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.Z imap-utils.tar.Z

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient
.if defined(WITH_DRAC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif
.if defined(WITH_SSL)
USE_OPENSSL=	yes
.endif

MAN8=		ipopd.8 imapd.8
.if defined(WITH_SSL)
ALL_TARGET=	bsf SSLTYPE=unix
.else
ALL_TARGET=	bsf
.endif

.include <bsd.port.pre.mk>

pre-extract:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} foo PRE-INSTALL || ${FALSE}
.endif

post-build:
	@(cd ${WRKDIR}/mlock; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)

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
	@${ECHO} "cert\"."
	@${ECHO}
	@${ECHO} "Example inetd config for the SSL services:"
	@${ECHO}
	@${ECHO} "pop3s   stream  tcp     nowait  root    /usr/local/libexec/ipop3d       ipop3d"
	@${ECHO} "imaps   stream  tcp     nowait  root    /usr/local/libexec/imapd        imapd"
	@${ECHO}
	@${ECHO} "Remember to recompile and reinstall your cclient port with SSL support too, if"
	@${ECHO} "you had it installed without SSL support."
	@${ECHO}
	@${ECHO} "================================================================================"
.endif

cert:
	@${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/certs
	@openssl req -new -x509 -days 365 -nodes -config ${FILESDIR}/imap-uw.cnf -out ${PREFIX}/certs/imapd.pem -keyout ${PREFIX}/certs/imapd.pem
	@openssl x509 -subject -dates -fingerprint -noout -in ${PREFIX}/certs/imapd.pem
	@${CHMOD} 700 ${PREFIX}/certs/imapd.pem
	@${LN} -s ${PREFIX}/certs/imapd.pem ${PREFIX}/certs/ipop3d.pem

.include <bsd.port.post.mk>
