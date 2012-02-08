# Ports collection makefile for:	jekyll
# Date created:				2009-12-24
# Whom:					Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	0.11.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

RUN_DEPENDS=	rubygem-albino>=1.3.2:${PORTSDIR}/textproc/rubygem-albino \
		rubygem-classifier>=1.3.1:${PORTSDIR}/devel/rubygem-classifier \
		rubygem-directory_watcher>=1.1.1:${PORTSDIR}/devel/rubygem-directory_watcher \
		rubygem-kramdown>=0.13.2:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-liquid>=1.9.0:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-maruku>=0.5.9:${PORTSDIR}/www/rubygem-maruku

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
