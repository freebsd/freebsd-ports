# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudprint
PORTVERSION=	0.11.20140215
PORTREVISION=	1
CATEGORIES=	print

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Google Cloud Print proxy for local CUPS printers

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cups.so:${PORTSDIR}/print/py-cups \
		${PYTHON_PKGNAMEPREFIX}daemon>0:${PORTSDIR}/devel/py-daemon

USE_GITHUB=	yes
GH_ACCOUNT=	armooo
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	07e4711

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
USE_RC_SUBR=	${PORTNAME}

USERS=		cups
GROUPS=		cups

SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}" \
		CPUSER="${USERS}" \
		CPGROUP="${GROUPS}"

.include <bsd.port.mk>
