# New ports collection makefile for:	uf-view
# Date created:				30 May 2001
# Whom:				Jonathan McGee <mcgee@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	uf-view
PORTVERSION=	2.2
CATEGORIES=	misc
MASTER_SITES=	http://www.hadess.net/files/software/uf-view/

MAINTAINER=	mcgee@wam.umd.edu
COMMENT=	A gTK+ viewer for the User Friendly and several other popular comics

LIB_DEPENDS=	gnomevfs-2.0:${PORTSDIR}/devel/gnomevfs2 \
		gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		gnome-desktop-2.3:${PORTSDIR}/x11/gnomedesktop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
