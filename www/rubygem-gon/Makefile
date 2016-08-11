# $FreeBSD$

PORTNAME=	gon
PORTVERSION=	6.0.1
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework to pass data to JS easily

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=3.0:www/rubygem-actionpack4 \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-request_store>=1.0:devel/rubygem-request_store

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
