# Ports collection makefile for:	rubygem-maruku
# Date created:				26 April 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	maruku
PORTVERSION=	0.6.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	avl@FreeBSD.org
COMMENT=	A Markdown and PHP Markdown extra interpreter for Ruby

RUN_DEPENDS=	rubygem-syntax>=1.0.0:${PORTSDIR}/textproc/rubygem-syntax

USE_RUBY=	yes
USE_RUBYGEMS=	yes
USE_RUBY_FEATURES=	iconv
RUBYGEM_AUTOPLIST=  yes
PLIST_FILES=	bin/maruku bin/marutex

.include <bsd.port.mk>
