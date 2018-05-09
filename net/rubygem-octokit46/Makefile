# $FreeBSD$

PORTNAME=	octokit
PORTVERSION=	4.6.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	46

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple wrapper for the GitHub API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-sawyer>=0.8.0:www/rubygem-sawyer

PORTSCOUT=	limit:^4\.6\.

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
