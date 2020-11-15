# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-bigtable
PORTVERSION=	2.2.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Cloud Bigtable API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-cloud-bigtable-admin-v2>=0.0<1:net/rubygem-google-cloud-bigtable-admin-v2 \
		rubygem-google-cloud-bigtable-v2>=0.0<1:net/rubygem-google-cloud-bigtable-v2 \
		rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
