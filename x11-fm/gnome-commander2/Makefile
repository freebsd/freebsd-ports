# Created by: Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
# $FreeBSD$

PORTNAME=	gnome-commander
PORTVERSION=	1.2.8.15
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-commander/1.2
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	File manager for Gnome2

BROKEN=		Fails to configure

LICENSE=	GPLv2

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		exif.12:${PORTSDIR}/graphics/libexif \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata

CONFLICTS=	gnome-commander-[0-9]*

USES=		tar:xz gmake
USE_GNOME=	gnomedocutils gnomehack gnomeprefix intlhack libgnomeui
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool autoconf:env aclocal:env automake:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALLS_OMF=	yes

MAN1=		gnome-commander.1

NO_STAGE=	yes
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -W none

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
