# New ports collection makefile for:	py-csv
# Date created:		17 January 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dsv
PORTVERSION=	1.4.0
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python module to parse or write delimeter-separated (e.g. CSV) files

.if defined(WITH_GUI)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
DSV_BASEDIR=	${PYTHONPREFIX_SITELIBDIR}/DSV

post-install:
	@${PRINTF} '#!/bin/sh\n${PYTHON_CMD} ${DSV_BASEDIR}/DSV.py "$$@"\n' \
	  >${WRKDIR}/DSV.sh
	@ ${INSTALL_SCRIPT} ${WRKDIR}/DSV.sh ${PREFIX}/bin/DSV
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/DSV/*.csv ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
