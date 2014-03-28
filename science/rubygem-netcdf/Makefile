# Created by: Shin-ya Murakami <murashin@gfd-dennou.org>
# $FreeBSD$

PORTNAME=	netcdf
PORTVERSION=	0.6.6.1
CATEGORIES=	science rubygems
MASTER_SITES=	RG
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby interface to the NetCDF scientific IO library

BUILD_DEPENDS=	rubygem-narray>=0:${PORTSDIR}/math/rubygem-narray
LIB_DEPENDS=	libnetcdf.so:${PORTSDIR}/science/netcdf
RUN_DEPENDS=	rubygem-narray>=0:${PORTSDIR}/math/rubygem-narray

USE_RUBY=	yes
USE_RAKE=	yes
USE_RUBYGEMS=	yes
GEM_NAME=	${DISTNAME}
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
