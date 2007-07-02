# New ports collection makefile for:	devede
# Date created:		2007-06-20
# Whom:			Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	devede
DISTVERSION=	3.01
CATEGORIES=	multimedia
MASTER_SITES=	http://www.rastersoft.com/descargas/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Create video DVDs, VCDs, sVCDs or CVDs from any number of video files

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer \
		spumux:${PORTSDIR}/multimedia/dvdauthor \
		vcdimager:${PORTSDIR}/multimedia/vcdimager

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_CDRTOOLS=	yes
NO_BUILD=	yes

OPTIONS=	PSYCO "Use psyco to compile the python scripts" Off \

.include <bsd.port.pre.mk>

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

PORTDOCS=	docs/*

DEVEDE_LIBS=	devede_convert.py devede_gtk_helper.py devede_other.py

.if defined(WITH_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco
.endif

pre-everything::
	@${ECHO_MSG} "========================================================================"
	@${ECHO_MSG} "To use devede you need to build multimedia/mplayer with option MENCODER!"
	@${ECHO_MSG} "========================================================================"

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_SCRIPT} ${WRKSRC}/devede.py ${PREFIX}/bin/devede
	${INSTALL_DATA} ${WRKSRC}/devede.glade ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devedesans.ttf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/barras.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/pixmaps/estira.png ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/devede.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/devede.png ${PREFIX}/share/pixmaps
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for lib in ${DEVEDE_LIBS}
	${INSTALL_SCRIPT} ${WRKSRC}/${lib} ${PREFIX}/lib/${PORTNAME}
.endfor
.if !defined(WITHOUT_NLS)
	${INSTALL_DATA} ${WRKSRC}/po/cs_CZ.mo ${PREFIX}/share/locale/cs/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/de_DE.mo ${PREFIX}/share/locale/de/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/ca.mo ${PREFIX}/share/locale/ca/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/es.mo ${PREFIX}/share/locale/es/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/fr.mo ${PREFIX}/share/locale/fr/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/gl.mo ${PREFIX}/share/locale/gl/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/it.mo ${PREFIX}/share/locale/it/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_BR.mo ${PREFIX}/share/locale/pt_BR/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/pt_PT.mo ${PREFIX}/share/locale/pt_PT/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sk.mo ${PREFIX}/share/locale/sk/LC_MESSAGES/devede.mo
	${INSTALL_DATA} ${WRKSRC}/po/sv.mo ${PREFIX}/share/locale/sv/LC_MESSAGES/devede.mo
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
