# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	ruby-augeas
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for Augeas

LICENSE=	LGPL21

LIB_DEPENDS=	libaugeas.so:textproc/augeas

CONFIGURE_ARGS=	--with-opt-include="${LOCALBASE}/include/libxml2"
USE_GNOME=	libxml2
USE_RUBY=	yes
USES=		gem pkgconfig

.include <bsd.port.mk>
