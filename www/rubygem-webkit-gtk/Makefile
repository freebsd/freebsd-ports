# $FreeBSD$

PORTNAME=	webkit-gtk
PORTVERSION=	3.3.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby/WebKitGTK is a Ruby binding of WebKitGTK+

LICENSE=	LGPL21+

BUILD_DEPENDS=	rubygem-rake>=0:devel/rubygem-rake
LIB_DEPENDS=	libwebkitgtk-3.0.so:www/webkit-gtk3
RUN_DEPENDS=	rubygem-gtk3>=${PORTVERSION}:x11-toolkits/rubygem-gtk3

DEPRECATED=	Uses webkit-gtk3 which has security issues
EXPIRATION_DATE=2019-03-24

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
