# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	ruby-augeas
PORTVERSION=	0.5.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	http://download.augeas.net/ruby/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for Augeas

LIB_DEPENDS=	augeas:${PORTSDIR}/textproc/augeas

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USES=		pkgconfig
USE_GNOME=	libxml2
RUBYGEM_AUTOPLIST=	yes
CONFIGURE_ARGS+=	--with-opt-include="${LOCALBASE}/include/libxml2"

.include <bsd.port.mk>
