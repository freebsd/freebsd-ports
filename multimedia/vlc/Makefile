# New ports collection makefile for:	vlc
# Date created:		3rd August 2001
# Whom:			Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

PORTNAME=	vlc
PORTVERSION=	0.2.90
CATEGORIES=	graphics
MASTER_SITES=	http://www.videolan.org/pub/videolan/vlc/${PORTVERSION}/ \
		ftp://ftp.Awfulhak.org/pub/vlc/ \
		http://people.FreeBSD.org/~brian/vlc/

MAINTAINER=	brian@Awfulhak.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PATH_GTKCONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		INCLUDE="-I${LOCALBASE}/include" \
		LIB="-L${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GTK=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes

post-patch:
	${PERL} -pi.orig -e 's,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
PLIST_SUB=	XF4=""
.else
PLIST_SUB=	XF4="@comment "
.endif

.include <bsd.port.post.mk>
