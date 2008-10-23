# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	24.2
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		${MASTER_SITE_SOURCEFORGE:S/$/:source/}
MASTER_SITE_SUBDIR=	numpy/:source
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	Numeric-${PORTVERSION}${EXTRACT_SUFX}:source \
		numpy.pdf:doc
EXTRACT_ONLY=	Numeric-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	The Numeric Extension to Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Numeric
PYDISTUTILS_EGGINFODIR=	${PYTHONPREFIX_SITELIBDIR}/Numeric

# PYDISTUTILS_NOEGGINFO is used as a temporary workaround to fix the plist
PYDISTUTILS_NOEGGINFO=	yes

WRKSRC=		${WRKDIR}/Numeric-${PORTVERSION}

DOCSDIR=	${PREFIX}/share/doc/py-numeric
EXAMPLESDIR=	${PREFIX}/share/examples/py-numeric

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/easy_install)
# py-setuptools is installed - adjust pkg-plist to work with
# implicit usage in setup.py
EASY=""
NOTEASY="@comment "
.else
# py-setuptools is not installed - adjust pkg-plist
EASY="@comment "
NOTEASY=""
.endif

PLIST_SUB+=	EASY=${EASY} NOTEASY=${NOTEASY}

pre-fetch:
.if ${PYTHON_REL} < 200
	@${ECHO} "Py-numeric doesn't work with Python versions < 2.0."
	@${ECHO} "Please use the py-numeric17 port for these."
	@${FALSE}
.endif

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}

post-install:
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLESDIR}/NumTut
.endif
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
