PORTNAME=	jekyll-redirect-from
PORTVERSION=	0.16.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handles redirection URLs for Jekyll pages and posts
WWW=		https://github.com/jekyll/jekyll-redirect-from

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jekyll>=3.3<5.0:www/rubygem-jekyll

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	script/*

.include <bsd.port.mk>
