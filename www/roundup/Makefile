# Created by: nbm
# $FreeBSD$

PORTNAME=	roundup
PORTVERSION=	1.4.21
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Issue-Tracking System for Knowledge Workers

LICENSE=	PSFL

USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	SQLITE PGSQL MYSQL NLS
OPTIONS_DEFAULT=SQLITE NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psycopgmodule.so:${PORTSDIR}/databases/py-psycopg
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		roundup-admin.1 roundup-demo.1 roundup-mailgw.1 \
		roundup-server.1
MANCOMPRESSED=	no
.endif

SCRIPTS=	roundup-admin roundup-demo roundup-gettext roundup-mailgw \
		roundup-server roundup-xmlrpc-server

post-install:
	@${INSTALL_SCRIPT} ${SCRIPTS:S,^,${WRKSRC}/build/scripts-${PYTHON_VER}/,} ${PREFIX}/bin
.if !defined(NO_INSTALL_MANPAGES)
	@${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/share/man/man1/,} ${MAN1PREFIX}/man/man1
.endif
.if ${PORT_OPTIONS:MNLS}
	@(cd ${WRKSRC}/build/share/locale/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/locale/)
.endif

.include <bsd.port.mk>
