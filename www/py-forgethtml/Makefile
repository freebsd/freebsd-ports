# Ports collection makefile for:	py-forgethtml
# Date created:				20 November 2004
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	forgethtml
PORTVERSION=	20041021
CATEGORIES=	www python
MASTER_SITES=	http://forgethtml.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-cvs-2004-10-21

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Python module for object-oriented HTML generation

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-build:
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -c 'import forgetHTML'
	@cd ${WRKSRC}/lib && ${PYTHON_CMD} -O -c 'import forgetHTML'

post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/forgetHTML.pyc ${PYTHON_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/lib/forgetHTML.pyo ${PYTHON_SITELIBDIR}/

.include <bsd.port.mk>
