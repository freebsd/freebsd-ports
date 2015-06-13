# $FreeBSD$

PORTNAME=	gon
PORTVERSION=	5.2.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework to pass data to JS easily

LICENSE=	MIT

RUN_DEPENDS=	rubygem-actionpack4>=4.1.6:${PORTSDIR}/www/rubygem-actionpack4 \
		rubygem-json>=0:${PORTSDIR}/devel/rubygem-json \
		rubygem-multi_json>=0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-request_store>=1.0.5:${PORTSDIR}/devel/rubygem-request_store

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
