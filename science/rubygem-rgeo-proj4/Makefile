# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	rgeo-proj4
PORTVERSION=	3.0.1
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Proj.4 extension for RGeo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	rubygem-rgeo>=2.0<3:science/rubygem-rgeo

USES=		gem
USE_RUBY=	yes

CONFIGURE_ARGS=	--with-proj-dir=${LOCALBASE}

.include <bsd.port.mk>
