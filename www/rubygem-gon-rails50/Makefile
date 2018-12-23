# $FreeBSD$

PORTNAME=	gon
PORTVERSION=	6.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Framework to pass data to JS easily

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack50>=3.0:www/rubygem-actionpack50 \
		rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-request_store>=1.0:devel/rubygem-request_store

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
