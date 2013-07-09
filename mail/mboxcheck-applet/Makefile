# New ports collection makefile for: xmms-status-plugin
# Date created:			Sep 28, 2003
# Whom:				Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$

PORTNAME=	mboxcheck-applet
PORTVERSION=	0.3
PORTREVISION=	12
CATEGORIES=	mail
MASTER_SITES=	http://perso.orange.fr/seb128/fichiers/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mailbox checking applet for GNOME 2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
NO_BUILD=	yes

do-patch:
	@${REINPLACE_CMD} 's|/usr/bin/python|${PYTHON_CMD}|' ${WRKSRC}/*.py
	@${REINPLACE_CMD} 's|/usr/share/pixmaps/|${LOCALBASE}/share/pixmaps/|' ${WRKSRC}/mboxcheck.py
	@${REINPLACE_CMD} 's|/usr/lib/gnome-panel/mboxcheck|${LOCALBASE}/libexec/mboxcheck.py|' ${WRKSRC}/GNOME_MboxCheck.server
	@${REINPLACE_CMD} 's|mbox.png|mboxcheck.png|' ${WRKSRC}/GNOME_MboxCheck.server

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mboxcheck.py ${LOCALBASE}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/configmbox.py ${LOCALBASE}/libexec
	${INSTALL_DATA} ${WRKSRC}/mboxcheck.png ${LOCALBASE}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/GNOME_MboxCheck.server ${LOCALBASE}/libdata/bonobo/servers

.include <bsd.port.mk>
