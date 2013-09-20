# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi-scripts
PORTVERSION=	0.4.18
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Embedded lua scripts for libquvi and utility scripts

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

OPTIONS_DEFINE=	NSFW
NSFW_DESC=	Enable adult website support

GNU_CONFIGURE=	yes
USE_XZ=		yes
USES=		pathfix

MAN7=		libquvi-scripts.7

PROJECTHOST=	quvi

PORTSCOUT=	limit:0.4.[0-9]*

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNSFW}
CONFIGURE_ARGS+=--with-nsfw
PLIST_SUB+=	NSFW=""
.else
PLIST_SUB+=	NSFW="@comment "
.endif

.include <bsd.port.mk>
