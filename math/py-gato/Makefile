# New ports collection makefile for:	py-gato
# Date created:		31 August 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gato
PORTVERSION=	0.99D
CATEGORIES=	math python
MASTER_SITES=	http://gato.sourceforge.net/Download/
MASTER_SITE_SUBDIR=	gato
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Gato-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python-based toolbox to visualise algorithms on graphs

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/Gato
GATO_DIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/Gato
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

post-patch:
	@ ${REINPLACE_CMD} -e 's,^.*__future__.*$$,,' ${WRKSRC}/DataStructures.py

pre-build:
	@ ${TOUCH} ${WRKSRC}/__init__.py

do-build:
	@ ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@ ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@ ${MKDIR} ${GATO_DIR}
	@ cd ${WRKSRC} && ${FIND} *.py *.pyc *.pyo \
	  -name Gato.py\* -o -print \
	  | ${CPIO} --verbose -pdum -R ${BINOWN}:${BINGRP} ${GATO_DIR}
.for script in Gato Gred
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${script}.py ${PREFIX}/bin/${script}
.endfor

post-install:
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}
.for egfile in *.alg *.pro *.cat
	@ ${INSTALL_DATA} ${WRKSRC}/${egfile} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
