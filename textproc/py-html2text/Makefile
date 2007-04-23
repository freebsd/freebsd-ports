# New ports collection makefile for:	html2text
# Date created:		23 April 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	html2text
PORTVERSION=	2.2.8
CATEGORIES=	textproc python
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Convert HTML into clean plain ASCII text

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}.py

post-install:
	@${CHMOD} 755 ${PYTHON_SITELIBDIR}/${PORTNAME}.py
	@${LN} -sf ${PYTHON_SITELIBDIR}/${PORTNAME}.py ${PREFIX}/bin/

.include <bsd.port.mk>
