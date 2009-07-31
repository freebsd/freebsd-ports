# New ports collection makefile for:	uf-view
# Date created:				30 May 2001
# Whom:				Jonathan McGee <mcgee@wam.umd.edu>
#
# $FreeBSD$
#

PORTNAME=	uf-view
PORTVERSION=	2.4
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	http://www.hadess.net/files/software/uf-view/

MAINTAINER=	mcgee@wam.umd.edu
COMMENT=	A gTK+ viewer for the User Friendly and several other popular comics

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomevfs2 gnomedesktop
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
