# Created by: Gustau Perez Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	tucan
PORTVERSION=	0.3.10
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://forja.rediris.es/frs/download.php/2051/

MAINTAINER=	gustau.perez@gmail.com
COMMENT=	Tucan Manager aids file-sharing with 1-click hosters

BROKEN=		unfetchable

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${LOCALBASE}/bin/cntraining:graphics/tesseract

NO_BUILD=	yes
USE_GNOME=	pygtk2 librsvg2

USES=		gettext python:2.7

post-patch:
	${REINPLACE_CMD} -Ee 's|#! /usr/bin/env python|#! ${PYTHON_CMD}|' ${WRKSRC}/tucan.py

# remove .orig leftovers from files/patch-*
pre-install:
	${RM} ${WRKSRC}/core/*.orig

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/core
	${MKDIR} ${STAGEDIR}${DATADIR}/default_plugins
	${MKDIR} ${STAGEDIR}${DATADIR}/i18n
	${MKDIR} ${STAGEDIR}${DATADIR}/media
	${MKDIR} ${STAGEDIR}${DATADIR}/ui
	${INSTALL_SCRIPT} ${WRKSRC}/tucan.py ${STAGEDIR}${PREFIX}/share/tucan/
	${LN} -s ${PREFIX}/share/tucan/tucan.py ${STAGEDIR}${PREFIX}/bin/tucan
	(cd ${WRKSRC}/core/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/core/)
	(cd ${WRKSRC}/default_plugins/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/default_plugins/)
	(cd ${WRKSRC}/i18n/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/i18n/)
	(cd ${WRKSRC}/media/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/media/)
	(cd ${WRKSRC}/ui/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/ui/)
	${INSTALL_DATA} ${WRKSRC}/media/tucan.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_MAN} ${WRKSRC}/tucan.1.gz ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL} ${WRKSRC}/tucan.desktop ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
