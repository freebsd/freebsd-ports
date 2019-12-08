# $FreeBSD$

PORTNAME=	jekyll-sitemap
PORTVERSION=	1.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically generate a sitemap.xml for Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-jekyll>=3.7<5.0:www/rubygem-jekyll

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	script/*

.include <bsd.port.mk>
