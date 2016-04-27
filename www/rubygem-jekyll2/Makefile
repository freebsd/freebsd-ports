# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	2.5.3
PORTREVISION=	2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-classifier-reborn>=2.0:devel/rubygem-classifier-reborn \
		rubygem-colorator>=0.1:textproc/rubygem-colorator \
		rubygem-jekyll-coffeescript>=1.0:devel/rubygem-jekyll-coffeescript \
		rubygem-jekyll-gist>=1.0:textproc/rubygem-jekyll-gist \
		rubygem-jekyll-paginate>=1.0:textproc/rubygem-jekyll-paginate \
		rubygem-jekyll-sass-converter>=1.0:textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=1.1:www/rubygem-jekyll-watch \
		rubygem-kramdown>=1.3:textproc/rubygem-kramdown \
		rubygem-liquid2>=2.6.1:textproc/rubygem-liquid2 \
		rubygem-mercenary>=0.3.3:devel/rubygem-mercenary \
		rubygem-pygments.rb>=0.6.0:devel/rubygem-pygments.rb \
		rubygem-redcarpet>=3.1:textproc/rubygem-redcarpet \
		rubygem-safe_yaml>=1.0:devel/rubygem-safe_yaml \
		rubygem-toml>=0.1.0:devel/rubygem-toml

CONFLICTS_INSTALL=	rubygem-jekyll-3.*

PORTSCOUT=	limit:^2\.

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
