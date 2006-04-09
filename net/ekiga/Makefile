# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ekiga
PORTVERSION=	2.0.1
PORTREVISION=	2
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0

MAINTAINER=	jbq@caraldi.com
COMMENT=	VoIP phone for GNOME

LIB_DEPENDS=	opal_r.2:${PORTSDIR}/net/opal

USE_BZIP2=	yes
USE_X_PREFIX=	yes
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

GCONF_SCHEMAS=	ekiga.schemas
MAN1=		ekiga.1

.include <bsd.port.pre.mk>

.ifndef (WITHOUT_AVAHI)
LIB_DEPENDS+=	avahi-core.4:${PORTSDIR}/net/avahi
CONFIGURE_ARGS+=--enable-avahi
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.ifndef (WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-1.2:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|{datadir}/dbus-1|(prefix)/share/dbus-1|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
