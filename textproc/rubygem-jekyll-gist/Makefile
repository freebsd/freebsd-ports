PORTNAME=	jekyll-gist
PORTVERSION=	1.5.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Liquid tag for displaying GitHub Gists in Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-octokit>=4.2<5:net/rubygem-octokit

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	script/*

.include <bsd.port.mk>
