# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ndpi
PORTVERSION=	1.4.0
CATEGORIES=	net
MASTER_SITES=	SF/ntop/nDPI
DISTNAME=	nDPI-${PORTVERSION}_r7023

MAINTAINER=	5u623l20@gmail.com
COMMENT=	ntop-maintained superset of the popular OpenDPI library

LICENSE=	GPLv3

CONFIGURE_ARGS=	--with-pic
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	 	pathfix pkgconfig

PLIST_SUB=	MAJOR_VER=${PORTVERSION:R}

.include <bsd.port.mk>
