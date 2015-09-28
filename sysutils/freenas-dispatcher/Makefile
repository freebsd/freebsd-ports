# $FreeBSD$

PORTNAME=       freenas-dispatcher
PORTVERSION=    20150928
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
GH_TAGNAME=	e9c6c4d0cd39e33ca45ca0d3151b5e688b0fb2ee

do-install:
	${MAKE} -C ${WRKSRC} install STAGEDIR=${STAGEDIR} PREFIX=${PREFIX} PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
