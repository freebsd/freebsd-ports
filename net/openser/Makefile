# Created by: jesusr
# $FreeBSD$

PORTNAME=	openser
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://openser.org/pub/openser/${PORTVERSION}/src/
DISTNAME=	${PORTNAME}-${PORTVERSION}-tls_src

MAINTAINER=	jesusr@FreeBSD.org
COMMENT=	Fast and configurable SIP proxy with TLS support

LIB_DEPENDS=	radiusclient-ng.2:${PORTSDIR}/net/radiusclient

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-tls

USE_GMAKE=	yes
USE_GNOME=	libxml2
MAKE_ENV=	CC_EXTRA_OPTS="${CFLAGS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST_FILES=	sbin/openser sbin/openserctl sbin/openserunix \
		lib/openser/openserctl/openserctl.base lib/openser/openserctl/openserctl.ctlbase \
		lib/openser/openserctl/openserctl.fifo lib/openser/openserctl/openserctl.sqlbase \
		lib/openser/openserctl/openserctl.unixsock \
		etc/openser/openserctlrc

PLIST_DIRS=	lib/openser/modules lib/openser/openserctl lib/openser

MODULES=	acc alias_db auth auth_db avpops cpl-c dbtext \
		dialog dispatcher diversion domain domainpolicy enum exec flatstore \
		gflags group imc lcr mangler maxfwd mediaproxy mi_fifo msilo \
		nathelper options pa path pdt permissions pike \
		registrar rr siptrace sl sms speeddial sst statistics \
		textops tm uac uac_redirect uri \
		uri_db usrloc xlog

RC_FILES=	acc/radiusclient.conf \
		acc/servers \
		dictionary.radius \
		openser.cfg
RC_DIRS=	acc

ONLY_FOR_ARCHS=	i386

MAN5=		openser.cfg.5
MAN8=		openser.8 \
		openserctl.8 \
		openserunix.8

PORTDOCS=	*

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST=	RC_DIRS="${RC_DIRS}" RC_FILES="${RC_FILES}"

OPTIONS_DEFINE=	MYSQL PGSQL UNIXODBC TLS SNMPSTATS AUTHRADIUS
OPTIONS_DEFAULT=	MYSQL
SNMPSTATS_DESC=		SNMPStats support
AUTHRADIUS_DESC=	auth_radius module

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
MODULES+=	mysql
PLIST_FILES+=	lib/openser/openserctl/openserctl.mysql sbin/openser_mysql.sh
.else
MAKE_ENV+=	MYSQL=mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
MODULES+=	postgres
PLIST_FILES+=	lib/openser/openserctl/openserctl.pgsql sbin/openser_postgresql.sh
.else
MAKE_ENV+=	PGSQL=postgres
.endif

.if ${PORT_OPTIONS:MUNIXODBC}
LIB_DEPENDS+=	odbc.2:${PORTSDIR}/databases/unixODBC
MODULES+=	unixodbc
.else
MAKE_ENV+=	UNIXODBC=unixodbc
.endif

.if ${PORT_OPTIONS:MTLS}
MODULES+=	tlsops
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
TLS_RC_FILES=	tls/rootCA/cacert.pem \
		tls/rootCA/certs/01.pem \
		tls/rootCA/index.txt \
		tls/rootCA/private/cakey.pem \
		tls/rootCA/serial \
		tls/user/user-calist.pem \
		tls/user/user-cert.pem \
		tls/user/user-cert_req.pem \
		tls/user/user-privkey.pem \
		tls/README \
		tls/ca.conf \
		tls/request.conf \
		tls/user.conf
RC_FILES+=	${TLS_RC_FILES}
TLS_RC_DIRS=	tls/user \
		tls/rootCA/certs \
		tls/rootCA/private \
		tls/rootCA \
		tls
RC_DIRS+=	${TLS_RC_DIRS}
.else
MAKE_ENV+=	TLSOPS=tlsops
MAKE_ARGS+=	TLS=""
.endif

.if ${PORT_OPTIONS:MSNMPSTATS}
RUN_DEPENDS+=	snmpcheck:${PORTSDIR}/net-mgmt/net-snmp
MODULES+=	snmpstats
.else
MAKE_ENV+=	SNMPSTATS=snmpstats
.endif

.if ${PORT_OPTIONS:MAUTHRADIUS}
MODULES+=	auth_radius
PLIST_FILES+=	lib/openser/modules/auth_radius.so
.else
MAKE_ENV+=	AUTHRADIUS=auth_radius
.endif

PLIST_FILES+=	${MODULES:S|^|lib/openser/modules/|:S|$|.so|} \
		${RC_FILES:S|^|etc/openser/|:S|$|.default|}

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's|install-doc install-man|install-man|' \
		${WRKSRC}/Makefile
.endif
	@${REINPLACE_CMD} -e 's|-g -O9 ||' -e 's|-O9 ||' ${WRKSRC}/Makefile.defs
	@${REINPLACE_CMD} -e 's|/usr/local/etc/ser|${PREFIX}/etc/openser|' \
		${WRKSRC}/scripts/sc.dbtext \
		${WRKSRC}/modules/dispatcher/README
	@${REINPLACE_CMD} -e 's|/etc/openser|${PREFIX}/etc/openser|' \
		${WRKSRC}/modules/mediaproxy/README \
		${WRKSRC}/modules/cpl-c/README \
		${WRKSRC}/INSTALL
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/etc/openser.cfg \
		${WRKSRC}/scripts/mysqldb.sh \
		${WRKSRC}/scripts/postgresqldb.sh \
		${WRKSRC}/scripts/sc.dbtext \
		${WRKSRC}/modules/speeddial/README
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/modules/acc/etc/radiusclient.conf
	@${REINPLACE_CMD} -e 's|/usr/local/etc/radiusclient|${PREFIX}/etc/openser/acc|' \
		${WRKSRC}/modules/acc/acc_mod.c ${WRKSRC}/modules/acc/README

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/openser.cfg \
		${PREFIX}/etc/openser/openser.cfg.default
	${MKDIR} ${PREFIX}/etc/openser/acc
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/radiusclient.conf \
		${PREFIX}/etc/openser/acc/radiusclient.conf.default
	${INSTALL_DATA} ${WRKSRC}/modules/acc/etc/servers \
		${PREFIX}/etc/openser/acc/servers.default
.for d in ${TLS_RC_DIRS}
	${MKDIR} ${PREFIX}/etc/openser/${d}
.endfor
.for f in ${TLS_RC_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${f} ${PREFIX}/etc/openser/${f}.default
.endfor
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
