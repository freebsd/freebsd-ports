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

LIB_DEPENDS=	libmng.so:${PORTSDIR}/graphics/libmng
BUILD_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig gettext gmake
USE_GNOME=	libglade2 intlhack gnomeprefix
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	MP3 OGG DVD
DVD_DESC=	DVD+RW support
MP3_LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad \
			libid3tag.so:${PORTSDIR}/audio/libid3tag
MP3_RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
MP3_CONFIGURE_OFF=	--disable-mp3
OGG_LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
			libvorbis.so:${PORTSDIR}/audio/libvorbis
OGG_CONFIGURE_OFF=	--disable-ogg
DVD_RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

.include <bsd.port.mk>
