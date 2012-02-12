# Ports collection makefile for:  textproc/rubygem-augeas
# Date created:			  19 May 2010
# Whom:				  Russell Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	ruby-augeas
PORTVERSION=	0.4.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	http://augeas.net/download/ruby/

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for Augeas

LIB_DEPENDS=	augeas.15:${PORTSDIR}/textproc/augeas

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_GNOME=	pkgconfig libxml2
RUBYGEM_AUTOPLIST=	yes
CONFIGURE_ARGS+=	--with-opt-include="${LOCALBASE}/include/libxml2"

.include <bsd.port.mk>
