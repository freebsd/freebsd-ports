PORTNAME=	octokit
PORTVERSION=	9.2.0
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple wrapper for the GitHub API
WWW=		https://octokit.github.io/octokit.rb/ \
		https://github.com/octokit/octokit.rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-gitlab>=1<3:www/rubygem-faraday-gitlab \
		rubygem-sawyer-gitlab>=0.9<1:www/rubygem-sawyer-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
