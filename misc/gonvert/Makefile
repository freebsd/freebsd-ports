# ex:ts=8
# New ports collection makefile for:	gonvert
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gonvert
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	misc python gnome
MASTER_SITES=	http://www.unihedron.com/projects/gonvert/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A conversion utility that allows conversion between many units

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier
USE_PYTHON=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gonvert ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gonvert.desktop \
		${PREFIX}/share/gnome/apps/Utilities
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gonvert_icon.png \
		${PREFIX}/share/gnome/pixmaps
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gonvert.glade ${DATADIR}
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${DATADIR}/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README CHANGELOG FAQ README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
