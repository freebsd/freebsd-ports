# New ports collection makefile for: 	tsclient
# Date created:				01 Mar 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	tsclient
PORTVERSION=	0.124
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	http://www.gnomepro.com/tsclient/

MAINTAINER=	einekoai@chello.nl
COMMENT=	A GNOME 2 frontend for rdesktop

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${LN} -sf ${PREFIX}/share/gnome/pixmaps/tsclient/tsclient.png \
		${PREFIX}/share/gnome/pixmaps/tsclient.png

.include <bsd.port.mk>
