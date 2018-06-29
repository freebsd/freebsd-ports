# $FreeBSD$

PORTNAME=	html-pipeline
PORTVERSION=	2.7.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	GitHub HTML processing filters and utilities used by GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=2:devel/rubygem-activesupport4 \
		rubygem-nokogiri>=1.4:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.7\.1

.include <bsd.port.mk>
