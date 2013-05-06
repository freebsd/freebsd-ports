# Created by: Meethune Bhowmick <meethune@gmail.com>
# $FreeBSD$

PORTNAME=	libnotify
PORTVERSION=	0.14
PORTREVISION=	11
CATEGORIES=	net-im
MASTER_SITES=	SF/gaim-${PORTNAME}/pidgin-${PORTNAME}/pidgin-${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	meethune@gmail.com
COMMENT=	This plugin adds a libnotify interface to Pidgin

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin \
    		${LOCALBASE}/libdata/pkgconfig/libnotify.pc:${PORTSDIR}/devel/libnotify
LIB_DEPENDS=	notify.4:${PORTSDIR}/devel/libnotify \
		purple.10:${PORTSDIR}/net-im/libpurple

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USES=		pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
