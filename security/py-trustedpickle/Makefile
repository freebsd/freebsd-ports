# New ports collection makefile for:    py-trustedpickle
# Date created:				02 May 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	trustedpickle
PORTVERSION=	0.02
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TrustedPickle
EXTRACT_SUFX=	.tgz

MAINTAINER=	alex@foxybanana.com
COMMENT=	TrustedPickle is a Python (de)Pickler with a way to verify the data

USE_PYTHON=	yes
USE_DOS2UNIX=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/TrustedPickle.py \
		%%PYTHON_SITELIBDIR%%/TrustedPickle.pyc \
		%%PYTHON_SITELIBDIR%%/TrustedPickle.pyo

WRKSRC=		${WRKDIR}/${PORTNAME}

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -OOOO -c 'import TrustedPickle' && \
	${PYTHON_CMD} -c 'import TrustedPickle'

do-install:
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.py ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.pyc ${PYTHON_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/TrustedPickle.pyo ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
