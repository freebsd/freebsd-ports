# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	20.3
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	numpy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Numeric-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes

DOCDIR=		${PREFIX}/share/doc/py-numeric
EXAMPLEDIR=	${PREFIX}/share/examples/py-numeric

.include <bsd.port.pre.mk>

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numeric doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup_all.py build

do-install:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${PYTHON_CMD} setup_all.py install

post-install:
	@${MKDIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLEDIR}
	@${MKDIR} ${EXAMPLEDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLEDIR}/NumTut
.if !defined(NOPORTDOCS)
#	@${MKDIR} ${DOCDIR}
#	${INSTALL_DATA} ${WRKSRC}/Doc/numpy.pdf ${DOCDIR}
.endif

.include <bsd.port.post.mk>
