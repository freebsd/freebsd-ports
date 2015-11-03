# Created by: Jeremy Johnston <jeremy@smart-serv.net>
# $FreeBSD$

PORTNAME=	tuptime
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.01
CATEGORIES=	sysutils

MAINTAINER=	jeremy@smart-serv.net
COMMENT=	Historical and statistical system running time report tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:${PORTSDIR}/databases/py-sqlite3

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	rfrail3

NO_BUILD=	yes
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	latest/tuptime
SUB_FILES=	pkg-message

PLIST_FILES=	bin/tuptime

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/latest/tuptime ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
