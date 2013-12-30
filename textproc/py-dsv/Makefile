# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dsv
PORTVERSION=	1.4.1
CATEGORIES=	textproc python
MASTER_SITES=	SF/python-${PORTNAME}/python-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module to parse or write delimeter-separated (e.g. CSV) files

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
DSV_BASEDIR=	${PYTHONPREFIX_SITELIBDIR}/DSV

post-install:
	@${PRINTF} '#!/bin/sh\n${PYTHON_CMD} ${DSV_BASEDIR}/DSV.py "$$@"\n' \
	  >${WRKDIR}/DSV.sh
	${INSTALL_SCRIPT} ${WRKDIR}/DSV.sh ${STAGEDIR}${PREFIX}/bin/DSV
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
