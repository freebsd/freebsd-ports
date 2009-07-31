# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ekiga
PORTVERSION=	2.0.11
PORTREVISION=	6
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	VoIP phone for GNOME

OPTIONS=	AVAHI	"Support Avahi for service discovery on LAN" on \
		DBUS	"Use D-BUS for interprocess communication" on

LIB_DEPENDS=	opal_r:${PORTSDIR}/net/opal

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
INSTALLS_OMF=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomehack gnomedocutils \
		evolutiondataserver intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}" \
		SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS=	--with-pwlib-dir=${LOCALBASE} \
		--with-opal-dir=${LOCALBASE}
ALL_TARGET=	-j`${SYSCTL} -n hw.ncpu`

GCONF_SCHEMAS=	ekiga.schemas
MAN1=		ekiga.1

pre-configure:
	${REINPLACE_CMD} -e "s,PWLIB_REC_VERSION=.*,PWLIB_REC_VERSION=`ptlib-config \
			--version`," \
		-e "s,OPAL_REC_VERSION=.*,OPAL_REC_VERSION=`${AWK} \
			'/define OPAL_VERSION/ \
			{printf $$NF}' ${LOCALBASE}/include/opal/opal/buildopts.h`," \
		${WRKSRC}/configure

.include <bsd.port.pre.mk>

.ifndef (WITHOUT_AVAHI)
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=--enable-avahi
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.ifndef (WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

.include <bsd.port.post.mk>
