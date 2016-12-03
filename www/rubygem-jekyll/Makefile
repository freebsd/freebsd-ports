# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	3.3.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4:www/rubygem-addressable \
		rubygem-colorator>=0.1:textproc/rubygem-colorator \
		rubygem-jekyll-sass-converter>=1.0:textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=1.1:www/rubygem-jekyll-watch \
		rubygem-kramdown>=1.3:textproc/rubygem-kramdown \
		rubygem-liquid>=3.0.0:textproc/rubygem-liquid \
		rubygem-mercenary>=0.3.3:devel/rubygem-mercenary \
		rubygem-pathutil>=0.9:devel/rubygem-pathutil \
		rubygem-rouge>=1.7:textproc/rubygem-rouge \
		rubygem-safe_yaml>=1.0:devel/rubygem-safe_yaml

CONFLICTS_INSTALL=	rubygem-jekyll2-*

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
