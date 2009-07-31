# New ports collection makefile for:	wmtimer
# Date created:			Thu Apr 26 16:46:38 EDT 2001
# Whom:				Patrick Li <pat@databits.net> et al
#
# $FreeBSD$
#

PORTNAME=	wmtimer
PORTVERSION=	2.92
PORTREVISION=	6
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.darkops.net/wmtimer/

MAINTAINER=	uspoerlein@gmail.com
COMMENT=	Multi-Function timer dockapp for WindowMaker

WRKSRC=		${WRKDIR}/${DISTNAME}/wmtimer
PORTDOCS=	README
PLIST_FILES=	bin/wmtimer
USE_GMAKE=	yes
USE_XORG=	x11 xau xcomposite xcursor xdamage xdmcp xext xfixes xi \
		xinerama xpm xrandr xrender
USE_GNOME=	gtk20
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtimer ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
