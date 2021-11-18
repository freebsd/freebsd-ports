PORTNAME=	libhsts
PORTVERSION=	0.1.0
CATEGORIES=	www security
MASTER_SITES=	https://gitlab.com/rockdaboot/libhsts/uploads/4753f61b5a3c6253acf4934217816e3f/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to check a domain against the Chromium HSTS Preload list

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool python:build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--disable-doc
TEST_TARGET=	check

.include <bsd.port.mk>
