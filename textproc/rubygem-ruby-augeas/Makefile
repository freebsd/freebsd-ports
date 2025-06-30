PORTNAME=	ruby-augeas
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for Augeas
WWW=		https://augeas.net/ \
		https://github.com/hercules-team/ruby-augeas

LICENSE=	LGPL21

LIB_DEPENDS=	libaugeas.so:textproc/augeas

USES=		gem gnome pkgconfig
USE_GNOME=	libxml2

CONFIGURE_ARGS=	--with-opt-include=${LOCALBASE}/include/libxml2

.include <bsd.port.mk>
