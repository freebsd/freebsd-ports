# Created by: Michael Johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	gmencoder
PORTVERSION=	0.1.0
PORTREVISION=	17
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome2 front-end to mplayer/mencoder

BUILD_DEPENDS=	mencoder:multimedia/mencoder
RUN_DEPENDS=	mencoder:multimedia/mencoder

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USE_GNOME=	gnomeprefix libgnomeui
USES=		pathfix gmake pkgconfig

DESKTOP_ENTRIES="Gmencoder" "Gnome2 front-end to mplayer/mencoder" \
		"" "gmencoder" "GNOME;AudioVideo;" false

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_DVD_DEVICE)
DEFAULT_DVD_DEVICE=${WITH_DVD_DEVICE}
.else
DEFAULT_DVD_DEVICE=/dev/acd0
.endif

pre-everything::
.if !defined(WITH_DVD_DEVICE)
	@${ECHO_MSG} "===> The default DVD device is ${DEFAULT_DVD_DEVICE}"
	@${ECHO_MSG} "===> Define WITH_DVD_DEVICE if you want to change the default"
	@${ECHO_MSG} "===> For example, 'make WITH_DVD_DEVICE=\"/dev/somedevice\"'"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O4||; s|type -path|which|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/dev/dvd|${DEFAULT_DVD_DEVICE}|' \
		${WRKSRC}/src/main.c ${WRKSRC}/src/interface.c
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^ALL_LINGUAS/d' ${WRKSRC}/configure
.endif

post-install:
	${INSTALL_MAN}	${WRKSRC}/man/gmencoder.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>
