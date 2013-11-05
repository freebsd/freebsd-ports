# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi-scripts
PORTVERSION=	0.4.20
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

PORTSCOUT=	limit:0.4.[0-9]*

OPTIONS_DEFINE=	NSFW
OPTIONS_SUB=	yes
NSFW_DESC=	Enable adult website support

GNU_CONFIGURE=	yes
USE_XZ=		yes
USES=		pathfix

PROJECTHOST=	quvi

NSFW_CONFIGURE_WITH=	nsfw

.include <bsd.port.mk>
