PORTNAME=	xdelta
DISTVERSION=	3.2.0
PORTEPOCH=	1
CATEGORIES=	misc devel
MASTER_SITES=	https://github.com/jmacd/xdelta/releases/download/v${DISTVERSION}/
PKGNAMESUFFIX=	3
DISTNAME=	xdelta3-${DISTVERSION}

MAINTAINER=	oss@tbarabosch.com
COMMENT=	Binary diff and VCDIFF/RFC 3284 delta compression tool
WWW=		https://github.com/jmacd/xdelta

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libblake3.so:devel/libblake3

USES=		cmake:testing compiler:c++11-lang pathfix

CMAKE_ARGS=	-DFETCHCONTENT_TRY_FIND_PACKAGE_MODE=ALWAYS \
		-DXD3_LZMA_MODE=on
CMAKE_ON=	XD3_ARMOR XD3_BUILD_LIB
CMAKE_OFF=	XD3_BUILD_TESTS XD3_LZMA_FETCH
CMAKE_TESTING_ON=	XD3_BUILD_TESTS

WRKSRC_SUBDIR=	xdelta3

post-patch:
	@${REINPLACE_CMD} -e \
		'/_POSIX_/d ; \
		 /_C99_/d' ${WRKSRC}/xdelta3.h

.include <bsd.port.mk>
