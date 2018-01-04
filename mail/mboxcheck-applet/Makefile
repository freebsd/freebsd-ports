# Created by: Pav Lucistnik <pav@oook.cz>
# $FreeBSD$

PORTNAME=	mboxcheck-applet
PORTVERSION=	0.3
PORTREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	http://perso.orange.fr/seb128/fichiers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailbox checking applet for GNOME 2

USES=		python:2.7
USE_GNOME=	pygnome2:run
NO_BUILD=	yes

do-patch:
	@${REINPLACE_CMD} 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/*.py
	@${REINPLACE_CMD} 's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|' ${WRKSRC}/mboxcheck.py
	@${REINPLACE_CMD} 's|/usr/lib/gnome-panel/mboxcheck|${LOCALBASE}/libexec/mboxcheck.py|' ${WRKSRC}/GNOME_MboxCheck.server
	@${REINPLACE_CMD} 's|mbox.png|mboxcheck.png|' ${WRKSRC}/GNOME_MboxCheck.server

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mboxcheck.py ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/configmbox.py ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/mboxcheck.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}/${PREFIX}/libdata/bonobo/servers
	${INSTALL_DATA} ${WRKSRC}/GNOME_MboxCheck.server \
		${STAGEDIR}${PREFIX}/libdata/bonobo/servers

.include <bsd.port.mk>
