# New ports collection makefile for:	gtkglarea
# Date created:		1 August 1999
# Whom:			Michael Sardo <jaeger16@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gtkglarea
PORTVERSION=	1.2.3
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL widget for the GTK+ GUI toolkit

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	libtool:22
USE_GL=		yes
USE_GNOME=	gnometarget gtk12 lthack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lstdc++ ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-lib-GL
USE_LDCONFIG=	yes

.include <bsd.port.mk>
