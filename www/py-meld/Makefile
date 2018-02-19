# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	meld
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://entrian.com/PyMeld/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyMeld
EXTRACT_SUFX=	.py
EXTRACT_ONLY=	# This space left intentionally empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System for manipulating HTML using a Pythonic object model

LICENSE=	MIT

USES=		python:2.7

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
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/PyMeld.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/PyMeld.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/PyMeld.pyo ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
