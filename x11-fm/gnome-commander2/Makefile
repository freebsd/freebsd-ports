# New ports collection makefile for:	gnomem-commander
# Date created:		23 April 2002
# Whom:			Edgardo Garcia Hoeffler <edybsd@yahoo.com.ar>
#
# $FreeBSD$
#

PORTNAME=	gnome-commander
PORTVERSION=	1.2.8
PORTEPOCH=	1
CATEGORIES=	x11-fm gnome
MASTER_SITES=	GNOME
MASTER_SITE_SUBDIR=	sources/gnome-commander/1.2
PKGNAMESUFFIX=	2
DIST_SUBDIR=	gnome2

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	File manager for Gnome2

LIB_DEPENDS=	id3-3.8.3:${PORTSDIR}/audio/id3lib \
		exif.12:${PORTSDIR}/graphics/libexif \
		iptcdata.3:${PORTSDIR}/graphics/libiptcdata

CONFLICTS=	gnome-commander-[0-9]*

USE_BZIP2=	yes
USE_GNOME=	gnomedocutils gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15 autoconf:262:env aclocal:19:env automake:19:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

MAN1=		gnome-commander.1

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTORECONF} -W none

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
