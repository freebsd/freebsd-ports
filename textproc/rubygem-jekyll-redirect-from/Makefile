# $FreeBSD$

PORTNAME=	jekyll-redirect-from
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Handles redirection URLs for jekyll pages and posts

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jekyll>=3.3:www/rubygem-jekyll

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem shebangfix
SHEBANG_FILES=	script/cibuild \
		script/bootstrap \
		script/release

.include <bsd.port.mk>
