# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	2.5.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-classifier-reborn>=2.0:${PORTSDIR}/devel/rubygem-classifier-reborn \
		rubygem-colorator>=0.1:${PORTSDIR}/textproc/rubygem-colorator \
		rubygem-jekyll-coffeescript>=1.0:${PORTSDIR}/devel/rubygem-jekyll-coffeescript \
		rubygem-jekyll-gist>=1.0:${PORTSDIR}/textproc/rubygem-jekyll-gist \
		rubygem-jekyll-paginate>=1.0:${PORTSDIR}/textproc/rubygem-jekyll-paginate \
		rubygem-jekyll-sass-converter>=1.0:${PORTSDIR}/textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=1.1:${PORTSDIR}/www/rubygem-jekyll-watch \
		rubygem-kramdown>=1.3:${PORTSDIR}/textproc/rubygem-kramdown \
		rubygem-liquid2>=2.6.1:${PORTSDIR}/textproc/rubygem-liquid2 \
		rubygem-mercenary>=0.3.3:${PORTSDIR}/devel/rubygem-mercenary \
		rubygem-pygments.rb>=0.6.0:${PORTSDIR}/devel/rubygem-pygments.rb \
		rubygem-redcarpet>=3.1:${PORTSDIR}/textproc/rubygem-redcarpet \
		rubygem-safe_yaml>=1.0:${PORTSDIR}/devel/rubygem-safe_yaml \
		rubygem-toml>=0.1.0:${PORTSDIR}/devel/rubygem-toml

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
