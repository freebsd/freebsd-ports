# Created by: Marcin Simonides <marcin@studio4plus.com>
# $FreeBSD$

PORTNAME=	gnome-subtitles
PORTVERSION=	1.3
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	sperber@FreeBSD.org
COMMENT=	Subtitle editor with video preview

LICENSE=	GPLv2

LIB_DEPENDS=	libenchant.so:${PORTSDIR}/textproc/enchant \
		libgtkspell.so:${PORTSDIR}/textproc/gtkspell

USES=		cpe gmake mono pkgconfig libtool desktop-file-utils
CPE_VENDOR=	pedro_castro
USE_GNOME=	gnomeprefix gtksharp20 gnomesharp20 gnomedocutils
USE_GSTREAMER1=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GCONF_SCHEMAS=	gnome-subtitles.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=yes

USE_LDCONFIG=	${PREFIX}/lib/gnome-subtitles

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gnome-subtitles/libgstreamer_playbin.so

.include <bsd.port.mk>
