PORTNAME=	libretls
PORTVERSION=	3.8.1
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	https://causal.agency/libretls/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	TLS library designed to ease writing foolproof applications
WWW=		https://git.causal.agency/libretls/about/

LICENSE=	ISCL

USES=	libtool ssl pkgconfig
INSTALL_TARGET=	install-strip
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

USE_LDCONFIG=	yes

.include <bsd.port.mk>
