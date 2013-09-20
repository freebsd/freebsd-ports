# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	graveman
PORTVERSION=	0.3.12.5
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://graveman.tuxfamily.org/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GTK2 frontend for cdrecord, mkisofs, readcd, and sox

LIB_DEPENDS=	mng:${PORTSDIR}/graphics/libmng
BUILD_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig gettext
USE_GNOME=	libglade2 intlhack gnomeprefix
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		graveman.1

OPTIONS_DEFINE=	MP3 OGG DVD
DVD_DESC=	DVD+RW support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	mad:${PORTSDIR}/audio/libmad \
		id3tag:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=--disable-mp3
.endif

.if ${PORT_OPTIONS:MOGG}
LIB_DEPENDS+=	ogg:${PORTSDIR}/audio/libogg \
		vorbis:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

.if ${PORT_OPTIONS:MDVD}
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.include <bsd.port.mk>
