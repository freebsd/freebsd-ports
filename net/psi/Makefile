# New ports collection makefile for:	psi
# Date created:		Wed May  1 20:27:23 NZST 2002
# Whom:			jonc@chen.org.nz
#
# $FreeBSD$
#

PORTNAME=	psi
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jonc@chen.org.nz

LIB_DEPENDS=	qt-mt.3:${PORTSDIR}/x11-toolkits/qt30

USE_X_PREFIX=	yes
USE_BZIP2=	yes

BUILD_WRKSRC=	${WRKSRC}/src
MAKE_ARGS=	QTDIR=${X11BASE}
EXTRA_PATCHES=	${WRKDIR}/patch-common.cpp

pre-patch:
	${SED} s,%%DATADIR%%,${DATADIR}, ${PATCHDIR}/template.patch-common.cpp > \
		${WRKDIR}/patch-common.cpp

pre-build:
	cd ${BUILD_WRKSRC}; qmake -spec ${X11BASE}/mkspecs/freebsd-g++ psi.pro

do-install:
	@${MKDIR} ${DATADIR}
	@cd ${INSTALL_WRKSRC}; \
		${CP} -r image iconsets sound certs README COPYING ${DATADIR}
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/psi ${PREFIX}/bin

.include <bsd.port.mk>
