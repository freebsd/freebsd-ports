# $FreeBSD$

PORTNAME=	webkit-sharp
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	www

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:www/webkit-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Uses webkit-gtk2 which has security issues
EXPIRATION_DATE=2019-03-24

USE_GITHUB=	yes
GH_ACCOUNT=	mono

PLIST_SUB+=	ASSEMBLY_VERSION=1.1.15

GNU_CONFIGURE=	yes
USES=		autoreconf gmake mono pathfix pkgconfig
USE_GNOME=	gtksharp20

.include <bsd.port.mk>
