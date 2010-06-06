# New ports collection makefile for:	bmp-extra-plugins
# Date created:			Tue Sep 21 17:09:43 CEST 2004
# Whom:				Jan Srzednicki <w@wrzask.pl>
#
# $FreeBSD$
#

PORTNAME=	bmp-extra-plugins
PORTVERSION=	0.2.2
PORTREVISION=	12
CATEGORIES=	multimedia audio
MASTER_SITES=	http://wrzask.pl/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A collection of additional plugins for beep media player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		artsc.0:${PORTSDIR}/audio/arts

USE_GNOME=	libglade2 esound
USE_GETTEXT=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-ogg=${LOCALBASE} \
		--with-vorbis=${LOCALBASE}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's,-pthread,${PTHREAD_LIBS},g ; \
		s,echo aout,echo elf,' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '38,40s,^static ,,' \
		${WRKSRC}/output/crossfade/monitor.c
	@${REINPLACE_CMD} -e '97s,^static ,,' \
		${WRKSRC}/output/crossfade/oss.c

.include <bsd.port.mk>
