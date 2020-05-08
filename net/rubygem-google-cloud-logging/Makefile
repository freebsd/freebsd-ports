# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-logging
PORTVERSION=	1.10.5
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Stackdriver Logging

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.1<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.2<2:net/rubygem-google-cloud-core \
		rubygem-google-gax>=1.8<2:devel/rubygem-google-gax \
		rubygem-googleapis-common-protos>=1.3.9<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.0.4<2.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-stackdriver-core>=1.3<2:net/rubygem-stackdriver-core

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
