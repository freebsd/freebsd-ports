PORTNAME=	libmdf
PORTVERSION=	1.0.26
CATEGORIES=	net finance
MASTER_SITES=	https://packages.millistream.com/source/

MAINTAINER=	henrik.holst@millistream.com
COMMENT=	Millistream Data Feed API library

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pkgconfig ssl

GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
