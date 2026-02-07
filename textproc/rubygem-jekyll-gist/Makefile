PORTNAME=	jekyll-gist
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites
WWW=		https://github.com/jekyll/jekyll-gist

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-octokit4>=4.2<5:net/rubygem-octokit4

USES=		gem shebangfix

NO_ARCH=	yes

SHEBANG_FILES=	script/*

.include <bsd.port.mk>
