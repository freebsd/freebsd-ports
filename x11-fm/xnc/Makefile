# New ports collection makefile for:	xnc
# Version required:	4.0.8
# Date created:		5 February 1999
# Whom:			Dima Sivachenko	<dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	xnc-4.0.8.src
PKGNAME=	xnc-4.0.8
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.chg.ru/pub/Linux/sunsite/X11/desktop/	\
		ftp://sunsite.unx.edu/pub/Linux/X11/desktop/

MAINTAINER=	dima@chg.ru

RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip		\
		unzip:${PORTSDIR}/archivers/unzip	\
		rpm:${PORTSDIR}/misc/rpm		\
		rar:${PORTSDIR}/archivers/rar		\
		unarj:${PORTSDIR}/archivers/unarj	\
		lha:${PORTSDIR}/archivers/lha		\
		bzip2:${PORTSDIR}/archivers/bzip2

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

do-install:
		@ ${INSTALL_SCRIPT} ${WRKSRC}/findslave.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/users.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/groups.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/rpm.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/zips.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/gzip.xnc ${PREFIX}/bin
		@ ${INSTALL_SCRIPT} ${WRKSRC}/bzip.xnc ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/nc ${PREFIX}/bin/xnc
		@ ${INSTALL_PROGRAM} ${WRKSRC}/ives/ives ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/ives/es ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/ives/vs ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/xsetup/xncsetup ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/xjroot/xjpegroot ${PREFIX}/bin
		@ ${INSTALL_PROGRAM} ${WRKSRC}/launch/xnlaunch ${PREFIX}/bin
		@ ${INSTALL_MAN} ${WRKSRC}/xnc.1 ${MAN1PREFIX}/man/cat1
		@ ${GZIP_CMD} ${MAN1PREFIX}/man/cat1/xnc.1
		@ ${INSTALL_MAN} ${WRKSRC}/ives/ives.1 ${MAN1PREFIX}/man/cat1
		@ ${GZIP_CMD} ${MAN1PREFIX}/man/cat1/ives.1
		@ ${INSTALL_MAN} ${WRKSRC}/xjroot/xjpegroot.1 ${MAN1PREFIX}/man/cat1
		@ ${GZIP_CMD} ${MAN1PREFIX}/man/cat1/xjpegroot.1
		@ ${INSTALL_MAN} ${WRKSRC}/launch/xnlaunch.1 ${MAN1PREFIX}/man/cat1
		@ ${GZIP_CMD} ${MAN1PREFIX}/man/cat1/xnlaunch.1

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/xnc
		${INSTALL_DATA} ${WRKSRC}/Docs/* ${PREFIX}/share/doc/xnc
.endif

.include <bsd.port.mk>
