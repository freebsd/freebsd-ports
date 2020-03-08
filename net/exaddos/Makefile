# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaddos
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ZI

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Monitor your network for DDoS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pysnmp-mibs>=0.1.4:net-mgmt/py-pysnmp-mibs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysnmp>=4.2.3:net-mgmt/py-pysnmp@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
USES=		python:2.7
SUB_FILES=	pkg-message exaddos.sh exaddos.conf.sample
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}
NO_ARCH=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/lib

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
	@(cd ${WRKSRC}/data/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})
	${INSTALL_DATA} ${WRKDIR}/exaddos.conf.sample \
		${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
