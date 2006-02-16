# New ports collection makefile for:	bmpx
# Date created:				2005-11-20
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bmpx
PORTVERSION=	0.13
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	beepmp

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Audio player

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		xine.15:${PORTSDIR}/multimedia/libxine \
		neon.25:${PORTSDIR}/www/neon

USE_AUTOTOOLS=	libtool:15
USE_BISON=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GCC=	3.4+
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2 desktopfileutils
LIBTOOLFILES=	configure libhrel/configure \
		libchroma/configure libskinned/configure
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-xine --disable-gst
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		bmpx.1

.if !defined(WITHOUT_AMAZON)
CONFIGURE_ARGS+=	--enable-amazon
.endif

.if defined(WITHOUT_DBUS)
CONFIGURE_ARGS+=	--disable-dbus
.else
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
.endif

.if !defined(WITHOUT_GCONF)
USE_GNOME+=	gconf2
CONFIGURE_ARGS+=	--enable-gconf
.endif

.if defined(WITHOUT_PERL)
CONFIGURE_ARGS+=	--disable-perl
.else
USE_PERL5_BUILD=	yes
.endif

.if defined(WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=	PYTHON="@comment "
.else
USE_PYTHON=	yes
USE_GNOME+=	pygtk2
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/dbus.pth:${PORTSDIR}/devel/py-dbus
PLIST_SUB+=	PYTHON=""
.endif

.if defined(WITHOUT_STARTUP_NOTIFICATION)
CONFIGURE_ARGS+=	--disable-sn
.else
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/src/metadata.c
.endif

.include <bsd.port.post.mk>
