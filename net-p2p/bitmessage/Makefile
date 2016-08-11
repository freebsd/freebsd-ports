# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bitmessage
PORTVERSION=	0.6.0
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

USES=		python pyqt:4
NATIVE_POW_USES=gmake
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NATIVE_POW
OPTIONS_DEFAULT=NATIVE_POW
NATIVE_POW_DESC=Native POW procedure
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|python2|${PYTHON_CMD}| ; s|share/man|man|' ${WRKSRC}/Makefile

do-build:
	@(cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC})
.if ${PORT_OPTIONS:MNATIVE_POW}
	@(cd ${WRKSRC} && \
		${ECHO_MSG} "===>  Compiling the proof-of-work (POW) routine" && \
		(cd src/bitmsghash && ${MAKE_CMD}))
.endif

post-install:
.if ${PORT_OPTIONS:MNATIVE_POW}
	@${RM} ${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.o
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/share/pybitmessage/bitmsghash/bitmsghash.so
.endif

.include <bsd.port.mk>
