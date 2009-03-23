# ex:ts=8
# New ports collection makefile for:	py-rijndael
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rijndael
PORTVERSION=	1.4
CATEGORIES=	security python
MASTER_SITES=	http://jclement.ca/software/pyrijndael/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyrijndael-v${PORTVERSION:S:.:_:}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure python implementation of the Rijndael encryption algorithm

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/pyrijndael

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -c 'import pyRijndael'
	@cd ${WRKSRC} && ${PYTHON_CMD} -O -c 'import pyRijndael'

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pyRijndael.* ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
