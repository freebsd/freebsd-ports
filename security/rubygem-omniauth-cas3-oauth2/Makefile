PORTNAME=	omniauth-cas3
PORTVERSION=	1.1.4
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-oauth2

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	CAS 3.0 Strategy for OmniAuth
WWW=		https://github.com/tduehr/omniauth-cas3

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.3<3:www/rubygem-addressable \
		rubygem-nokogiri>=1.7.1<2:textproc/rubygem-nokogiri \
		rubygem-omniauth>=1.2<3:security/rubygem-omniauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
