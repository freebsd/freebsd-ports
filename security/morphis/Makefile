# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	morphis
PORTVERSION=	0.8.18.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	security net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Peer-to-peer high-performance distributed datastore and mail

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy11>0:databases/py-sqlalchemy11@${PY_FLAVOR}

USES=		python:3.4+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	yurivict
NO_ARCH=	yes
SHEBANG_FILES=	contrib/morphisd/opt/morphis/setargv

SUB_FILES=	morphis-service morphis-cmd pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} USER=${USER} GROUP=${GROUP}
PLIST_SUB=	USER=${USER} GROUP=${GROUP}

USER=		nobody
GROUP=		nobody

do-build:
	@(cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC})
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CP} -R ${WRKSRC}/* ${STAGEDIR}${DATADIR}/
	@cd ${STAGEDIR}${DATADIR} && ${RM} Makefile LICENSE README RUNNING TODO-*
	@${MKDIR} ${STAGEDIR}/var/db/morphis
	@${LN} -s /var/db/morphis ${STAGEDIR}${DATADIR}/data
	${INSTALL_SCRIPT} ${WRKDIR}/morphis-cmd ${STAGEDIR}${PREFIX}/bin/morphis
	${INSTALL_SCRIPT} ${WRKDIR}/morphis-service ${STAGEDIR}${PREFIX}/etc/rc.d/morphis

.include <bsd.port.mk>
