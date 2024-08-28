PORTNAME=	rgeo-proj4
PORTVERSION=	4.0.0
PORTREVISION=	4
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Proj.4 extension for RGeo
WWW=		https://github.com/rgeo/rgeo-proj4

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	rubygem-rgeo>=3.0.0<3.1:science/rubygem-rgeo

USES=		gem

CONFIGURE_ARGS=	--with-proj-dir=${LOCALBASE}

.include <bsd.port.mk>
