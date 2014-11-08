# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	bitmessage
PORTVERSION=	0.4.4
CATEGORIES=	net-p2p
MASTER_SITES=	GH

MAINTAINER=	yuri@rawbw.com
COMMENT=	Secure P2P communications client

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-core>=${PYQT4_VERSION}:${PORTSDIR}/devel/py-qt4-core \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=${PYQT4_VERSION}:${PORTSDIR}/x11-toolkits/py-qt4-gui

USE_GITHUB=	yes
GH_ACCOUNT=	Bitmessage
GH_PROJECT=	PyBitmessage
GH_COMMIT=	c9c301a
GH_TAGNAME=	v${PORTVERSION}

USES=		python
USE_OPENSSL=	yes
INSTALLS_ICONS=	yes

post-patch:
	${REINPLACE_CMD} -e 's|python2|${PYTHON_CMD}|' ${WRKSRC}/Makefile

do-build:
	@(cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC} && \
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${WRKSRC} -f ${WRKSRC})

.include <bsd.port.mk>
