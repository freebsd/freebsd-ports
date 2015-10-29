# $FreeBSD$

PORTNAME=	html-pipeline
PORTVERSION=	2.2.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GitHub HTML processing filters and utilities

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport>=2:${PORTSDIR}/devel/rubygem-activesupport \
		rubygem-nokogiri>=1.4:${PORTSDIR}/textproc/rubygem-nokogiri

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
