# Ports collection makefile for:	rubygem-multi_xml
# Date created:				4 March 2011
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	multi_xml
PORTVERSION=	0.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Ruby library provide swappable XML backends

OPTIONS=	NOKOGIRI "Nokogiri is a HTML, XML, SAX, and Reader parser" off

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_NOKOGIRI)
RUN_DEPENDS+=	rubygem-nokogiri>=0:${PORTSDIR}/textproc/rubygem-nokogiri
.endif

.include <bsd.port.post.mk>
