# New ports collection makefile for:	nautilus-gtkhtml
# Date created:				21 May 2002
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nautilus-gtkhtml
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/nautilus-gtkhtml/0.3
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A simple NautilusView component for displaying html files in Nautilus

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack libgtkhtml nautilus2
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
