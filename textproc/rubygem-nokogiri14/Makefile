# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.4.0
PKGNAMESUFFIX=	14
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
USE_GNOME=	libxml2 libxslt
USES=		pkgconfig
CONFIGURE_ARGS=	--use-system-libraries	

# Don't install bin/nokogiri

.include <bsd.port.mk>
