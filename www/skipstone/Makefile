# New ports collection makefile for:	skipstone
# Date created:				16 November 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	skipstone
PORTVERSION=	0.8.3
CATEGORIES=	www
MASTER_SITES=	http://www.muhri.net/skipstone/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web browser that uses the mozilla-embedded renderer

BUILD_DEPENDS=	${X11BASE}/include/mozilla-vendor/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers-vendor \
		${X11BASE}/lib/mozilla-embedded-vendor/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded-vendor
RUN_DEPENDS=	${X11BASE}/lib/mozilla-embedded-vendor/libgtkembedmoz.so:${PORTSDIR}/www/mozilla-embedded-vendor \
		wget:${PORTSDIR}/ftp/wget

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes=${X11BASE}/include/mozilla-vendor --with-mozilla-libs=${X11BASE}/lib/mozilla-embedded-vendor

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|' ${WRKSRC}/configure

.include <bsd.port.mk>
