# ex:ts=8
# New ports collection makefile for:	py-rijndael
# Date created:			Jul 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rijndael
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	ftp://ftp.openbsd.org/pub/OpenBSD/distfiles/	\
		http://people.FreeBSD.org/~foxfair/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyRijndael-${PORTVERSION}.py
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A pure python implementation of the Rijndael encryption algorithm

EXTRACT_AFTER_ARGS=	> ${DISTNAME}
USE_PYTHON=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${MV} ${WRKSRC}/${DISTNAME} ${WRKSRC}/pyRijndael.py

do-build:
	@cd ${WRKSRC} && ${PYTHON_CMD} -c 'import pyRijndael'
	@cd ${WRKSRC} && ${PYTHON_CMD} -O -c 'import pyRijndael'

do-install:
	@${INSTALL_DATA} ${WRKSRC}/pyRijndael.* ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
