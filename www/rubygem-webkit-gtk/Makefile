# $FreeBSD$

PORTNAME=	webkit-gtk
PORTVERSION=	2.2.5
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/WebKitGTK is a Ruby binding of WebKitGTK+

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libwebkitgtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
RUN_DEPENDS=	rubygem-gobject-introspection>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-gobject-introspection \
		rubygem-gtk3>=${PORTVERSION}:${PORTSDIR}/x11-toolkits/rubygem-gtk3

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
