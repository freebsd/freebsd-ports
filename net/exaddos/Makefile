# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaddos
PORTVERSION=	0.4.0
CATEGORIES=	net
MASTER_SITES=	http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Monitor your network for DDoS

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snmp4-mibs>=0.1.4:net-mgmt/py-snmp4-mibs \
		${PYTHON_PKGNAMEPREFIX}snmp4>=4.2.3:net-mgmt/py-snmp4

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
USES=		python tar:tgz
SUB_FILES=	pkg-message exaddos.sh exaddos.conf.sample
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}

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
