# $FreeBSD$

PORTNAME=	html-pipeline
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub HTML processing filters and utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=2:devel/rubygem-activesupport52 \
		rubygem-nokogiri>=1.4:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
