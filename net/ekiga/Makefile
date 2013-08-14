# Created by: roger@FreeBSD.org
# $FreeBSD$

PORTNAME=	ekiga
PORTVERSION=	2.0.11
PORTREVISION=	13
CATEGORIES=	net gnome
MASTER_SITES=	GNOME

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	VoIP phone for GNOME

LIB_DEPENDS=	opal_r:${PORTSDIR}/net/opal

OPTIONS_DEFINE=	AVAHI DBUS
OPTIONS_DEFAULT=	AVAHI DBUS

CONFLICTS=	ekiga-3.*

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		gettext
USE_SDL=	sdl
INSTALLS_OMF=	yes
USE_GNOME=	libgnomeui gnomeprefix gnomehack gnomedocutils \
		evolutiondataserver intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ARGS=	--with-pwlib-dir=${LOCALBASE} \
		--with-opal-dir=${LOCALBASE}

GCONF_SCHEMAS=	ekiga.schemas
MAN1=		ekiga.1

pre-configure:
	${REINPLACE_CMD} -e "s,PWLIB_REC_VERSION=.*,PWLIB_REC_VERSION=`ptlib-config \
			--version`," \
		-e "s,OPAL_REC_VERSION=.*,OPAL_REC_VERSION=`${AWK} \
			'/define OPAL_VERSION/ \
			{printf $$NF}' ${LOCALBASE}/include/opal/opal/buildopts.h`," \
		${WRKSRC}/configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-core:${PORTSDIR}/net/avahi-app
CONFIGURE_ARGS+=--enable-avahi
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	DBUS:=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	DBUS:="@comment "
.endif

.include <bsd.port.mk>
