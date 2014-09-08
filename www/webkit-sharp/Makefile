# $FreeBSD$

PORTNAME=	webkit-sharp
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	www

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono bindings for Webkit

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	mono
GH_COMMIT=	4d50e3c

PLIST_SUB+=	ASSEMBLY_VERSION=1.1.15

GNU_CONFIGURE=	yes
USES=		gmake mono pathfix pkgconfig
USE_GNOME=	gtksharp20
PATHFIX_MAKEFILEIN=	Makefile.am

USE_AUTOTOOLS=	aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing -i -f

.include <bsd.port.mk>
