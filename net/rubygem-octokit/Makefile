PORTNAME=	octokit
PORTVERSION=	5.6.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Simple wrapper for the GitHub API
WWW=		https://github.com/octokit/octokit.rb

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday1>=1<3:www/rubygem-faraday1 \
		rubygem-sawyer>=0.9<1:www/rubygem-sawyer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
