# Created by: nbm
# $FreeBSD$

PORTNAME=	roundup
PORTVERSION=	1.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Issue-Tracking System for Knowledge Workers

LICENSE=	PSFL
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		cpe gettext python:2.7
CPE_VENDOR=	roundup-tracker
USE_PYTHON=	distutils
NO_ARCH=	yes

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL NLS
OPTIONS_DEFAULT=SQLITE
OPTIONS_SUB=	yes

SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>0:databases/py-MySQLdb@${FLAVOR}

SCRIPTS=	roundup-admin roundup-demo roundup-gettext roundup-mailgw \
		roundup-server roundup-xmlrpc-server

post-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/build/scripts-${PYTHON_VER}/,} ${STAGEDIR}${PREFIX}/bin
.for f in roundup-admin roundup-demo roundup-mailgw roundup-server
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/${f}.1 ${STAGEDIR}${MANPREFIX}/man/man1
.endfor

post-install-NLS-on:
	@(cd ${WRKSRC}/build/share/locale/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/locale/)

.include <bsd.port.mk>
