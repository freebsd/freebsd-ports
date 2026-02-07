PORTNAME=	omniauth
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	1

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generalized Rack framework for multiple-provider authentication
WWW=		https://github.com/omniauth/omniauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-hashie>=3.4.6:devel/rubygem-hashie \
		rubygem-rack22>=1.6.2,3<3,3:www/rubygem-rack22

USES=		cpe gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.

.include <bsd.port.mk>
