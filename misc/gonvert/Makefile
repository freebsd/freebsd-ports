# ex:ts=8
# New ports collection makefile for:	gonvert
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gonvert
PORTVERSION=	0.2.12
CATEGORIES=	misc python gnome
MASTER_SITES=	http://www.unihedron.com/projects/gonvert/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A conversion utility that allows conversion between many units

USE_X_PREFIX=	yes
USE_GNOME=	gnomehier pygtk2
USE_PYTHON=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|#!/usr/bin/python|#!/usr/bin/env python|g' ${WRKSRC}/gonvert

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gonvert ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/gonvert.desktop \
		${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gonvert.png \
		${PREFIX}/share/gnome/pixmaps
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gonvert.glade ${DATADIR}
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gonvert_picture.png \
		${DATADIR}/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README CHANGELOG FAQ README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
