# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zeronet
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.2
CATEGORIES=	security net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Decentralized websites using Bitcoin crypto and BitTorrent network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stem>0:security/py-stem@${PY_FLAVOR}

SUB_FILES=	zeronet-service zeronet-cmd pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} USER=${USER} GROUP=${GROUP}
PLIST_SUB=	USER=${USER} GROUP=${GROUP}

# ZeroNet hasn't been ported to Python 3 yet
# https://github.com/HelloZeroNet/ZeroNet/issues/149
USES=		python:2.7
USE_GITHUB=	yes
GH_ACCOUNT=	HelloZeroNet
GH_PROJECT=	ZeroNet
NO_ARCH=	yes

OPTIONS_DEFINE=	DEBUG

DEBUG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR}

.include <bsd.port.options.mk>

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
	@${RM} `${FIND} ${STAGEDIR}${DATADIR} -name "*.orig"`
	@${RM} `${FIND} ${STAGEDIR}${DATADIR} -name LICENSE`
	@${RM} ${STAGEDIR}${DATADIR}/README*.md ${STAGEDIR}${DATADIR}/CHANGELOG*.md ${STAGEDIR}${DATADIR}/requirements.txt
	@${RM} ${STAGEDIR}${DATADIR}/Vagrantfile ${STAGEDIR}${DATADIR}/Dockerfile
	@${RM} -r `${FIND} ${STAGEDIR}${DATADIR} -name test`
	@${MKDIR} ${STAGEDIR}/var/db/zeronet
	@${MKDIR} ${STAGEDIR}/var/log/zeronet
	@${LN} -s /var/db/zeronet ${STAGEDIR}${DATADIR}/data
	@${LN} -s /var/log/zeronet ${STAGEDIR}${DATADIR}/log
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-cmd ${STAGEDIR}${PREFIX}/bin/zeronet
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-service ${STAGEDIR}${PREFIX}/etc/rc.d/zeronet

.include <bsd.port.mk>
