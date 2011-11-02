# Ports collection makefile for:	jekyll
# Date created:				2009-12-24
# Whom:					Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	0.11.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

RUN_DEPENDS=	rubygem-classifier>=1.3.1:${PORTSDIR}/devel/rubygem-classifier \
		rubygem-redcloth>=4.2.1:${PORTSDIR}/www/rubygem-redcloth \
		rubygem-liquid>=1.9.0:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-maruku>=0.5.9:${PORTSDIR}/www/rubygem-maruku \
		rubygem-directory_watcher>=1.1.1:${PORTSDIR}/devel/rubygem-directory_watcher \
		rubygem-open4>=0.9.6:${PORTSDIR}/devel/rubygem-open4 \
		rubygem-albino>=1.3.2:${PORTSDIR}/textproc/rubygem-albino \
		rubygem-kramdown>=0.13.2:${PORTSDIR}/textproc/rubygem-kramdown

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
