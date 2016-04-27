# $FreeBSD$

PORTNAME=	webkit-gtk
PORTVERSION=	3.0.8
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/WebKitGTK is a Ruby binding of WebKitGTK+

LICENSE=	LGPL21+

LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:devel/rubygem-gobject-introspection \
		rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
