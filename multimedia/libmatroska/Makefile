PORTNAME=	libmatroska
DISTVERSION=	1.7.1
CATEGORIES=	multimedia audio
MASTER_SITES=	https://dl.matroska.org/downloads/libmatroska/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Extensible Multimedia Container Format
WWW=		https://www.matroska.org/

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.LGPL

LIB_DEPENDS=	libebml.so:textproc/libebml

USES=		cmake compiler:c++14-lang cpe tar:xz
USE_LDCONFIG=	yes
CPE_VENDOR=	matroska

CMAKE_ARGS=	-DBUILD_SHARED_LIBS=YES

.include <bsd.port.mk>
