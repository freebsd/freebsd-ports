# New ports collection makefile for:	imap-uw
# Date created:		9 Jan 1997
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	imap
PORTVERSION=	2000c
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cac.washington.edu/imap/%SUBDIR%/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.cac.washington.edu/mail/%SUBDIR%/ \
		http://mirror.nucba.ac.jp/mirror/imap/%SUBDIR%/ \
		ftp://ftp.uni-halle.de/pub/mail/pine/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMESUFFIX=	-uw
DISTFILES=	${DISTNAME}.tar.Z \
		imap-utils.tar.Z

MAINTAINER=	petef@databits.net

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient
.if defined(WITH_DRAC)
BUILD_DEPENDS=	${LOCALBASE}/lib/libdrac.a:${PORTSDIR}/mail/drac
.endif

MAN8=		ipopd.8 imapd.8
ALL_TARGET=	bsf

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

.if defined(WITH_DRAC)
post-install:
	@${ECHO} "================================================================================"
	@${ECHO} "To have DRAC working, you must create ${PREFIX}/etc/dracd.host, containing"
	@${ECHO} "the hostname of the DRAC server:"
	@${ECHO}
	@${ECHO} "localhost"
	@${ECHO} "================================================================================"
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
