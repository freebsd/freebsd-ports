# Ports collection makefile for:	rubygem-nokogiri
# Date created:				17 May 2009
# Whom:						Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.2.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RF

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	An HTML, XML, SAX, and Reader parser

BUILD_DEPENDS=	${RUBY_PKGNAMEPREFIX}iconv>=0:${PORTSDIR}/converters/ruby-iconv
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	libxml2 libxslt

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
