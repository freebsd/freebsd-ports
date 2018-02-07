# Created by: John Oxley <john@yoafrica.com>
# $FreeBSD$

PORTNAME=	vexim
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	mail www

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Web interface for managing virtual domains for exim

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

SUB_FILES=	pkg-message
NO_ARCH=	yes
NO_BUILD=	yes
USES=		gettext php
USE_PHP=	gettext session posix

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}2
GH_TAGNAME=	2f51492

OPTIONS_MULTI=		DB
OPTIONS_MULTI_DB=	MYSQL PGSQL
OPTIONS_DEFINE=		DOCS ORDER
OPTIONS_DEFAULT=	MYSQL

ORDER_DESC=		Sort userlist by localpart instead of realname
ORDER_EXTRA_PATCHES=	${FILESDIR}/extrapatch-order

MYSQL_USE=	php=pdo_mysql
PGSQL_USE=	php=pdo_pgsql

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MORDER}
post-patch:
	${RM} -rv ${WRKSRC}/vexim/*.orig
.endif

do-install:
	@${ECHO} "Installing in ${WWWDIR}:"
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC}/vexim && ${FIND} . \
		-type d -exec ${MKDIR} ${STAGEDIR}${WWWDIR}/{} \;  \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${WWWDIR}/{} \;
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/setup && ${FIND} . \
		-type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${FIND} docs \
		-type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
		-o -type f \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
.for i in README.md TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
