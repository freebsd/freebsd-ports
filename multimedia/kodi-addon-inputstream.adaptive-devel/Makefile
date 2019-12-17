# $FreeBSD$

PORTNAME=	inputstream.adaptive
DISTVERSION=	2.5.3
DISTVERSIONSUFFIX=	-Matrix
PORTREVISION=	1
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	kodi-devel>=19.0.a20191216:multimedia/kodi-devel
LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	kodi-devel>=19.0.a20191216:multimedia/kodi-devel

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d

PLIST_SUB=	SOVERSION=${DISTVERSION}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/addons/inputstream.adaptive/libssd_wv.so

.include <bsd.port.mk>
