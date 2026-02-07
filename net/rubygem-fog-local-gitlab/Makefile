PORTNAME=	fog-local
PORTVERSION=	0.9.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support local filesystem storage
WWW=		https://github.com/fog/fog-local

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-fog-core-gitlab>=1.27<3.0:devel/rubygem-fog-core-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
