# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libquvi-scripts/Makefile 19684 2014-05-24 09:25:55Z gusi $

PORTNAME=	libquvi-scripts
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	AGPLv3

PORTSCOUT=	limit:0.4.[0-9]*

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

USES=		lua:run pathfix tar:xz
GNU_CONFIGURE=	yes

QUVI_VER=	0.9.20131130

PLIST_SUB+=	VERSION=${QUVI_VER}

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
