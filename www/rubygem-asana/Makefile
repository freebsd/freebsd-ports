# $FreeBSD$

PORTNAME=	asana
PORTVERSION=	0.5.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby wrapper for the Asana REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=0.9:${PORTSDIR}/www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-faraday_middleware-multi_json>=0.0:${PORTSDIR}/devel/rubygem-faraday_middleware-multi_json \
		rubygem-oauth2>1.0:${PORTSDIR}/net/rubygem-oauth2

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
