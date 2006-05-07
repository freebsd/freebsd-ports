# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.14.4
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	beepmp

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Media player geared towards usability, technical efficiency and looks

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		cairo.2:${PORTSDIR}/graphics/cairo \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz \
		neon.25:${PORTSDIR}/www/neon

USE_BISON=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
LIBTOOLFILES=	configure libhrel/configure \
		libchroma/configure libskinned/configure
USE_GSTREAMER=	bad good ugly mad ogg
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pkgconfig-dir=${PREFIX}/libdata/pkgconfig
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		beep-media-player-2.1

.if !defined(WITHOUT_AMAZON)
CONFIGURE_ARGS+=	--enable-amazon
.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-dbus
PLIST_SUB+=	DBUS="@comment "
.else
CONFIGURE_ARGS+=	--with-dbus-services-dir="${PREFIX}/share/dbus-1/services"
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
PLIST_SUB+=	DBUS=""
.endif

.if defined(WITH_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--enable-gconf
GCONF_SCHEMAS=	bmp-2.0.schema
.endif

.if defined(WITHOUT_PERL)
CONFIGURE_ARGS+=	--disable-perl
.else
USE_PERL5_BUILD=	yes
.endif

.if defined(WITHOUT_STARTUP_NOTIFICATION)
CONFIGURE_ARGS+=	--disable-sn
.else
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/src/metadata.c
.endif

.include <bsd.port.post.mk>
