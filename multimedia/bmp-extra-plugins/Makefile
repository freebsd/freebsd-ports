# New ports collection makefile for:	bmp-extra-plugins
# Date created:			Tue Sep 21 17:09:43 CEST 2004
# Whom:				Jan Srzednicki <w@wrzask.pl>
#
# $FreeBSD$
#

PORTNAME=	bmp-extra-plugins
PORTVERSION=	0.2.2
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://www.t17.ikarnet.pl/~wiget/bmp-extra-plugins/download/

MAINTAINER=	w@wrzask.pl
COMMENT=	A collection of additional plugins for beep media player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		artsc.0:${PORTSDIR}/audio/arts

USE_GNOME=	libglade2 esound
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15

CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} \
		--with-vorbis=${LOCALBASE}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
