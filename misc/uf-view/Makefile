# Created by: Jonathan McGee <mcgee@wam.umd.edu>
# $FreeBSD$

PORTNAME=	uf-view
PORTVERSION=	2.4
PORTREVISION=	12
CATEGORIES=	misc
MASTER_SITES=	http://www.hadess.net/files/software/uf-view/

MAINTAINER=	mcgee@wam.umd.edu
COMMENT=	A gTK+ viewer for the User Friendly and several other popular comics

DEPRECATED=	gnome-desktop 2.x will be updated in the GNOME 3 import 
EXPIRATION_DATE=2014-04-10

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gnomehack gnomehier gnomevfs2 gnomedesktop libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
