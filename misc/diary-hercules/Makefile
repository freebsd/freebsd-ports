# New ports collection makefile for:	diary-hercules
# Date created:		2 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hercules
PORTVERSION=	0.0.3.2
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}/stable%20branch/${PORTVERSION}
PKGNAMEPREFIX=	diary-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal workout diary program for bodybuilders

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sqlite/__init__.py:${PORTSDIR}/databases/py-PySQLite11

USE_GETTEXT=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes
USE_WX=		2.6
WX_COMPS=	python

.include <bsd.port.mk>
