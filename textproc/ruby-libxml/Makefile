# New ports collection makefile for:	ruby-libxml
# Date created:		09 July 2002
# Whom:	      		Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libxml
PORTVERSION=	0.3.2
CATEGORIES=	textproc ruby
MASTER_SITES=	http://www.rubynet.org/modules/xml/libxml/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	A friendly API to libxml for Ruby

BUILD_DEPENDS=	${LOCALBASE}/bin/xml2-config:${PORTSDIR}/textproc/libxml2
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2

PLIST_FILES=	%%RUBY_SITEARCHLIBDIR%%/xml/libxml.so
USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

.include <bsd.port.mk>
