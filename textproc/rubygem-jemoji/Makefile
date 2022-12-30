PORTNAME=	jemoji
PORTVERSION=	0.13.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GitHub-flavored emoji plugin for Jekyll
WWW=		https://github.com/jekyll/jemoji

LICENSE=	MIT

RUN_DEPENDS=	rubygem-gemoji>=3<5:textproc/rubygem-gemoji \
		rubygem-html-pipeline>=2.2<3:textproc/rubygem-html-pipeline \
		rubygem-jekyll>=3.0<5.0:www/rubygem-jekyll

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
