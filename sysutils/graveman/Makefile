# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	graveman
DISTVERSION=	0.3.12-5
PORTREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	http://graveman.tuxfamily.org/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GTK2 frontend for cdrecord, mkisofs, readcd, and sox

LIB_DEPENDS=	libmng.so:graphics/libmng
BUILD_DEPENDS=	cdrecord:sysutils/cdrtools
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig gettext gmake tar:bzip2
USE_GNOME=	libglade2 intlhack gnomeprefix
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MP3 OGG DVD
DVD_DESC=	DVD+RW support
MP3_LIB_DEPENDS=	libmad.so:audio/libmad \
			libid3tag.so:audio/libid3tag
MP3_RUN_DEPENDS=	sox:audio/sox
MP3_CONFIGURE_OFF=	--disable-mp3
OGG_LIB_DEPENDS=	libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis
OGG_CONFIGURE_OFF=	--disable-ogg
DVD_RUN_DEPENDS=	growisofs:sysutils/dvd+rw-tools

.include <bsd.port.mk>
