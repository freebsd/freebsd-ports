# New ports collection makefile for:	pyx12
# Date created:		29 Jan 2004
# Whom:			john@zoner.org
#
# $FreeBSD$
#

PORTNAME=	pyx12
PORTVERSION=	1.1.0
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyx12-${PORTVERSION:S/.b/b/}

MAINTAINER=	jholland@kazoocmh.org
COMMENT=	Validate and convert HIPAA X12 documents

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

post-install:
	${WRKSRC}/bin/x12_build_pkl.py ${PREFIX}/share/pyx12/map/

.include <bsd.port.mk>
