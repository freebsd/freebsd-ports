# New ports collection makefile for:	stickynotes_applet
# Date created:				17 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stickynotes_applet
PORTVERSION=	1.0.6
CATEGORIES=	misc gnome
MASTER_SITES=	http://loban.caltech.edu/stickynotes/packages/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet that adds sticky notes to your desktop

LIB_DEPENDS=	panel-applet-2.0:${PORTSDIR}/x11/gnomepanel

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in INSTALL COPYING NEWS AUTHORS THANKS README TODO ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/pixmaps/stickynotes.png \
		${PREFIX}/share/gnome/pixmaps

.include <bsd.port.mk>
