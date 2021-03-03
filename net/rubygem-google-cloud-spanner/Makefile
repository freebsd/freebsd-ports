# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-spanner
PORTVERSION=	2.4.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Spanner API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-spanner-admin-database-v1>=0.1<1:net/rubygem-google-cloud-spanner-admin-database-v1 \
		rubygem-google-cloud-spanner-admin-instance-v1>=0.1<1:net/rubygem-google-cloud-spanner-admin-instance-v1 \
		rubygem-google-cloud-spanner-v1>=0.2<1:net/rubygem-google-cloud-spanner-v1

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
