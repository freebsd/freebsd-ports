# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	0.7.1
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	meld
EXTRACT_SUFX=	.tgz

MAINTAINER=	pav@oook.cz
COMMENT=	GNOME 2 visual diff and merge tool

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|os.path.dirname(sys.argv\[0\])|"${PYTHON_SITELIBDIR}/meldapp"|' ${WRKSRC}/misc.py
	@${REINPLACE_CMD} -e 's|/"+os.path.abspath(misc.appdir("manual/index.html") )|${PREFIX}/share/doc/meld/index.html"|' ${WRKSRC}/meldapp.py
	@${REINPLACE_CMD} \
		-e 's|/usr/share/pixmaps|${X11BASE}/share/gnome/pixmaps|' \
		${WRKSRC}/cvsview.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/meld ${PREFIX}/bin
	${ECHO} meldapp > ${PYTHON_SITELIBDIR}/meldapp.pth
	${MKDIR} ${PYTHON_SITELIBDIR}/meldapp
	${INSTALL_DATA} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/meldapp
	${MKDIR} ${PYTHON_SITELIBDIR}/meldapp/glade2
	${INSTALL_DATA} ${WRKSRC}/glade2/*.glade* ${PYTHON_SITELIBDIR}/meldapp/glade2
	${MKDIR} ${PYTHON_SITELIBDIR}/meldapp/glade2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/glade2/pixmaps/*.png ${PYTHON_SITELIBDIR}/meldapp/glade2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/glade2/pixmaps/*.xpm ${PYTHON_SITELIBDIR}/meldapp/glade2/pixmaps
	${MKDIR} ${PREFIX}/share/doc/meld
	${INSTALL_DATA} ${WRKSRC}/manual/*.html ${PREFIX}/share/doc/meld
	${INSTALL_DATA} ${WRKSRC}/manual/*.css ${PREFIX}/share/doc/meld

.include <bsd.port.mk>
