# Created by: nbm
# $FreeBSD$

PORTNAME=	roundup
PORTVERSION=	1.5.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Issue-Tracking System for Knowledge Workers

LICENSE=	PSFL

USES=		cpe gettext python
CPE_VENDOR=	roundup-tracker
USE_PYTHON=	distutils

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL NLS
OPTIONS_DEFAULT=SQLITE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>0:databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

SCRIPTS=	roundup-admin roundup-demo roundup-gettext roundup-mailgw \
		roundup-server roundup-xmlrpc-server

post-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/build/scripts-${PYTHON_VER}/,} ${STAGEDIR}${PREFIX}/bin
.for f in roundup-admin roundup-demo roundup-mailgw roundup-server
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/${f}.1 ${STAGEDIR}${PREFIX}/man/man1
.endfor
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/build/share/locale/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/locale/)
.endif

.include <bsd.port.mk>
