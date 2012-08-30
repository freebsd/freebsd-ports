# New ports collection makefile for:	graveman
# Date created:		2005-02-01
# Whom:			Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	graveman
PORTVERSION=	0.3.12.5
PORTREVISION=	10
CATEGORIES=	sysutils
MASTER_SITES=	http://graveman.tuxfamily.org/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GTK2 frontend for cdrecord, mkisofs, readcd, and sox

LIB_DEPENDS=	mng:${PORTSDIR}/graphics/libmng

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_CDRTOOLS=	yes
USE_PKGCONFIG=	build
USE_GNOME=	libglade2 intlhack gnomehack gnomeprefix
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

MAN1=		graveman.1

OPTIONS_DEFINE=	MP3 OGG DVD
DVD_DESC=	DVD+RW support

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
