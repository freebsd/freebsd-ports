# New ports collection makefile for:	libwnck
# Date created:				12 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libwnck
PORTVERSION=	0.18
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.18
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomehack
USE_REINPLACE=	yes
USE_BISON=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
