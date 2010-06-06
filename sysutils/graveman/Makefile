# New ports collection makefile for:	graveman
# Date created:		2005-02-01
# Whom:			Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	graveman
PORTVERSION=	0.3.12.5
PORTREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES=	http://graveman.tuxfamily.org/sources/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(.)$/-\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another GTK2 frontend for cdrecord, mkisofs, readcd and sox

LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_CDRTOOLS=	yes
USE_GNOME=	libglade2 intlhack gnomehack gnomeprefix
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		graveman.1

OPTIONS=	MP3 "MP3 Support" off \
		OGG "OGG Support" off \
		DVD "DVD+RW Support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.0:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=--disable-mp3
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.7:${PORTSDIR}/audio/libogg \
		vorbis.4:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

.if defined(WITH_DVD)
RUN_DEPENDS+=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools
.endif

.include <bsd.port.post.mk>
