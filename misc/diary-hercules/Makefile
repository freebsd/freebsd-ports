# New ports collection makefile for:	diary-hercules
# Date created:		2 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hercules
PORTVERSION=	0.0.3.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	diary-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A personal workout diary program for bodybuilders

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/wx-2.6-gtk2-unicode/wx/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26-unicode \
		${PYTHON_SITELIBDIR}/sqlite/__init__.py:${PORTSDIR}/databases/py-PySQLite11

USE_GETTEXT=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
