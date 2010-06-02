# Ports collection makefile for:  textproc/rubygem-augeas
# Date created:			  19 May 2010
# Whom:				  Russell Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	ruby-augeas
PORTVERSION=	0.3.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	http://augeas.net/download/ruby/

MAINTAINER=	raj@csub.edu
COMMENT=	Ruby bindings for Augeas

LIB_DEPENDS=	augeas.10:${PORTSDIR}/textproc/augeas

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_GNOME=	pkgconfig
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
