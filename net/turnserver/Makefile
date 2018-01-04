# $FreeBSD$

PORTNAME=	turnserver
PORTVERSION=	4.5.0.7
CATEGORIES=	net
MASTER_SITES=	http://turnserver.open-sys.org/downloads/v${PORTVERSION}/:prog \
		http://turnserver.open-sys.org/downloads/extradocs/:xdocs \
		http://coturn.net/turnserver/v${PORTVERSION}/:prog \
		http://coturn.net/turnserver/extradocs/:xdocs
PKGNAMEPREFIX=
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:prog \
		turn.extra.docs-2.0.0.1.tar.gz:xdocs

MAINTAINER=	bhughes@FreeBSD.org
COMMENT=	STUN/TURN Server; IPv6, DTLS support; RFCs 5389, 5766, 6062, 6156

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		gettext-runtime perl5 shebangfix ssl
SHEBANG_FILES=	examples/scripts/restapi/shared_secret_maintainer.pl
HAS_CONFIGURE=	yes
CONFIGURE_ENV+=	PTHREAD_LIBS=-pthread TURN_DISABLE_RPATH=1
# MongoDB support is disabled until devel/mongo-c-driver is updated
CONFIGURE_ENV+=	TURN_NO_MONGO=1
TEST_TARGET=	test

SUB_FILES=	pkg-message
USE_RC_SUBR=	turnserver

MANPAGES=	turnserver.1 turnadmin.1 turnutils.1 turnutils_peer.1 \
		turnutils_stunclient.1 turnutils_uclient.1 coturn.1 \
		turnutils_oauth.1 turnutils_natdiscovery.1

DOCS=	html TurnNetworks.pdf
PORTREADMEDOCS=	LICENSE README.turnserver README.turnadmin README.turnutils INSTALL
PORTDOCS=	${DOCS} ${PORTREADMEDOCS} postinstall.txt schema.sql schema.mongo.sh \
		schema.userdb.redis schema.stats.redis

_BIN_UTILS=	peer stunclient uclient oauth natdiscovery

_ETC_EXAMPLES=	turnserver.conf turn_client_cert.pem \
		turn_client_pkey.pem turn_server_cert.pem turn_server_pkey.pem
_SCRIPT_EXAMPLES=	peer.sh	\
	basic/relay.sh basic/dos_attack.sh \
	basic/tcp_client_c2c_tcp_relay.sh basic/udp_c2c_client.sh \
	basic/udp_client.sh basic/tcp_client.sh \
	loadbalance/master_relay.sh loadbalance/slave_relay_1.sh loadbalance/slave_relay_2.sh \
	loadbalance/udp_c2c.sh loadbalance/tcp_c2c_tcp_relay.sh \
	longtermsecure/secure_dtls_client.sh longtermsecure/secure_relay.sh \
	longtermsecure/secure_tls_client_cert.sh longtermsecure/secure_dtls_client_cert.sh \
	longtermsecure/secure_relay_cert.sh \
	longtermsecure/secure_tcp_client_c2c_tcp_relay.sh longtermsecure/secure_tcp_client.sh \
	longtermsecure/secure_tls_client_c2c_tcp_relay.sh longtermsecure/secure_tls_client.sh \
	longtermsecure/secure_udp_c2c.sh longtermsecure/secure_udp_client.sh \
	longtermsecure/secure_sctp_client.sh \
	longtermsecure/secure_dos_attack.sh \
	longtermsecuredb/secure_relay_with_db_psql.sh \
	longtermsecuredb/secure_relay_with_db_mysql.sh \
	longtermsecuredb/secure_relay_with_db_mysql_ssl.sh \
	longtermsecuredb/secure_relay_with_db_mongo.sh \
	longtermsecuredb/secure_relay_with_db_redis.sh \
	longtermsecuredb/secure_relay_with_db_sqlite.sh \
	restapi/secure_relay_secret.sh \
	restapi/secure_relay_secret_with_db_mysql.sh \
	restapi/secure_relay_secret_with_db_psql.sh \
	restapi/secure_relay_secret_with_db_redis.sh \
	restapi/secure_relay_secret_with_db_mongo.sh \
	restapi/secure_relay_secret_with_db_sqlite.sh \
	restapi/secure_udp_client_with_secret.sh \
	restapi/secure_relay_secret_with_db_psql.sh \
	restapi/shared_secret_maintainer.pl \
	selfloadbalance/secure_dos_attack.sh \
	selfloadbalance/secure_relay.sh

OPTIONS_DEFINE=	DOCS EXAMPLES MYSQL PGSQL REDIS SQLITE
OPTIONS_DEFAULT=	MYSQL PGSQL REDIS SQLITE
OPTIONS_SUB=	yes

MYSQL_DESC=	MySQL database support
MYSQL_USES=	mysql
MYSQL_CONFIGURE_ENV_OFF=	TURN_NO_MYSQL=1

PGSQL_DESC=	PostgreSQL database support
PGSQL_USES=	pgsql
PGSQL_CONFIGURE_ENV_OFF=	TURN_NO_PQ=1

REDIS_DESC=	Redis support for user database and for status and statistics reporting
REDIS_LIB_DEPENDS=	libhiredis.so:databases/hiredis
REDIS_CONFIGURE_ENV_OFF=	TURN_NO_HIREDIS=1

SQLITE_DESC=	SQLite database support
SQLITE_USES=	sqlite
SQLITE_CONFIGURE_ENV_OFF=	TURN_NO_SQLITE=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/turnserver ${STAGEDIR}${PREFIX}/bin/turnserver
	${INSTALL_PROGRAM} ${WRKSRC}/bin/turnadmin ${STAGEDIR}${PREFIX}/bin/turnadmin
.for f in ${_BIN_UTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/turnutils_${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	(cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MANPAGES} \
		${STAGEDIR}${PREFIX}/man/man1)
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/turndb && ${INSTALL_DATA} schema.sql schema.userdb.redis \
		schema.stats.redis ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/turndb && ${INSTALL_SCRIPT} testredisdbsetup.sh schema.mongo.sh \
		testmongosetup.sh ${STAGEDIR}${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/lib/libturnclient.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/examples/etc/turnserver.conf \
		${STAGEDIR}${PREFIX}/etc/turnserver.conf.default
	${MKDIR} ${STAGEDIR}${PREFIX}/include/turn
	(cd ${WRKSRC}/include/turn && ${COPYTREE_SHARE} "client ns_turn_defs.h" \
		${STAGEDIR}${PREFIX}/include/turn)

do-install-SQLITE-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/var/db
	${INSTALL_DATA} ${WRKSRC}/sqlite/turndb ${STAGEDIR}${PREFIX}/var/db/turndb

do-install-EXAMPLES-on:
.for dir in basic loadbalance longtermsecure longtermsecuredb restapi selfloadbalance
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/scripts/${dir}
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/etc
	${INSTALL_MAN} ${WRKSRC}/examples/scripts/readme.txt \
		${STAGEDIR}${EXAMPLESDIR}/scripts
	(cd ${WRKSRC}/examples/etc && ${INSTALL_DATA} ${_ETC_EXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}/etc)
.for f in ${_SCRIPT_EXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/scripts/${f} \
		${STAGEDIR}${EXAMPLESDIR}/scripts/${f}
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/turndocs/docs && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTREADMEDOCS} ${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${PKGMESSAGE} ${STAGEDIR}${DOCSDIR}/postinstall.txt
	(cd ${WRKSRC}/turndb && ${INSTALL_DATA} schema.sql schema.mongo.sh \
		schema.userdb.redis schema.stats.redis ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
