# $FreeBSD$

PORTNAME=	webkit-gtk2
PORTVERSION=	2.0.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/WebKitGtk2 is a Ruby binding of WebKitGTK+ for Gtk 2.0 Toolkit

RUN_DEPENDS=	rubygem-gtk2>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection
LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
