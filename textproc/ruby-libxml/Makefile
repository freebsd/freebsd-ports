# New ports collection makefile for:	ruby-libxml
# Date created:		09 July 2002
# Whom:	      		Sean Chittenden <sean@chittenden.org>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	0.01
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubynet.org/modules/xml/ruby-libxml/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-20020709

MAINTAINER=	sean@chittenden.org

BUILD_DEPENDS=	${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2
RUN_DEPENDS=	${BUILD_DEPENDS}
#LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.mk>
