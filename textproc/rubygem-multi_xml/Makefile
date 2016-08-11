# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	multi_xml
PORTVERSION=	0.5.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby library provide swappable XML backends

LICENSE=	MIT

OPTIONS_DEFINE=	NOKOGIRI
NOKOGIRI_DESC=	Nokogiri is a HTML, XML, SAX, and Reader parser

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

NOKOGIRI_RUN_DEPENDS=	rubygem-nokogiri>=0:textproc/rubygem-nokogiri

.include <bsd.port.mk>
