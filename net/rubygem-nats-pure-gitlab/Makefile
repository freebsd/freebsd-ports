PORTNAME=	nats-pure
DISTVERSION=	2.5.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby client for NATS, the cloud native messaging system
WWW=		https://rubygems.org/gems/nats-pure

LICENSE=	APACHE20

USES=		gem

RUN_DEPENDS=	rubygem-base6402>=0.2.0<0.3:converters/rubygem-base6402 \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-json>=0:devel/rubygem-json \
		rubygem-securerandom>=0:security/rubygem-securerandom \
		rubygem-uri-gitlab>=0:net/rubygem-uri-gitlab

NO_ARCH=	yes

.include <bsd.port.mk>
