# New ports collection makefile for:	stickynotes_applet
# Date created:				17 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stickynotes_applet
PORTVERSION=	1.2.3
CATEGORIES=	misc gnome
MASTER_SITES=	http://loban.caltech.edu/stickynotes/packages/

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	Applet that adds sticky notes to your desktop

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in INSTALL COPYING NEWS AUTHORS THANKS README TODO ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
