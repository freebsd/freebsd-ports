PORTNAME=	caldera-ot
DISTVERSION=	4.2.0
PORTREVISION=	1
CATEGORIES=	security python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	caldera OT plugin and capabilities
WWW=		https://github.com/mitre/caldera-ot

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bacnet-stack>0:devel/bacnet-stack \
		nuitka3:devel/nuitka
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymodbus>0:comms/py-pymodbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${LOCALBASE}/www/caldera/app/__init__.py:security/caldera

USE_GITHUB=	yes
GH_ACCOUNT=	mitre
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	6c6b971d96de121da33f27aa6f80806835346b23
GH_TUPLE=	mitre:bacnet:745432c:bacnet/bacnet \
		mitre:dnp3:01e3748:dnp3/dnp3 \
		mitre:modbus:e47e259:modbus/modbus

USES=		compiler:c++11-lang dos2unix python

DOS2UNIX_REGEX= .*\.([yml])
CALDERA_USER=	caldera
CALDERA_GROUP=	caldera
USERS=		${CALDERA_USER}
GROUPS=		${CALDERA_GROUP}

WWWDIR=		${PREFIX}/www/caldera

SUB_FILES=	pkg-message
SUB_LIST=	WWWDIR=${WWWDIR}

post-extract:
	${RM} -R ${WRKSRC}/.github
	cd ${WRKSRC} && ${RM} -f .coveragerc .dockerignore .eslintrc.js .flake8 \
		.git* .pre* .stylelintrc.json Dockerfile

post-patch:
	${REINPLACE_CMD} -i "" -e 's|.sync|.tcp|g' ${WRKSRC}/modbus/src/src/modbus/client.py
	cd ${WRKSRC} && \
		${FIND} . -type f -name "*.orig" -exec ${RM} "{}" \;

do-build:
	@${MKDIR} ${WRKDIR}/modbus_cli-build
	cd ${WRKSRC}/bacnet/src/bacnet-stack/apps && \
		${CC} readprop/main.c -I${LOCALBASE}/include -L${LOCALBASE}/lib \
			-lbacnet-stack -o ${WRKSRC}/bacnet/payloads/bacrp-freebsd
	cd ${WRKSRC}/bacnet/src/bacnet-stack/apps && \
		${CC} readprop/main.c -I${LOCALBASE}/include -L${LOCALBASE}/lib \
			-lbacnet-stack -o ${WRKSRC}/bacnet/payloads/bacwp-freebsd
	cd ${WRKSRC}/modbus/src/src && \
		${LOCALBASE}/bin/nuitka3 --standalone --onefile \
		--output-filename=modbus_cli-freebsd --output-dir=${WRKDIR}/modbus_cli-build modbus_cli.py

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}/plugins/bacnet
	@${MKDIR} ${STAGEDIR}${WWWDIR}/plugins/dnp3
	@${MKDIR} ${STAGEDIR}${WWWDIR}/plugins/modbus
	@cd ${WRKSRC}/bacnet && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/plugins/bacnet
	@cd ${WRKSRC}/dnp3 && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/plugins/dnp3
	@cd ${WRKSRC}/modbus && ${COPYTREE_SHARE} . ${STAGEDIR}/${WWWDIR}/plugins/modbus
	${INSTALL_PROGRAM} ${WRKDIR}/modbus_cli-build/modbus_cli-freebsd \
		${STAGEDIR}/${WWWDIR}/plugins/modbus/payloads/

.include <bsd.port.mk>
