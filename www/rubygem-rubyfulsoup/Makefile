# $FreeBSD$

PORTNAME=	rubyfulsoup
PORTVERSION=	1.0.4
CATEGORIES=	www textproc rubygems
MASTER_SITES=	RG
DISTNAME=	rubyful_soup-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby port of the HTML/XML parser Beautiful Soup

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

RUN_DEPENDS=	rubygem-htmltools>=1.10:${PORTSDIR}/textproc/rubygem-htmltools

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
