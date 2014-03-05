# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudprint
PORTVERSION=	0.11.20140215
CATEGORIES=	print

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Google Cloud Print proxy for local CUPS printers

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups

USE_GITHUB=	yes
GH_ACCOUNT=	armooo
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	07e4711

USE_PYTHON=	2
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
