# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/multimedia/libquvi-scripts/Makefile 19571 2014-04-25 18:12:46Z kwm $

PORTNAME=	libquvi-scripts
PORTVERSION=	0.9
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION}/${PORTNAME}/ \
		GOOGLE_CODE
DISTFILES=	${PORTNAME}-${PORTVERSION}.20131130.tar.xz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}.20131130

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	AGPLv3

PORTSCOUT=	limit:0.4.[0-9]*

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

USES=		pathfix tar:xz
GNU_CONFIGURE=	yes

QUVI_VER=	0.9.20131130

PLIST_SUB+=	VERSION=${QUVI_VER}

PROJECTHOST=	quvi

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
