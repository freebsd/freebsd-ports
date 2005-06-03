# New ports collection makefile for:	gtkglarea
# Date created:		1 August 1999
# Whom:			Michael Sardo <jaeger16@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gtkglarea
PORTVERSION=	1.2.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL widget for the GTK+ GUI toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gtk12 lthack
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++ ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-lib-GL
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
