# Ports collection makefile for:	jekyll
# Date created:				2009-12-24
# Whom:					Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	0.5.4
CATEGORIES=	www
MASTER_SITES=	RG

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	A is a simple, blog aware, static site generator

RUN_DEPENDS=	rubygem-classifier>=1.3.1:${PORTSDIR}/devel/rubygem-classifier \
		rubygem-redcloth>=4.2.1:${PORTSDIR}/www/rubygem-redcloth \
		rubygem-liquid>=1.9.0:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-maruku>=0.5.9:${PORTSDIR}/www/rubygem-maruku \
		rubygem-directory_watcher>=1.1.1:${PORTSDIR}/devel/rubygem-directory_watcher \
		rubygem-open4>=0.9.6:${PORTSDIR}/devel/rubygem-open4

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
