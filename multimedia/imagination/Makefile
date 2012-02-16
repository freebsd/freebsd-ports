# New ports collection makefile for:	imagination
# Date created:				April 22, 2011
# Whom:					Jesse <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	imagination
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A DVD slideshow maker

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		${LOCALBASE}/bin/sox:${PORTSDIR}/audio/sox \
		${LOCALBASE}/bin/intltool-extract:${PORTSDIR}/textproc/intltool
RUN_DEPENDS=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
