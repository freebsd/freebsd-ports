PORTNAME=	ruby-augeas
PORTVERSION=	0.5.0
PORTREVISION=	4
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for Augeas
WWW=		https://augeas.net/

LICENSE=	LGPL21

LIB_DEPENDS=	libaugeas.so:textproc/augeas

USES=		gem gnome pkgconfig
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--with-opt-include="${LOCALBASE}/include/libxml2"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
