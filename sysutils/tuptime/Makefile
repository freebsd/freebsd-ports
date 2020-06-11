# $FreeBSD$

PORTNAME=	tuptime
DISTVERSION=	5.0.0
CATEGORIES=	sysutils

MAINTAINER=	jeremy@smart-serv.net
COMMENT=	Historical and statistical system running time report tool

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:run shebangfix
SHEBANG_FILES=	${WRKSRC}/src/tuptime
USE_GITHUB=	yes
GH_ACCOUNT=	rfrail3
USE_RC_SUBR=	${PORTNAME}

NO_BUILD=	yes
NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	bin/tuptime \
		man/man1/tuptime.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tuptime ${STAGEDIR}${PREFIX}/bin/tuptime
	${INSTALL_MAN} ${WRKSRC}/src/man/tuptime.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
