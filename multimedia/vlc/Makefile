# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.2.92
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/${PORTVERSION}/ \
		ftp://ftp.Awfulhak.org/pub/vlc/ \
		http://people.FreeBSD.org/~brian/vlc/

MAINTAINER=	brian@FreeBSD.org

LIB_DEPENDS=	dvdcss.2:${PORTSDIR}/graphics/libdvdcss


GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		INCLUDE="-I${LOCALBASE}/include" \
		LIB="-L${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib"

CONFIGURE_ARGS+=--with-dvdcss=${LOCALBASE}

USE_GTK=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

post-patch:
	${PERL} -pi.orig -e 's,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure
	find ${WRKSRC}/ -name \*.[ch] | xargs ${PERL} -pi.orig \
	    -e 's,"videolan/dvdcss.h","dvdcss/dvdcss.h",; \
		s,<videolan/dvdcss.h>,<dvdcss/dvdcss.h>,'

.include <bsd.port.mk>
