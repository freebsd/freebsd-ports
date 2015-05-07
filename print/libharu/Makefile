# Created by: ijliao
# $FreeBSD$

PORTNAME=	libharu
DISTVERSIONPREFIX=	RELEASE_
DISTVERSION=	2_3_0
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Haru Free PDF Library

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

OPTIONS_DEFINE=	EXAMPLES

USE_LDCONFIG=	yes
USES+=		cmake:outsource
CMAKE_ARGS+=	-DDEVPAK:BOOL=ON

USE_GITHUB=	yes

SOVERSION=	2
PLIST_SUB+=	SOVERSION=${SOVERSION}
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
CMAKE_ARGS+=	-DLIBHPDF_EXAMPLES:BOOL=ON  \
    		-DEXAMPLESDIR:STRING=share/examples/${PORTNAME}
.endif

post-install:
	${LN} -s libhpdf.so ${STAGEDIR}${PREFIX}/lib/libhpdf.so.${SOVERSION}

.include <bsd.port.mk>
