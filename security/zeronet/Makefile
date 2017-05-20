# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	zeronet
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	v
CATEGORIES=	security net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Decentralized websites using Bitcoin crypto and BitTorrent network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}gevent>=1.0.2:devel/py-gevent \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3

USE_GITHUB=	yes
GH_ACCOUNT=	HelloZeroNet
GH_PROJECT=	ZeroNet

SUB_FILES=	zeronet-service zeronet-cmd pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} USER=${USER} GROUP=${GROUP}
PLIST_SUB=	USER=${USER} GROUP=${GROUP}

USES=		python
NO_ARCH=	yes

OPTIONS_DEFINE=	TOR DEBUG
TOR_DESC=	Enable TOR anonymity network integration

TOR_RUN_DEPENDS=	tor:security/tor
DEBUG_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTOR}
USER=		_tor
GROUP=		_tor
.else
USER=		nobody
GROUP=		nobody
.endif

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
	@${RM} ${STAGEDIR}${DATADIR}/README*.md ${STAGEDIR}${DATADIR}/CHANGELOG.md ${STAGEDIR}${DATADIR}/requirements.txt
	@${RM} ${STAGEDIR}${DATADIR}/Vagrantfile ${STAGEDIR}${DATADIR}/Dockerfile
	@${RM} -r `${FIND} ${STAGEDIR}${DATADIR} -name test`
	@${MKDIR} ${STAGEDIR}/var/db/zeronet
	@${MKDIR} ${STAGEDIR}/var/log/zeronet
	@${LN} -s /var/db/zeronet ${STAGEDIR}${DATADIR}/data
	@${LN} -s /var/log/zeronet ${STAGEDIR}${DATADIR}/log
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-cmd ${STAGEDIR}${PREFIX}/bin/zeronet
	${INSTALL_SCRIPT} ${WRKDIR}/zeronet-service ${STAGEDIR}${PREFIX}/etc/rc.d/zeronet

.include <bsd.port.mk>
