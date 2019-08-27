# $FreeBSD$

PORTNAME=	inputstream.adaptive
DISTVERSION=	2.4.0.a20190826
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	kodi-devel>=19.0.a20190826:multimedia/kodi-devel
LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	kodi-devel>=19.0.a20190826:multimedia/kodi-devel

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d
GH_TAGNAME=	7074cc804b9ce996b54afebe855968f1f35e2985

PLIST_SUB=	SOVERSION=${DISTVERSION:R}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/addons/inputstream.adaptive/libssd_wv.so

.include <bsd.port.mk>
