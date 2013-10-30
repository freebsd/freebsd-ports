# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

RUN_DEPENDS=	rubygem-classifier>=1.3:${PORTSDIR}/devel/rubygem-classifier \
		rubygem-colorator>=0.1:${PORTSDIR}/textproc/rubygem-colorator \
		rubygem-commander>=4.1.3:${PORTSDIR}/devel/rubygem-commander \
		rubygem-directory_watcher>=1.4.1:${PORTSDIR}/devel/rubygem-directory_watcher \
		rubygem-kramdown>=1.0.2:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-liquid>=2.3:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-maruku>=0.5:${PORTSDIR}/www/rubygem-maruku \
		rubygem-pygments.rb>=0.5.0:${PORTSDIR}/devel/rubygem-pygments.rb \
		rubygem-safe_yaml>=0.7.0:${PORTSDIR}/devel/rubygem-safe_yaml

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
