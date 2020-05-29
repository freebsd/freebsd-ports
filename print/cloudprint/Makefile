# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cloudprint
PORTVERSION=	0.14.0.20170128
PORTREVISION=	2
CATEGORIES=	print

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Google Cloud Print proxy for local CUPS printers

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configargparse>=0.9.3:devel/py-configargparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemon>0:devel/py-daemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.7.0:www/py-requests@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	armooo
GH_TAGNAME=	108b9f0

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils optsuffix
USE_RC_SUBR=	${PORTNAME}

USERS=		cups
GROUPS=		cups

SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}" \
		CPUSER="${USERS}" \
		CPGROUP="${GROUPS}"

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3500
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycups1>=0:print/py-pycups1@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pycups>=0:print/py-pycups@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
