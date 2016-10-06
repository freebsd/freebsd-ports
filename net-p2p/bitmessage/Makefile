# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bitmessage
PORTVERSION=	0.6.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-p2p

MAINTAINER=	yuri@rawbw.com
COMMENT=	Secure P2P communications client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-network>=${PYQT4_VERSION}:net/py-qt4-network \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:x11-toolkits/py-qt4-gui

USE_GITHUB=	yes
GH_ACCOUNT=	Bitmessage
GH_PROJECT=	PyBitmessage

USES=		python pyqt:4 ssl
NATIVE_POW_USES=gmake
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NATIVE_POW
OPTIONS_DEFAULT=NATIVE_POW
NATIVE_POW_DESC=Native POW procedure
OPTIONS_SUB=	yes
REINPLACE_ARGS=	-i ''

post-patch:
	@${REINPLACE_CMD} -e 's|python2|${PYTHON_CMD}| ; s|share/man|man|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|\((CCFLAGS)\)|\1 -I${OPENSSLINC} |g" \
		-e "s|\(-lcrypto\)|-L${OPENSSLLIB} \1|g" \
		${WRKSRC}/src/bitmsghash/Makefile
	@${REINPLACE_CMD} -e 's|python2|${PYTHON_CMD}| ; s|share/man|man|' ${WRKSRC}/Makefile ${WRKSRC}/src/depends.py
	@${REINPLACE_CMD} -e 's|^#!.*$$|#!${PYTHON_CMD}|' \
		${WRKSRC}/compiletest.py ${WRKSRC}/src/bitmessagecli.py ${WRKSRC}/src/bitmessagemain.py \
		${WRKSRC}/src/depends.py \
		${WRKSRC}/src/bitmessageqt/migrationwizard.py ${WRKSRC}/src/bitmessageqt/newaddresswizard.py \
		${WRKSRC}/src/bitmessageqt/settingsmixin.py ${WRKSRC}/src/helper_msgcoding.py ${WRKSRC}/src/openclpow.py

do-build:
	@(cd ${WRKSRC} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC} -f ${WRKSRC} && \
		${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
			-d ${WRKSRC} -f ${WRKSRC})

do-build-NATIVE_POW-on:
	@(cd ${WRKSRC} && \
		${ECHO_MSG} "===>  Compiling the proof-of-work (POW) routine" && \
		(cd src/bitmsghash && ${MAKE_CMD}))

post-install:
	@${RM}	${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/Makefile \
		${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.cpp \
		${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.cl

post-install-NATIVE_POW-on:
	@${RM} ${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.o
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.so

.include <bsd.port.mk>
