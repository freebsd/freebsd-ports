# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gonvert
PORTVERSION=	0.2.31
CATEGORIES=	misc python gnome
MASTER_SITES=	http://www.unihedron.com/projects/gonvert/downloads/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Conversion utility that allows conversion between many units

LICENSE=	GPLv2

USE_GNOME=	pygtk2
USE_PYTHON=	yes
NO_BUILD=	yes

PORTDOCS=	CHANGELOG FAQ README THANKS TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

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

.if ${PORT_OPTIONS:MNLS}
	@${MKDIR} ${PREFIX}/share/locale/pl/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/i18n/pl_messages.gmo \
		${PREFIX}/share/locale/pl/LC_MESSAGES/gonvert.mo
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
