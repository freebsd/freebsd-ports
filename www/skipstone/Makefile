# New ports collection makefile for:	skipstone
# Date created:				16 November 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	skipstone
PORTVERSION=	0.8.3
PORTCOMMENT=	Web browser that uses the mozilla-embedded renderer
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	eric@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded
RUN_DEPENDS=	${X11BASE}/lib/mozilla-embedded/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded \
		wget:${PORTSDIR}/ftp/wget

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes=${X11BASE}/include/mozilla --with-mozilla-libs=${X11BASE}/lib/mozilla-embedded

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/configure

.include <bsd.port.mk>
