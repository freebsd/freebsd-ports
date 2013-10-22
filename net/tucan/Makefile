# Created by: Gustau Perez Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	tucan
PORTVERSION=	0.3.10
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://forja.rediris.es/frs/download.php/2051/ \
		http://build-tucan-doc.googlecode.com/files/

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Tucan Manager aids file-sharing with 1-click hosters

RUN_DEPENDS=	${LOCALBASE}/bin/pilconvert.py:${PORTSDIR}/graphics/py-imaging \
		${LOCALBASE}/bin/cntraining:${PORTSDIR}/graphics/tesseract

NO_BUILD=	yes
USE_GNOME=	pygtk2 librsvg2
USE_PYTHON=	2.5+

MANCOMPRESSED=	yes
MAN1=		tucan.1
USES=		gettext

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -Ee 's|#! /usr/bin/env python|#! ${PYTHON_CMD}|' ${WRKSRC}/tucan.py

# remove .orig leftovers from files/patch-*
pre-install:
	${RM} ${WRKSRC}/core/*.orig

do-install:
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
	${INSTALL_DATA} ${WRKSRC}/media/tucan.png ${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/tucan.1.gz ${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/tucan.desktop ${PREFIX}/share/applications/

.include <bsd.port.mk>
