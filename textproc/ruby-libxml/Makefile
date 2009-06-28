# New ports collection makefile for:	ruby-libxml
# Date created:		09 July 2002
# Whom:	      		Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	1.1.3
CATEGORIES=	textproc ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	libxml
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A friendly API to libxml for Ruby

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_RUBY=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${PORTNAME}-ruby-${PORTVERSION}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
