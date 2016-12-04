# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudprint
PORTVERSION=	0.14
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Google Cloud Print proxy for local CUPS printers

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycups>=0:print/py-pycups \
		${PYTHON_PKGNAMEPREFIX}daemon>0:devel/py-daemon \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests

USE_GITHUB=	yes
GH_ACCOUNT=	armooo
GH_TAGNAME=	4618224

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	${PORTNAME}

USERS=		cups
GROUPS=		cups

SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}" \
		CPUSER="${USERS}" \
		CPGROUP="${GROUPS}"

.include <bsd.port.mk>
