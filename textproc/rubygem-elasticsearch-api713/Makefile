PORTNAME=	elasticsearch-api
PORTVERSION=	7.13.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	713

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby API for Elasticsearch

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^7\.13\.

.include <bsd.port.mk>
