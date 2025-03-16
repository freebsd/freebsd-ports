PORTNAME=	NotiMail
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	mail python

MAINTAINER=	stefano@dragas.it
COMMENT=	Server-side email notification manager with push support
WWW=		https://github.com/draga79/NotiMail

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}configparser>0:devel/py-configparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	draga79
USE_RC_SUBR=	notimail
SHEBANG_FILES=	NotiMail.py

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/NotiMail.py ${STAGEDIR}${PREFIX}/bin/notimail
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/notimail
	${INSTALL_DATA} ${WRKSRC}/config.ini.sample ${STAGEDIR}${PREFIX}/etc/notimail/config.ini.sample
	${INSTALL_MAN} ${WRKSRC}/man/notimail.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${MKDIR} ${STAGEDIR}/var/cache/notimail
	${MKDIR} ${STAGEDIR}/var/log/notimail

.include <bsd.port.mk>
