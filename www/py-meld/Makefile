# New ports collection makefile for:	py-meld
# Date created:				2 May 2006
# Whom:					Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	meld
PORTVERSION=	2.1.3
CATEGORIES=	www python
MASTER_SITES=	http://www.entrian.com/PyMeld/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyMeld
EXTRACT_SUFX=	.py
EXTRACT_ONLY=	# This space left intentionally empty

MAINTAINER=	alex@foxybanana.com
COMMENT=	A system for manipulating HTML using a Pythonic object model

USE_PYTHON=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/PyMeld.py \
		%%PYTHON_SITELIBDIR%%/PyMeld.pyc \
		%%PYTHON_SITELIBDIR%%/PyMeld.pyo

pre-build:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -OOOO -c 'import PyMeld' && \
	${PYTHON_CMD} -c 'import PyMeld'

do-install:
	${INSTALL_DATA} ${WRKSRC}/PyMeld.py ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/PyMeld.pyc ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/PyMeld.pyo ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
