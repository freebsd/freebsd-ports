PORTNAME=	google-cloud-core
PORTVERSION=	1.6.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Internal shared library for Google Cloud Client Library
WWW=		https://github.com/googleapis/google-cloud-ruby/tree/master/google-cloud-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-google-cloud-env>=1.0<2:net/rubygem-google-cloud-env \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
