# $FreeBSD$

PORTNAME=	obs-streamfx
DISTVERSION=	0.8.0b1
PORTREVISION=	1
CATEGORIES=	multimedia

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	aafddeda7fffc7261a72401a591098567c43e81b.patch:-p1 # https://github.com/Xaymar/obs-StreamFX/pull/165

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	OBS Studio Plugin: Modern effects

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libobs.so:multimedia/obs-studio

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Xaymar
GH_PROJECT=	obs-StreamFX

CMAKE_ARGS=	-DOBS_STUDIO_DIR=${LOCALBASE}/lib

.include <bsd.port.mk>
