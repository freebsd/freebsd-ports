# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	2.4.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT

RUN_DEPENDS=	rubygem-classifier-reborn>=2.0:${PORTSDIR}/devel/rubygem-classifier-reborn \
		rubygem-colorator>=0.1:${PORTSDIR}/textproc/rubygem-colorator \
		rubygem-kramdown>=1.3:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-liquid>=2.6.1:${PORTSDIR}/textproc/rubygem-liquid \
		rubygem-mercenary>=0.3.3:${PORTSDIR}/devel/rubygem-mercenary \
		rubygem-pygments.rb>=0.6.0:${PORTSDIR}/devel/rubygem-pygments.rb \
		rubygem-redcarpet>=3.1:${PORTSDIR}/textproc/rubygem-redcarpet \
		rubygem-safe_yaml>=1.0:${PORTSDIR}/devel/rubygem-safe_yaml \
		rubygem-toml>=0.1.0:${PORTSDIR}/devel/rubygem-toml \
		rubygem-jekyll-coffeescript>=1.0.0:${PORTSDIR}/devel/rubygem-jekyll-coffeescript \
		rubygem-jekyll-gist>=1.0.0:${PORTSDIR}/textproc/rubygem-jekyll-gist \
		rubygem-jekyll-paginate>=1.0.0:${PORTSDIR}/textproc/rubygem-jekyll-paginate \
		rubygem-jekyll-sass-converter>=1.0.0:${PORTSDIR}/textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=1.1.0:${PORTSDIR}/www/rubygem-jekyll-watch

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
