# ex:ts=8
# New ports collection makefile for:	gonvert
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gonvert
PORTVERSION=	0.2.21
CATEGORIES=	misc python gnome
MASTER_SITES=	http://www.unihedron.com/projects/gonvert/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A conversion utility that allows conversion between many units

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|#!/usr/bin/python|#!/usr/bin/env python|g ; \
		 s|/usr/share|${PREFIX}/share|g ; \
		 s|/\.\./pixmaps/|/pixmaps/|g' ${WRKSRC}/gonvert

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gonvert ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/gonvert.desktop ${PREFIX}/share/applications
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gonvert.glade ${DATADIR}
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/*.png ${DATADIR}/pixmaps
	@${MKDIR} ${PREFIX}/share/pixmaps
	${LN} -sf ${DATADIR}/pixmaps/gonvert.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${PREFIX}/share/locale/pl/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/i18n/pl_messages.gmo \
		${PREFIX}/share/locale/pl/LC_MESSAGES/gonvert.mo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG FAQ README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
