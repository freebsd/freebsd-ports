# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	libmcrypt
PORTVERSION=	2.5.8
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/mcrypt/Libmcrypt/${PORTVERSION}

MAINTAINER=	john@essenz.com
COMMENT=	Multi-cipher cryptographic library (used in PHP)

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		libtool
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-static
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
