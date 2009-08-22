# New ports collection makefile for:	numpy
# Date created:		20 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	numeric
PORTVERSION=	24.2
PORTREVISION=	3
CATEGORIES=	math python
MASTER_SITES=	http://numpy.scipy.org/:doc \
		SF/numpy/Old%20Numeric/${PORTVERSION}:source
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

.if exists(${LOCALBASE}/bin/easy_install-${PYTHON_VER})
# py-setuptools is installed - adjust pkg-plist to work with
# implicit usage in setup.py
EASY=""
NOTEASY="@comment "
.else
# py-setuptools is not installed - adjust pkg-plist
EASY="@comment "
NOTEASY=""
.endif

# Adjusting pkg-plist gets weirder here. Python 2.5+ incorporates
# install_egg_info functionality into distutils, so if py-numeric
# is installed into a lesser Python version, make sure all egg-related
# pkg-plist entries are omitted
.if ${PYTHON_SUFFIX} < 25
NOEGGINFO="@comment "
.else
NOEGGINFO=""
.endif

PLIST_SUB+=	EASY=${EASY} NOTEASY=${NOTEASY} \
		PYDISTUTILS_EGGINFO=${PYDISTUTILS_EGGINFO} \
		NOEGGINFO=${NOEGGINFO}

post-extract:
	@${CP} ${DISTDIR}/numpy.pdf ${WRKDIR}
#
# Force the setup.py file to use a specific version of Python,
# since more than one may be installed, and we want to use
# the correct one, because if one has setuptools and another
# doesn't, that could mess with how pkg-plist is constructed.
#
	@${REINPLACE_CMD} -e "s|/usr/bin/env python|/usr/bin/env python${PYTHON_VER}|" ${WRKSRC}/setup.py

post-install:
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Demo/*.py ${EXAMPLESDIR}
	@${INSTALL} -d ${EXAMPLESDIR}/NumTut
	${INSTALL_DATA} ${WRKSRC}/Demo/NumTut/* ${EXAMPLESDIR}/NumTut
.endif
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/numpy.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
