# $FreeBSD$

PORTNAME=	inputstream.adaptive
DISTVERSION=	2.5.6
DISTVERSIONSUFFIX=	-Matrix
CATEGORIES=	multimedia
PKGNAMEPREFIX=	kodi-addon-
PKGNAMESUFFIX=	-devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Adaptive stream support for Kodi

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.GPL

BUILD_DEPENDS=	kodi-devel>=19.0.a20200414:multimedia/kodi-devel
LIB_DEPENDS=	libexpat.so:textproc/expat2
RUN_DEPENDS=	kodi-devel>=19.0.a20200414:multimedia/kodi-devel

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	peak3d

PLIST_SUB=	SOVERSION=${DISTVERSION}

post-extract:
	${MV} ${WRKSRC}/inputstream.adaptive/resources/resource.language.sk_sk \
		${WRKSRC}/inputstream.adaptive/resources/language

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/kodi/addons/inputstream.adaptive/libssd_wv.so
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/kodi/addons/inputstream.adaptive/resources/language \
		-name strings.po >> ${TMPPLIST}

.include <bsd.port.mk>
