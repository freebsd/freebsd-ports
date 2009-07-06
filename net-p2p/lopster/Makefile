# New ports collection makefile for:	lopster
# Date created:		19 Oct 2000
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	lopster
PORTVERSION=	1.2.2
PORTREVISION=	6
CATEGORIES=	net-p2p
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://lopster.sourceforge.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ client for Napster

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
CONFIGURE_ARGS=	--with-pthread=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libogg.so.4)
WITH_OGG=	yes
.endif

.if defined(WITH_OGG)
LIB_DEPENDS+=	ogg.6:${PORTSDIR}/audio/libogg
.endif

.if !defined(WITHOUT_ZLIB)
CONFIGURE_ARGS+=	--with-zlib=yes
.else
CONFIGURE_ARGS+=	--with-zlib=no
.endif

pre-everything::
.ifndef WITH_OGG
	@${ECHO_MSG} "You can specify WITH_OGG to include Ogg support"
.endif
.ifndef WITHOUT_ZLIB
	@${ECHO_MSG} "You can specify WITHOUT_ZLIB to disable compression for old servers"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" ${WRKSRC}/configure

.include <bsd.port.post.mk>
