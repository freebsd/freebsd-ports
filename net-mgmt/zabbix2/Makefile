# Ports collection makefile for:	zabbix
# Date created:		Jun 18 2003
# Whom:			Sergey Akifyev <asa@gascom.ru>
#
# $FreeBSD$
#

PORTNAME=	zabbix
PORTVERSION=	1.4.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application and network monitoring solution

LIB_DEPENDS=	netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp \
		iksemel.3:${PORTSDIR}/textproc/iksemel \
		curl.4:${PORTSDIR}/ftp/curl

OPTIONS=	MYSQL "Use MySQL backend" on \
		PGSQL "Use PostgreSQL backend" off \
		SQLITE "Use SQLite backend" off \
		LDAP "Support for checking LDAP servers" on \
		FPING "Use fping for pinging hosts" on

USE_GMAKE=	yes
USE_PHP=	gd snmp sockets pcre bcmath
USE_RC_SUBR=	zabbix_server.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-agent --enable-server \
		--with-net-snmp=${LOCALBASE}/bin/net-snmp-config \
		--with-curl=${LOCALBASE}/bin/curl-config \
		--with-jabber=${LOCALBASE}
MAKE_ARGS=	ARCH=freebsd
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.ifndef WITHOUT_LDAP
USE_OPENLDAP=	yes
CONFIGURE_ARGS+=--with-ldap=${LOCALBASE}
LIB_DEPENDS+=	gnutls.13:${PORTSDIR}/security/gnutls \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif
.ifndef WITHOUT_FPING
RUN_DEPENDS+=	fping:${PORTSDIR}/net/fping
.endif
.ifndef WITHOUT_MYSQL
USE_MYSQL=	yes
USE_PHP+=	mysql
CONFIGURE_ARGS+=--with-mysql=${LOCALBASE}/bin/mysql_config
.elifdef WITH_PGSQL
USE_PGSQL=	yes
USE_PHP+=	pgsql
CONFIGURE_ARGS+=--with-pgsql=${LOCALBASE}/bin/pg_config
.elifdef WITH_SQLITE
USE_SQLITE=	yes
USE_PHP+=	sqlite
CONFIGURE_ARGS+=--with-sqlite=${LOCALBASE}
.else
IGNORE=	zabbix needs a database backend
.endif

post-patch:
	@${FIND} ${WRKSRC}/src/ -type f|${XARGS} \
		${REINPLACE_CMD} -Ee 's|(/etc/zabbix)|${PREFIX}\1|;s|/usr/sbin|${LOCALBASE}/sbin|'
	@${REINPLACE_CMD} -e '/test.*rf/s|-rf|-f|;/LDFLAGS/s|-static||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^SDI.*pg_connection_string/d' ${WRKSRC}/frontends/php/include/db.inc.php
.ifdef WITHOUT_FPING
	@${ECHO} 'DisablePinger=yes' >> ${WRKSRC}/misc/conf/zabbix_server.conf
.endif

.if ${ARCH} == "amd64"
post-configure:
	${ECHO_CMD} "#define HAVE_VA_COPY 1" >> ${WRKSRC}/include/config.h
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/zabbix_server/zabbix_server ${PREFIX}/bin/
	@${INSTALL} -d ${PREFIX}/etc/zabbix/ ${DATADIR}/create/
	@${INSTALL_DATA} ${WRKSRC}/misc/conf/zabbix_server.conf\
		${PREFIX}/etc/zabbix/zabbix_server.conf.sample
	@${CP} -Rf ${WRKSRC}/frontends/ ${WRKSRC}/upgrades/dbpatches ${DATADIR}/
	@${CP} -Rf ${WRKSRC}/create/data ${WRKSRC}/create/schema ${DATADIR}/create/
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
