PORTNAME=	libretls
PORTVERSION=	3.3.4
CATEGORIES=	security devel
MASTER_SITES=	https://causal.agency/libretls/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	TLS library designed to ease writing foolproof applications

LICENSE=	ISCL

BROKEN_FreeBSD_11=	requires newer OpenSSL

USES=	libtool ssl pkgconfig
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes

USE_LDCONFIG=	yes

.include <bsd.port.mk>
