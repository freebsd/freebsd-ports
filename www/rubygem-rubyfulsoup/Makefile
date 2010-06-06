# Ports collection makefile for:	rubyfulsoup
# Date created:				16 feb 2007
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	rubyfulsoup
PORTVERSION=	1.0.4
CATEGORIES=	www textproc rubygems
MASTER_SITES=	RG
DISTNAME=	rubyful_soup-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Ruby port of the HTML/XML parser Beautiful Soup

RUN_DEPENDS=	rubygem-htmltools>=1.10:${PORTSDIR}/textproc/rubygem-htmltools

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
