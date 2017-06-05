# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	morphis
PORTVERSION=	0.8.18.6
DISTVERSIONPREFIX=	v
CATEGORIES=	security net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Peer-to-peer high-performance distributed datastore and mail

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy11>0:databases/py-sqlalchemy11

USE_GITHUB=	yes
GH_ACCOUNT=	yurivict

SUB_FILES=	morphis-service morphis-cmd pkg-message
SUB_LIST=	LOCALBASE=${LOCALBASE} USER=${USER} GROUP=${GROUP}
PLIST_SUB=	USER=${USER} GROUP=${GROUP}

USES=		python:3.4+
NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && !defined(PACKAGE_BUILDING_FLAVORS) && \
    ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

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

.include <bsd.port.post.mk>
