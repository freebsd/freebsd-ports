PORTNAME=	octokit
PORTVERSION=	8.1.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	8

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple wrapper for the GitHub API
WWW=		https://octokit.github.io/octokit.rb/ \
		https://github.com/octokit/octokit.rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-faraday>=1<3:www/rubygem-faraday \
		rubygem-sawyer>=0.9<1:www/rubygem-sawyer

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^8\.

.include <bsd.port.mk>
