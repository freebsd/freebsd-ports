# New ports collection makefile for:	meld
# Date created:				2003-04-13
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	0.8.4
CATEGORIES=	textproc devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	meld
EXTRACT_SUFX=	.tgz

MAINTAINER=	rui@ruilopes.com
COMMENT=	GNOME 2 visual diff and merge tool

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_PYTHON=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|os.path.dirname(sys.argv\[0\])|"${INSTALLDIR}"|' ${WRKSRC}/misc.py
	@${REINPLACE_CMD} -e 's|/"+os.path.abspath(misc.appdir("manual/index.html") )|${DOCSDIR}/index.html"|' ${WRKSRC}/meldapp.py
	@${REINPLACE_CMD} -e 's|^Path=.*$$|Icon=${INSTALLDIR}/glade2/pixmaps/icon.png|' ${WRKSRC}/meld.desktop

INSTALLDIR=	${PREFIX}/share/meld
do-install:
	${MKDIR} ${INSTALLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/meld ${INSTALLDIR}
	${LN} -sf ${INSTALLDIR}/meld ${PREFIX}/bin/meld
	${INSTALL_DATA} ${WRKSRC}/meld.desktop ${PREFIX}/share/gnome/applications
	${INSTALL_DATA} ${WRKSRC}/*.py ${INSTALLDIR}
	${MKDIR} ${INSTALLDIR}/glade2
	${INSTALL_DATA} ${WRKSRC}/glade2/*.glade ${INSTALLDIR}/glade2
	${MKDIR} ${INSTALLDIR}/glade2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/glade2/pixmaps/*.png ${INSTALLDIR}/glade2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/glade2/pixmaps/*.xpm ${INSTALLDIR}/glade2/pixmaps
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual/*.css ${DOCSDIR}
.endif

post-install:
	@${ECHO_CMD} 'Compiling files...'
	@(cd ${INSTALLDIR} && \
		${PYTHON_CMD} -c "import compileall; compileall.compile_dir('.', 0)" && \
		${PYTHON_CMD} -O -c "import compileall; compileall.compile_dir('.', 0)")

.include <bsd.port.mk>
