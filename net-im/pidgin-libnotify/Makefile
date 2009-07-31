# Ports collection Makefile for:	pidgin-libnotify
# Date created:				2007-07-10
# Whom:					Meethune Bhowmick <meethune@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libnotify
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	gaim-libnotify
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	meethune@gmail.com
COMMENT=	This plugin adds a libnotify interface to Pidgin

BUILD_DEPENDS=	${LOCALBASE}/bin/pidgin:${PORTSDIR}/net-im/pidgin \
    		${LOCALBASE}/libdata/pkgconfig/libnotify.pc:${PORTSDIR}/devel/libnotify
LIB_DEPENDS=	notify.1:${PORTSDIR}/devel/libnotify \
		purple.5:${PORTSDIR}/net-im/libpurple

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig gtk20

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

CONFIGURE_ARGS=	--disable-static

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
