# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qooxdoo
PORTVERSION=	2.1.1
PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-current/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-sdk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive and innovative Ajax application framework

LICENSE=	LGPL3 EPL
LICENSE_COMB=	dual

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

QXDDIRS=	component framework tool

REINPLACE_ARGS=	-e 's,/usr/bin/env python,&${PYTHON_VER},' -i.bak

USE_PYTHON=	2
USES=		zip

SHAREMODE=	644

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	${FIND} ${FIND_FILES} | ${XARGS} -0 ${REINPLACE_CMD}
	${FIND} ${FIND_FILES_BAK} -delete

do-build:
	${PYTHON_CMD} -m compileall -f ${WRKSRC}/tool
	${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/tool

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.for D in ${QXDDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${STAGEDIR}${DATADIR}
.endfor
	cd ${WRKSRC}/documentation/manual && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/application && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/version.txt ${STAGEDIR}${DATADIR}
	${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/tool/bin/*.py
	${INSTALL_SCRIPT} ${WRKSRC}/create-application.py ${STAGEDIR}${DATADIR}/create-application.py

.include <bsd.port.mk>
