# Ports collection Makefile for:	gnomemeeting
# Date created:				24/07/2001
# Whom:					roger@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ekiga
PORTVERSION=	2.0.1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/2.0

MAINTAINER=	jbq@caraldi.com
COMMENT=	VoIP phone for Gnome

LIB_DEPENDS=	opal__r.2:${PORTSDIR}/net/opal \
		avahi-core.4:${PORTSDIR}/net/avahi \
		ebook-1.2.5:${PORTSDIR}/databases/evolution-data-server

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GNOME=	libgnomeui libbonobo gnomeprefix gnomehack gnomelibs gnomedocutils
USE_AUTOTOOLS=	libtool:15
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config LDFLAGS="${LDFLAGS}"

CONFIGURE_ARGS=	--with-pwlib-dir=${LOCALBASE} \
		--with-opal-dir=${LOCALBASE}

GCONF_SCHEMAS=	ekiga.schemas
MAN1=		ekiga.1

.include <bsd.port.mk>
