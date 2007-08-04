# New ports collection makefile for:	py-funkload
# Date created:		Mar. 03, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	funkload
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://funkload.nuxeo.org/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	FunkLoad is a functional and load web tester

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/docutils/__init__.py:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_SITELIBDIR}/gdchart.so:${PORTSDIR}/graphics/py-gdchart \
		${PYTHON_SITELIBDIR}/webunit/__init__.py:${PORTSDIR}/www/py-webunit \
		${PYXML} \
		tcpwatch.py:${PORTSDIR}/net/tcpwatch

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/funkload/demo ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
