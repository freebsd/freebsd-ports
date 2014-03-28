# Created by: Jesse <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	imagination
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	DVD slideshow maker

LIB_DEPENDS=	libsox.so:${PORTSDIR}/audio/sox \
	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig pathfix
USE_GNOME=	gtk20 intltool intlhack libxslt
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

.include <bsd.port.mk>
