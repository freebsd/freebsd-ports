PORTNAME=	google-cloud-env
PORTVERSION=	2.2.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Provides information on Google Cloud Platform hosting environment
WWW=		https://github.com/googleapis/ruby-cloud-env

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-faraday>=1.0<3.0:www/rubygem-faraday

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
