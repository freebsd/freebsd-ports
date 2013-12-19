# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cjc
PORTVERSION=	1.2.1
CATEGORIES=	net-im python
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console Jabber Client

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyxmpp>=1.1.0:${PORTSDIR}/net-im/py-pyxmpp

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	Jajcus

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		shebangfix
SHEBANG_FILES=	cjc.in cjc.py cjc/main.py
USE_PYTHON=	2

post-patch:
	@${REINPLACE_CMD} -e \
		"s|prefix=.*|prefix=${PREFIX}| ; \
		 /^DOCS/s|COPYING|| ; \
		 s|INSTALL=.*|INSTALL=${INSTALL}| ; \
		 s|INSTALL_DATA=.*|INSTALL_DATA=${INSTALL_DATA}| ; \
		 s|INSTALL_DIR=.*|INSTALL_DIR=${MKDIR}|g ; \
		 /compileall/d" ${WRKSRC}/Makefile

post-install:
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${DATADIR_REL})

.include <bsd.port.mk>
