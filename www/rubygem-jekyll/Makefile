# Created by: Peter Schuller <peter.schuller@infidyne.com>
# $FreeBSD$

PORTNAME=	jekyll
PORTVERSION=	4.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-colorator>=1.0<2:textproc/rubygem-colorator \
		rubygem-em-websocket>=0.5<1:www/rubygem-em-websocket \
		rubygem-i18n>=0.9.5,2<2,2:devel/rubygem-i18n \
		rubygem-jekyll-sass-converter>=2.0<3:textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=2.0<3:www/rubygem-jekyll-watch \
		rubygem-kramdown>=2.1<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.0<2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-liquid>=4.0<5:textproc/rubygem-liquid \
		rubygem-mercenary>=0.3.3<1:devel/rubygem-mercenary \
		rubygem-pathutil>=0.9<1:devel/rubygem-pathutil \
		rubygem-rouge>=3.0<4:textproc/rubygem-rouge \
		rubygem-safe_yaml>=1.0<2:devel/rubygem-safe_yaml \
		rubygem-terminal-table>=1.8<2:textproc/rubygem-terminal-table

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/jekyll

.include <bsd.port.mk>
