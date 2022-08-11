PORTNAME=	jekyll
PORTVERSION=	3.9.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple, blog aware, static site generator

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4<3:www/rubygem-addressable \
		rubygem-colorator>=1.0<2:textproc/rubygem-colorator \
		rubygem-em-websocket>=0.5<1:www/rubygem-em-websocket \
		rubygem-i18n>=0.7,2:devel/rubygem-i18n \
		rubygem-jekyll-sass-converter1>=1.0<2:textproc/rubygem-jekyll-sass-converter1 \
		rubygem-jekyll-watch>=2.0<3:www/rubygem-jekyll-watch \
		rubygem-kramdown>=1.17<3:textproc/rubygem-kramdown \
		rubygem-liquid4>=4.0<5:textproc/rubygem-liquid4 \
		rubygem-mercenary>=0.3.3<1:devel/rubygem-mercenary \
		rubygem-pathutil>=0.9<1:devel/rubygem-pathutil \
		rubygem-rouge>=1.7<4:textproc/rubygem-rouge \
		rubygem-safe_yaml>=1.0<2:devel/rubygem-safe_yaml

USES=		cpe gem
USE_RUBY=	yes

CONFLICTS_INSTALL=	rubygem-jekyll

NO_ARCH=	yes

PLIST_FILES=	bin/jekyll

CPE_VENDOR=	jekyllrb

PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
