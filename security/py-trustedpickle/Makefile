# Created by: Alexander Botero-Lowry <alex@foxybanana.com>
# $FreeBSD$

PORTNAME=	trustedpickle
PORTVERSION=	0.02
CATEGORIES=	security python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TrustedPickle

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TrustedPickle is a Python (de)Pickler with a way to verify the data

LICENSE=	BSD2CLAUSE

USES=		dos2unix python tar:tgz
NO_ARCH=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/TrustedPickle.py \
		%%PYTHON_SITELIBDIR%%/TrustedPickle.pyc \
		%%PYTHON_SITELIBDIR%%/TrustedPickle.pyo

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -OOOO -c 'import TrustedPickle' && \
	${PYTHON_CMD} -c 'import TrustedPickle'

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.py ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.pyc ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.pyo ${STAGEDIR}${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
