PORTNAME=	howdy
PORTVERSION=	3.0.0.b.20230306
PORTREVISION=	2
CATEGORIES=	security

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Windows Hello(TM) style authentication provider
WWW=		https://github.com/boltgolt/howdy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	opencv>0:graphics/opencv \
		${PYTHON_PKGNAMEPREFIX}python-pam>0:security/py-python-pam@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dlib>0:science/py-dlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR} \
		${LOCALBASE}/share/dlib-models/shape_predictor_5_face_landmarks.dat:misc/dlib-models

USES=		python:run shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	boltgolt
GH_PROJECT=	howdy
GH_TAGNAME=	30728a6d36

SHEBANG_GLOB=	*.py

NO_BUILD=	yes
NO_ARCH=	yes
STRIP=

post-patch:
	${ECHO_CMD} 'config_dir = "${ETCDIR}"' >> ${WRKSRC}/howdy/src/paths.py
	${ECHO_CMD} 'dlib_data_dir = "${LOCALBASE}/share/dlib-models/"' >> ${WRKSRC}/howdy/src/paths.py
	${ECHO_CMD} 'user_models_dir = "/var/db/howdy/models/"' >> ${WRKSRC}/howdy/src/paths.py

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/howdy
	cd ${WRKSRC}/howdy/src/ && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/libexec/howdy
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MV} ${STAGEDIR}${PREFIX}/libexec/howdy/config.ini ${STAGEDIR}${ETCDIR}/config.ini.sample
	${LN} -s ../libexec/howdy/cli.py ${STAGEDIR}${PREFIX}/bin/howdy
	${INSTALL_PROGRAM} ${WRKSRC}/howdy/src/cli.py ${STAGEDIR}${PREFIX}/libexec/howdy

	${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions
	${INSTALL_DATA}  ${WRKSRC}/howdy/src/autocomplete/howdy ${STAGEDIR}${PREFIX}/share/bash-completion/completions/

	${RM} -r ${STAGEDIR}${PREFIX}/libexec/howdy/autocomplete
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/howdy/dlib-data
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/howdy/pam
	${RM} -r ${STAGEDIR}${PREFIX}/libexec/howdy/pam-config

.include <bsd.port.mk>
