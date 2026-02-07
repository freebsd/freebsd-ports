PORTNAME=	libebml
DISTVERSION=	1.4.5
CATEGORIES=	textproc
MASTER_SITES=	https://dl.matroska.org/downloads/${PORTNAME}/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	EBML (Extensible Binary Meta Language), sort of binary version of XML
WWW=		https://www.matroska.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

BUILD_DEPENDS=	${LOCALBASE}/include/utf8cpp/utf8/checked.h:devel/utf8cpp

USES=		cmake compiler:c++14-lang cpe localbase pathfix tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	matroska

EXTRACT_AFTER_ARGS=	--exclude src/lib

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
