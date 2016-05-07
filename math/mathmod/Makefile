# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	MathMod
PORTVERSION=	4.0
CATEGORIES=	math graphics
MASTER_SITES=	SF/${PORTNAME:tl}/${PKGNAME}/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}-src

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mathematical modeling software

LICENSE=	GPLv2

USES=		dos2unix zip
USE_GL=		yes
USE_QT5=	buildtools_build core gui opengl qmake_build widgets

BRANCHE=	246
WRKSRC=		${WRKDIR}/${PORTNAME:tl}-branches-${BRANCHE}-trunk

PLIST_FILES=	bin/MathMod

# LL / ULL suffix would be needed for integer constants
BROKEN_FreeBSD_9_i386=	YES

pre-build:
	cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${QMAKE}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ARGET/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
