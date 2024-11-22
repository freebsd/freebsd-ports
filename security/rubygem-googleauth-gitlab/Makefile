PORTNAME=	googleauth
PORTVERSION=	1.11.2
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Google Auth Library for Ruby
WWW=		https://github.com/googleapis/google-auth-library-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-faraday-gitlab>=1.0<3.0:www/rubygem-faraday-gitlab \
		rubygem-google-cloud-env-gitlab>=2.1<3:net/rubygem-google-cloud-env-gitlab \
		rubygem-jwt>=1.4<3.0:www/rubygem-jwt \
		rubygem-multi_json>=1.11<2:devel/rubygem-multi_json \
		rubygem-os>=0.9<2.0:devel/rubygem-os \
		rubygem-signet-gitlab>=0.16<2:security/rubygem-signet-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
