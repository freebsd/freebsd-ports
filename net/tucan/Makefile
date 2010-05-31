# New ports collection makefile for:   Tucan
# Date created:         2009-14-11
# Whom:                 Gustau Perez Querol <gustau.perez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tucan
PORTVERSION=	0.3.9
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://forja.rediris.es/frs/download.php/1470/ \
		http://build-tucan-doc.googlecode.com/files/

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Give us the links, we'll cook the meal!

RUN_DEPENDS=	${LOCALBASE}/bin/pilconvert.py:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/bin/cntraining:${PORTSDIR}/graphics/tesseract/

NO_BUILD=	yes
USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	yes

MANCOMPRESSED=	yes
MAN1=		tucan.1
USE_GETTEXT=	yes

do-install:
	${MKDIR} ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/share/pixmaps/
	${MKDIR} ${PREFIX}/man/man1/
	${MKDIR} ${PREFIX}/share/applications/
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/core
	${MKDIR} ${DATADIR}/default_plugins
	${MKDIR} ${DATADIR}/i18n
	${MKDIR} ${DATADIR}/media
	${MKDIR} ${DATADIR}/ui
	${INSTALL_SCRIPT} ${WRKSRC}/tucan.py ${PREFIX}/share/tucan/
	${LN} -s ${PREFIX}/share/tucan/tucan.py ${PREFIX}/bin/tucan
	(cd ${WRKSRC}/core/ && ${COPYTREE_SHARE} \* ${DATADIR}/core/)
	(cd ${WRKSRC}/default_plugins/ && ${COPYTREE_SHARE} \* ${DATADIR}/default_plugins/)
	(cd ${WRKSRC}/i18n/ && ${COPYTREE_SHARE} \* ${DATADIR}/i18n/)
	(cd ${WRKSRC}/media/ && ${COPYTREE_SHARE} \* ${DATADIR}/media/)
	(cd ${WRKSRC}/ui/ && ${COPYTREE_SHARE} \* ${DATADIR}/ui/)
	${INSTALL_DATA} ${WRKSRC}/media/tucan.svg ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/tucan.1.gz ${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/tucan.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
