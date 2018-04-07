# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rgeo-proj4
PORTVERSION=	1.0.0
CATEGORIES=	science rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Proj.4 extension for RGeo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libproj.so:graphics/proj
RUN_DEPENDS=	rubygem-rgeo>=1.0:science/rubygem-rgeo

CONFIGURE_ARGS=	--with-proj-dir=${LOCALBASE}
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
