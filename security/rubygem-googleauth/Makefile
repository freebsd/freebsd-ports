PORTNAME=	googleauth
PORTVERSION=	1.15.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Google Auth Library for Ruby
WWW=		https://github.com/googleapis/google-auth-library-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday>=1.0<3.0:www/rubygem-faraday \
		rubygem-google-cloud-env>=2.2<3:net/rubygem-google-cloud-env \
		rubygem-google-logging-utils>=0.1<1:devel/rubygem-google-logging-utils \
		rubygem-jwt>=1.4<4.0:www/rubygem-jwt \
		rubygem-multi_json>=1.11<2:devel/rubygem-multi_json \
		rubygem-os>=0.9<2.0:devel/rubygem-os \
		rubygem-signet>=0.16<2:security/rubygem-signet

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
