# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.6.2.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

BUILD_DEPENDS=	rubygem-mini_portile=0.6.0:${PORTSDIR}/devel/rubygem-mini_portile
RUN_DEPENDS=	rubygem-mini_portile=0.6.0:${PORTSDIR}/devel/rubygem-mini_portile

LICENSE=	MIT

GEM_ENV=	LC_CTYPE=UTF-8

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/nokogiri

.include <bsd.port.mk>
