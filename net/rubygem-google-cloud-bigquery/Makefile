# $FreeBSD$

PORTNAME=	google-cloud-bigquery
PORTVERSION=	1.17.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Official Ruby library for Google BigQuery

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-google-api-client>=0.33<1:devel/rubygem-google-api-client \
		rubygem-google-cloud-core>=1.2<2:net/rubygem-google-cloud-core \
		rubygem-googleauth>=0.9<1:security/rubygem-googleauth \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
