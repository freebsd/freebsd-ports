# New ports collection makefile for:	xmps
# Date created:				15 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmps
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	multimedia gnome
# per distfile survey, site disappeared in June 2003
MASTER_SITES=	# http://xmps.sourceforge.net/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X MPEG Player System - a media player with a very nice GUI

USE_SDL=	sdl
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'

post-configure:
	@${REINPLACE_CMD} -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

.include <bsd.port.post.mk>
