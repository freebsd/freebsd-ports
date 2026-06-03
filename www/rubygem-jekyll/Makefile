PORTNAME=	jekyll
PORTVERSION=	4.4.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator
WWW=		https://jekyllrb.com/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-colorator>=1.0<2:textproc/rubygem-colorator \
		rubygem-csv>=3.0<4:devel/rubygem-csv \
		rubygem-em-websocket>=0.5<1:www/rubygem-em-websocket \
		rubygem-i18n>=1.0,2<2,2:devel/rubygem-i18n \
		rubygem-jekyll-sass-converter>=2.0<4.0:textproc/rubygem-jekyll-sass-converter \
		rubygem-jekyll-watch>=2.0<3:www/rubygem-jekyll-watch \
		rubygem-json>=2.6<3:devel/rubygem-json \
		rubygem-kramdown>=2.3.1<3:textproc/rubygem-kramdown \
		rubygem-kramdown-parser-gfm>=1.0<2:textproc/rubygem-kramdown-parser-gfm \
		rubygem-liquid4>=4.0<5:textproc/rubygem-liquid4 \
		rubygem-mercenary>=0.3.6<1:devel/rubygem-mercenary \
		rubygem-pathutil>=0.9<1:devel/rubygem-pathutil \
		rubygem-rouge>=3.0<5.0:textproc/rubygem-rouge \
		rubygem-safe_yaml>=1.0<2:devel/rubygem-safe_yaml \
		rubygem-terminal-table3>=1.8<4.0:textproc/rubygem-terminal-table3 \
		rubygem-webrick>=1.7<2:www/rubygem-webrick

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/jekyll

CONFLICTS_INSTALL=	rubygem-jekyll3

CPE_VENDOR=	jekyllrb

.include <bsd.port.mk>
