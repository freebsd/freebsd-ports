# New ports collection makefile for:	pkgview
# Date created:				14 November 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pkgview
PORTVERSION=	0.0.6
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.gtnorthern.demon.co.uk/packages/pkgview/

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%X11BASE%%|${X11BASE}|g' \
			${WRKSRC}/src/config-path.c

.include <bsd.port.mk>
