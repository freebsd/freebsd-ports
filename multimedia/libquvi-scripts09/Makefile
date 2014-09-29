# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi-scripts
PORTVERSION=	0.9
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION}/${PORTNAME}/ \
		GOOGLE_CODE
PKGNAMESUFFIX=	09
DISTNAME=	${PORTNAME}-${PORTVERSION}.${QUVI_VER}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	AGPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.${QUVI_VER}

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

USES=		lua:run pathfix tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=09

QUVI_VER=	20131130

PLIST_SUB+=	VERSION="0.9.${QUVI_VER}"

PROJECTHOST=	quvi

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
