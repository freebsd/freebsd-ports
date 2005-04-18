# New ports collection makefile for:	graveman
# Date created:		2005-02-01
# Whom:			Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	graveman
PORTVERSION=	0.3.7
CATEGORIES=	sysutils
MASTER_SITES=	http://www.nongnu.org/${PORTNAME}/

MAINTAINER=	toxa@toxahost.ru
COMMENT=	Another GTK2 frontend for cdrecord, mkisofs, readcd and sox

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrtools

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	libglade2 intlhack gnomehack gnomeprefix
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	MP3 "MP3 Support" off \
		OGG "OGG Support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MP3)
LIB_DEPENDS+=	mad.2:${PORTSDIR}/audio/libmad \
		id3tag.2:${PORTSDIR}/audio/libid3tag
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.else
CONFIGURE_ARGS+=--disable-mp3
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.5:${PORTSDIR}/audio/libogg \
		vorbis.3:${PORTSDIR}/audio/libvorbis
.else
CONFIGURE_ARGS+=--disable-ogg
.endif

.include <bsd.port.post.mk>
