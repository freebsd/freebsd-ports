# New ports collection makefile for:    avidemux
# Date created:         15 August 2002
# Whom:                 Anish Mistry
#                       with help from mean
# $FreeBSD$
#

PORTNAME=	avidemux
PORTVERSION=	0.9.0.16
CATEGORIES=	graphics
MASTER_SITES=	http://fixounet.free.fr/avidemux/
DISTNAME=	avidemux-0.9pre16_gtkfix
EXTRACT_SUFX=	.tgz

MAINTAINER=	amistry@am-productions.biz

LIB_DEPENDS=	xvidcore.0:${PORTSDIR}/graphics/xvid \
		mp3lame.0:${PORTSDIR}/audio/lame \
		mad.1:${PORTSDIR}/audio/mad
BUILD_DEPENDS=	\
	${LINUXBASE}/usr/include/divx/decore.h:${PORTSDIR}/graphics/divx4linux \
	${X11BASE}/include/X11/extensions/Xvlib.h:${PORTSDIR}/graphics/xv

WRKSRC=		${WRKDIR}/avidemux-0.9pre16
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
		-I${LINUXBASE}/usr/include/divx" \
		LIBFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-xvid-as-decoder --disable-warnings
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
