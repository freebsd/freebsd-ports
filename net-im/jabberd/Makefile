# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jabberd
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	https://github.com/jabberd2/jabberd2/releases/download/${PORTNAME}-${DISTVERSION}/ \
		LOCAL/matthew/${PORTNAME}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Online presence and instant messaging server

LICENSE=	GPLv2

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libgsasl.so:security/gsasl \
		libidn.so:dns/libidn \
		libudns.so:dns/udns

OPTIONS_DEFINE=	MYSQL PGSQL LDAP BDB SQLITE PAM PIPE ANON FS DEBUG REQUIRES \
		DOCS SUPERSEDED EXPERIMENTAL
OPTIONS_DEFAULT=MYSQL DEBUG
OPTIONS_SUB=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		compiler:c11 iconv libtool perl5 ssl tar:xz
USE_PERL5=	run
USE_RC_SUBR=	jabberd
USE_LDCONFIG=	${PREFIX}/lib/jabberd
CONFIGURE_ARGS=	--localstatedir=/var \
		--sysconfdir=${PREFIX}/etc/jabberd \
		--enable-ssl --enable-mio=kqueue \
		--disable-tests \
		--with-sasl=gsasl \
		--with-extra-include-path="${LOCALBASE}/include ${EIP}" \
		--with-extra-library-path="${LOCALBASE}/lib ${ELP}"

JABBER_USER=	jabber
JABBER_GROUP=	jabber

USERS=		${JABBER_USER}
GROUPS=		${JABBER_GROUP}

JABBER_ETCDIR=	"${PREFIX}/etc/jabberd"
JABBER_RUNDIR=	"/var/jabberd"

PLIST_SUB+=	JABBER_USER=${JABBER_USER} \
		JABBER_GROUP=${JABBER_GROUP} \
		JABBER_ETCDIR="${JABBER_ETCDIR}" \
		JABBER_RUNDIR="${JABBER_RUNDIR}"

SUB_LIST+=	JABBER_USER=${JABBER_USER} \
		JABBER_RUNDIR="${JABBER_RUNDIR}" \
		PERL="${PERL}"

PORTDOCS=	*

DOCFILES=	AUTHORS ChangeLog NEWS README README.config \
		README.protocol TODO

_REQUIRE=	LOGIN

ELP+=	${OPENSSLLIB}
EIP+=	${OPENSSLINC}

DEBUG_CONFIGURE_ENABLE=	debug

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	pgsql

SQLITE_CONFIGURE_ENABLE=sqlite
SQLITE_LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

MYSQL_USE=		MYSQL=yes
MYSQL_CONFIGURE_ENABLE=	mysql

BDB_USES=		bdb
BDB_CONFIGURE_ENABLE=	db
BDB_CONFIGURE_ON=	--oldincludedir=/nonexistant

LDAP_USE=		OPENLDAP=yes
LDAP_CONFIGURE_ENABLE=	ldap

FS_CONFIGURE_ENABLE=	fs
FS_DESC=		Filesystem storage (only for testing)

PAM_CONFIGURE_ENABLE=	pam

PIPE_CONFIGURE_ENABLE=	pipe
PIPE_DESC=		Enable pipe (auth/reg)

ANON_CONFIGURE_ENABLE=	anon
ANON_DESC=		Enable anonymous (auth/reg)

SUPERSEDED_CONFIGURE_ENABLE=	superseded
SUPERSEDED_DESC=	Enable superseded features (ns_TIME)

EXPERIMENTAL_CONFIGURE_ENABLE=	experimental
EXPERIMENTAL_DESC=	Enable experimental features (TLS-Everywhere)

.include <bsd.port.options.mk>

.if (${OPSYS} != FreeBSD || ${OSVERSION} < 1000000)
WITH_OPENSSL_PORT=	yes
.endif

.if ${PORT_OPTIONS:MPGSQL}
_REQUIRE+=		postgresql
.endif

.if ${PORT_OPTIONS:MMYSQL}
EIP+=${LOCALBASE}/include/mysql
ELP+=${LOCALBASE}/lib/mysql
_REQUIRE+=	mysql
.endif

.if ${PORT_OPTIONS:MBDB}
EIP+=${BDB_INCLUDE_DIR}
ELP+=${BDB_LIB_DIR}
.endif

.if ${PORT_OPTIONS:MLDAP}
_REQUIRE+=	slapd
.endif

.if ${PORT_OPTIONS:MREQUIRES}
SUB_LIST+=	REQUIRE="${_REQUIRE}"
.else
SUB_LIST+=	REQUIRE="LOGIN"
.endif
REQUIRES_DESC=	Add backend requires to startup script

post-patch:
.for FILE in c2s.xml jabberd.cfg router-filter.xml router-users.xml \
	router.xml s2s.xml sm.xml templates/roster.xml
	@${MV} ${WRKSRC}/etc/${FILE}.dist.in ${WRKSRC}/etc/${FILE}.sample.in
.endfor
#.if ${PORT_OPTIONS:MCYRUS}
#	@${REINPLACE_CMD} -e '/^#error /d' \
#		${WRKSRC}/sx/sasl_cyrus.c
#.endif

post-install:
.for DIR in db logs pid
	@${MKDIR} ${STAGEDIR}${JABBER_RUNDIR}/${DIR}
.endfor
	@${CHMOD} -R go= ${STAGEDIR}${JABBER_RUNDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.for FILE in db-setup.mysql db-setup.pgsql db-setup.sqlite
	${INSTALL_DATA} ${WRKSRC}/tools/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
