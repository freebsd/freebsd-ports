# $FreeBSD$

PORTNAME=       freenas-datastore
PORTVERSION=    20151008
CATEGORIES=     sysutils
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kmoore@freebsd.org
COMMENT=        FreeNAS data store layer

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>0:${PORTSDIR}/databases/pymongo \
		mongodb>0:${PORTSDIR}/databases/mongodb \
		${PYTHON_PKGNAMEPREFIX}freenas-dispatcher>0:${PORTSDIR}/sysutils/freenas-dispatcher

USES=		python
NO_BUILD= 	yes
ALL_TARGET=	obj all
WRKSRC_SUBDIR=	src/datastore
USE_GITHUB=	yes
GH_ACCOUNT=	freenas
GH_PROJECT=	middleware
GH_TAGNAME=	8ccc378cc7c104416f3b2197ab70747d5de5184f

do-install:
	${MAKE} -C ${WRKSRC} install STAGEDIR=${STAGEDIR} PREFIX=${PREFIX} PYTHON=${PYTHON_CMD}
	${MKDIR} ${STAGEDIR}/data/freenas.db

.include <bsd.port.mk>
