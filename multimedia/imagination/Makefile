# Created by: Jesse <jessefrgsmith@yahoo.ca>
# $FreeBSD$

PORTNAME=	imagination
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	DVD slideshow maker

BUILD_DEPENDS=	${LOCALBASE}/lib/gtk-2.0:${PORTSDIR}/x11-toolkits/gtk20 \
		${LOCALBASE}/bin/sox:${PORTSDIR}/audio/sox \
		${LOCALBASE}/bin/intltool-extract:${PORTSDIR}/textproc/intltool
RUN_DEPENDS=	${LOCALBASE}/bin/ffmpeg:${PORTSDIR}/multimedia/ffmpeg

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
