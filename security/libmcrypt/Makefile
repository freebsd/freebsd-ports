# Created by: nsayer@FreeBSD.org
# $FreeBSD$

PORTNAME=	libmcrypt
PORTVERSION=	2.5.8
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/mcrypt/Libmcrypt/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-cipher cryptographic library (used in PHP)

USES=		libtool:oldver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
