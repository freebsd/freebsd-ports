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
PLIST_FILES=	bin/${PORTNAME}.py

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PYTHON_CMD}|' ${WRKSRC}/${PORTNAME}.py

.include <bsd.port.mk>
