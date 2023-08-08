PORTNAME=	tuptime
DISTVERSION=	5.2.2
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jeremy@smart-serv.net
COMMENT=	Historical and statistical system running time report tool
WWW=		https://github.com/rfmoz/tuptime

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=2.7:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:run shebangfix
SHEBANG_FILES=	${WRKSRC}/src/tuptime
USE_GITHUB=	yes
GH_ACCOUNT=	rfmoz
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

USERS=         _tuptime
GROUPS=        _tuptime

PLIST_FILES=    bin/tuptime \
		"@rmtry /var/lib/tuptime/tuptime.db" \
		"@dir /var/lib" \
		"@dir(${USERS},${GROUPS},755) /var/lib/tuptime" \
		"@dir etc/cron.d" \
		"etc/cron.d/tuptime" \
		man/man1/tuptime.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/tuptime ${STAGEDIR}${PREFIX}/bin/tuptime
	${INSTALL_MAN} ${WRKSRC}/src/man/tuptime.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install:
	${MKDIR} ${STAGEDIR}/var/lib/tuptime
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/cron.d
	${INSTALL_DATA} ${FILESDIR}/cron ${STAGEDIR}${LOCALBASE}/etc/cron.d/tuptime

.include <bsd.port.mk>
