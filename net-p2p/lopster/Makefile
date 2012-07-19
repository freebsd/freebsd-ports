# New ports collection makefile for:	lopster
# Date created:		19 Oct 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	lopster
PORTVERSION=	1.2.2
PORTREVISION=	10
CATEGORIES=	net-p2p
MASTER_SITES=	SF \
		http://lopster.sourceforge.net/download/

MAINTAINER=	conrads@cox.net
COMMENT=	GTK+ client for Napster and free alternatives

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ARGS=	--with-pthread=yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS=	FLAC	"Include FLAC support"		On	\
		OGG	"Include OGG support"		On	\
		ZLIB	"Enable ZLIB compression"	On

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

# --with-flac is on by default
.if defined(WITH_FLAC)
LIB_DEPENDS+=		FLAC.10:${PORTSDIR}/audio/flac
.else
CONFIGURE_ARGS+=	--without-flac
.endif

# --with-ogg is on by default
.if defined(WITH_OGG)
LIB_DEPENDS+=		ogg:${PORTSDIR}/audio/libogg
.else
CONFIGURE_ARGS+=	--without-ogg
.endif

# --with-zlib is on by default
.if defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=	--without-zlib
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/www.naplist.com/www.gotnap.com/" \
		${WRKSRC}/src/lopster.h

.include <bsd.port.post.mk>
