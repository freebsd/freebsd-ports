# New ports collection makefile for:	drgenius
# Date created:				11 January 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drgenius
PORTVERSION=	0.8.1
CATEGORIES=	math
MASTER_SITES=	http://www.ofset.org/drgenius/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gob:${PORTSDIR}/x11-toolkits/gob
LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libglade
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
