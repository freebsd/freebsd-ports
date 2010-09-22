# Ports collection makefile for:	rubygem-nokogiri
# Date created:				17 May 2009
# Whom:						Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.4.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	An HTML, XML, SAX, and Reader parser

RUN_DEPENDS=	rubygem-hoe>=2.3.3:${PORTSDIR}/devel/rubygem-hoe

USE_GNOME=	libxml2 libxslt

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/nokogiri

.include <bsd.port.mk>
