# New ports collection makefile for:	py-asv
# Date created:		4 April 2001
# Whom:	      		Johann Visagie <johann@egenetics.com>
#
# $FreeBSD$
#

PORTNAME=	asv
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	textproc python
MASTER_SITES=	http://tratt.net/laurie/python/asv/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible Python module to parse simple text file formats like CSV

USE_PYTHON=	yes

ASV_BASEDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@printf '#!/bin/sh\n${PYTHON_CMD} ${ASV_BASEDIR}/ASV.py "$$@"\n' \
		> ${WRKDIR}/asv.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/asv.sh ${PREFIX}/bin/asv
	@${INSTALL_DATA} ${WRKSRC}/ASV.* ${ASV_BASEDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in INSTALL README THANKS
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	@${MKDIR} ${EXAMPLESDIR}
.for egfile in asv_example.* example_data.csv
	@${INSTALL_DATA} ${WRKSRC}/${egfile} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
