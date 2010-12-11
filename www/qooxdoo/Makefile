# New ports collection makefile for:	qooxdoo
# Date created:		2010-12-10
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qooxdoo
PORTVERSION=	1.3
#PORTREVISION=	0
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-current/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-sdk

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A comprehensive and innovative Ajax application framework

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

NO_BUILD=	yes

QXDDIRS=	component framework tool

REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},'

USE_PYTHON=	-2.7
USE_ZIP=	yes

XARGS_ARGS=	-0

post-patch:
	${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	${FIND} ${FIND_FILES_BAK} -delete

do-install:
	${MKDIR} ${DATADIR}
.for D in ${QXDDIRS}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/documentation/manual && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	cd ${WRKSRC}/application && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
	${LN} -s ${DATADIR}/tool/bin/create-application.py ${PREFIX}/bin/create-application.py

.include <bsd.port.mk>
