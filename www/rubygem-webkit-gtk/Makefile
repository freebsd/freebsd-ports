# $FreeBSD$

PORTNAME=	webkit-gtk
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/WebKitGTK is a Ruby binding of WebKitGTK+

RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3 \
		rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection
LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
