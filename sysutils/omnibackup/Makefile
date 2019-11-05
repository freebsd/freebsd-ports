# Created by: Mohammad S. Babaei <info@babaei.net>
# $FreeBSD$

PORTNAME=	omnibackup
PORTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	info@babaei.net
COMMENT=	One Script to back them all up

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	DOCS \
	OPENLDAP \
	PGSQL \
	MYSQL
OPTIONS_DEFAULT=	\
	DOCS \
	OPENLDAP \
	PGSQL \
	MYSQL

OPENLDAP_DESC=	OpenLDAP support

NO_ARCH=	yes
NO_BUILD=	yes
RUN_DEPENDS+=	\
	bash:shells/bash \
	flock:sysutils/flock \
	jq:textproc/jq

SUB_FILES=	pkg-message
SUB_LIST=	ROOT_HOME=/root

PLIST_FILES=	\
	bin/omnibackup \
	${ETCDIR}/config.json.sample

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	${DOCSDIR}/README.md
.endif

.if ${PORT_OPTIONS:MOPENLDAP} \
	|| ${PORT_OPTIONS:MPGSQL} \
	|| ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	sudo:security/sudo
.if ${PORT_OPTIONS:MOPENLDAP}
RUN_DEPENDS+=	slapcat:net/openldap24-server
.endif
.if ${PORT_OPTIONS:MPGSQL}
USES+=	pgsql
RUN_DEPENDS+=	pg_dump:databases/postgresql${PGSQL_VER_NODOT}-client
RUN_DEPENDS+=	pg_dumpall:databases/postgresql${PGSQL_VER_NODOT}-client
.endif
.if ${PORT_OPTIONS:MMYSQL}
USES+=	mysql
RUN_DEPENDS+=	mysqldump:${_MYSQL_CLIENT}
.endif
.endif

USE_GITHUB=	yes
GH_ACCOUNT=	NuLL3rr0r

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/backup.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/config.json.sample ${STAGEDIR}${ETCDIR}/config.json.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
