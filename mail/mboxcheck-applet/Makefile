# New ports collection makefile for: xmms-status-plugin
# Date created:			Sep 28, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	mboxcheck-applet
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	http://perso.wanadoo.fr/seb128/fichiers/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Mailbox checking applet for GNOME 2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_X_PREFIX=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

do-patch:
	@${REINPLACE_CMD} 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/*.py
	@${REINPLACE_CMD} 's|/usr/share/pixmaps/|${X11BASE}/share/gnome/pixmaps/|' ${WRKSRC}/mboxcheck.py
	@${REINPLACE_CMD} 's|/usr/lib/gnome-panel/mboxcheck|${X11BASE}/libexec/mboxcheck.py|' ${WRKSRC}/GNOME_MboxCheck.server
	@${REINPLACE_CMD} 's|mbox.png|mboxcheck.png|' ${WRKSRC}/GNOME_MboxCheck.server

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mboxcheck.py ${X11BASE}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/configmbox.py ${X11BASE}/libexec
	${INSTALL_DATA} ${WRKSRC}/mboxcheck.png ${X11BASE}/share/gnome/pixmaps
	${INSTALL_DATA} ${WRKSRC}/GNOME_MboxCheck.server ${X11BASE}/libdata/bonobo/servers

.include <bsd.port.mk>
