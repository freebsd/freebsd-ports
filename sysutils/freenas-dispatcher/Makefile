# $FreeBSD$

PORTNAME=       freenas-dispatcher
PORTVERSION=    20151008
CATEGORIES=     sysutils
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=     kmoore@freebsd.org
COMMENT=        FreeNAS middleware daemon

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>0:${PORTSDIR}/devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}enum34>0:${PORTSDIR}/devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}ws4py>0:${PORTSDIR}/www/py-ws4py \
		${PYTHON_PKGNAMEPREFIX}fnutils>0:${PORTSDIR}/sysutils/py-fnutils

NO_BUILD=	yes
ALL_TARGET=	obj all
USES=		python
USE_GITHUB=	yes
WRKSRC_SUBDIR=	src/dispatcher
GH_ACCOUNT=	freenas
GH_PROJECT=	middleware
GH_TAGNAME=	658a4831382e98c95ec4a6a0d9294169f99ea3d0

do-install:
	${MAKE} -C ${WRKSRC} install STAGEDIR=${STAGEDIR} PREFIX=${PREFIX} PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
