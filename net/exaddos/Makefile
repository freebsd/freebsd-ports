# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	exaddos
PORTVERSION=	0.4.0
CATEGORIES=	net
MASTER_SITES=	GH GHC \
		http://mirrors.rit.edu/zi/
EXTRACT_SUFX=	.tgz

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Monitor your network for DDoS

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}snmp4-mibs>=0.1.4:${PORTSDIR}/net-mgmt/py-snmp4-mibs \
    		${PYTHON_PKGNAMEPREFIX}snmp4>=4.2.3:${PORTSDIR}/net-mgmt/py-snmp4

USE_GITHUB=	yes
GH_ACCOUNT=	Exa-Networks
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	4e93fc1
USES=		python
SUB_FILES=	pkg-message exaddos.sh exaddos.conf.sample
SUB_LIST=	PYTHON_LIBDIR=${PYTHON_LIBDIR} PYTHON_CMD=${PYTHON_CMD} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}
USE_RC_SUBR=	${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}/lib

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME} ${STAGEDIR}${ETCDIR}
	@(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR})
	@(cd ${WRKSRC}/data/${PORTNAME} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})
	@${INSTALL_DATA} ${WRKDIR}/exaddos.conf.sample \
		${STAGEDIR}${ETCDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
