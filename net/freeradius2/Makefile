# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION?=	1.1.5
PORTREVISION?=	0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		ftp://ftp.ntua.gr/pub/net/radius/freeradius/ \
		ftp://ftp.uk.freeradius.org/pub/radius/ \
		ftp://ftp.us.freeradius.org/pub/radius/ \
		ftp://ftp.freeradius.org/pub/radius/old/ \
		http://freeradius.portal-to-web.de/

MAINTAINER?=	david@wood2.org.uk
COMMENT?=	A free RADIUS server implementation

USE_BZIP2=	yes

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

LOGDIR?=	/var/log

# If FREERADIUS_SLAVE_MYSQL is defined, we want to build the
# freeradius-mysql slave port

CONFLICTS=	gnu-radius-1.* openradius-0.* radiusd-cistron-1.*
.ifdef(FREERADIUS_SLAVE_MYSQL)
CONFLICTS+=	freeradius-1.*
PKGNAMESUFFIX=	-mysql
.else
CONFLICTS+=	freeradius-mysql-1.*
.endif

USE_RC_SUBR=	radiusd.sh
USE_AUTOTOOLS=	libltdl:15 libtool:15
USE_GMAKE=	yes
USE_OPENSSL=	yes
MAKE_ARGS+=	LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS=	KERBEROS	"With Kerberos support" off \
		HEIMDAL		"With Heimdal Kerberos support" off \
		LDAP		"With LDAP database support" off
.ifndef(FREERADIUS_SLAVE_MYSQL)
OPTIONS+=	MYSQL		"With MySQL database support" off
.endif
OPTIONS+=	PGSQL		"With PostgreSQL database support" off \
		FIREBIRD	"With Firebird database support (EXPERIMENTAL)" off \
		SNMP		"With SNMP support" off \
		EDIR		"With Novell eDirectory support" off \
		NOPERL		"Do not require perl (use only if necessary)" off \
		EXPERIMENTAL	"Build experimental modules" off

.include <bsd.port.pre.mk>

# Default requirements for rc script
_REQUIRE=	NETWORKING SERVERS

.ifdef(FREERADIUS_SLAVE_MYSQL)
WITH_MYSQL=	yes
.endif

CONFIGURE_ARGS=	--quiet \
		--prefix=${PREFIX} \
		--localstatedir=/var \
		--mandir=${PREFIX}/man \
		--with-system-libtool \
		--with-docdir=${DOCSDIR} \
		--with-logdir=${LOGDIR} \
		--with-large-files \
		--with-openssl-includes=${OPENSSLINC} \
		--with-openssl-libraries=${OPENSSLLIB} \
		--without-rlm_sql_db2 \
		--without-rlm_sql_freetds \
		--without-rlm_sql_iodbc \
		--without-rlm_sql_oracle \
		--without-rlm_sql_sybase \
		--without-rlm_sql_unixodbc

.if ${OSVERSION} < 500000 && ${OPENSSLBASE} == "/usr"
PLIST_SUB+=	4SSL="@comment "
.else
PLIST_SUB+=	4SSL=""
.endif

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-pic
.endif

.if defined(WITH_HEIMDAL) && !defined(WITH_KERBEROS)
WITH_KERBEROS=	yes
.endif

.ifdef(WITH_KERBEROS)
.ifdef(WITH_HEIMDAL)
LIB_DEPENDS+=	krb5.21:${PORTSDIR}/security/heimdal
CONFIGURE_ARGS+=--enable-heimdal-krb5
.else
LIB_DEPENDS+=	krb5.3:${PORTSDIR}/security/krb5
.endif
CONFIGURE_ARGS+=--with-rlm-krb5-lib-dir=${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-rlm-krb5-include-dir=${LOCALBASE}/include
PLIST_SUB+=	KRB5=""
.else
CONFIGURE_ARGS+=--without-rlm_krb5
PLIST_SUB+=	KRB5="@comment "
.endif

.if defined(WITH_EDIR) && !defined(WITH_LDAP)
WITH_LDAP=	yes
.endif

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
_REQUIRE+=	slapd
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.ifdef(WITH_EDIR)
CONFIGURE_ARGS+=--with-edir
.endif

.ifdef(WITH_MYSQL)
USE_MYSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_mysql
PLIST_SUB+=	MYSQL=""
_REQUIRE+=	mysql
.else
CONFIGURE_ARGS+=--without-rlm_sql_mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=	YES
CONFIGURE_ARGS+=--with-rlm_sql_postgresql
PLIST_SUB+=	PGSQL=""
_REQUIRE+=	postgresql
.else
CONFIGURE_ARGS+=--without-rlm_sql_postgresql
PLIST_SUB+=	PGSQL="@comment "
.endif

.ifdef(WITH_FIREBIRD)
USE_FIREBIRD=	YES
CONFIGURE_ARGS+=--with-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_firebird
PLIST_SUB+=	FIREBIRD="@comment "
.endif

# Firebird module is still experimental
.if defined(WITH_FIREBIRD) && !defined(WITH_EXPERIMENTAL)
WITH_EXPERIMENTAL=	yes
.endif

.ifdef(WITH_SNMP)
LIB_DEPENDS+=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4
.else
CONFIGURE_ARGS+=--without-snmp
.endif

.ifdef(WITH_EXPERIMENTAL)
USE_PYTHON=	yes
# hack to get the dependency
.include "${PORTSDIR}/Mk/bsd.python.mk"
CONFIGURE_ARGS+=--with-experimental-modules
PLIST_SUB+=	EXPM=""
.else
PLIST_SUB+=	EXPM="@comment "
.endif

.ifndef(WITH_NOPERL)
USE_PERL5=	yes
.endif

# rlm_perl does not build on 4.x
.if ${OSVERSION} < 500000 || defined(WITH_NOPERL)
CONFIGURE_ARGS+=--without-rlm_perl
PLIST_SUB+=	RLMPERL="@comment "
.else
CONFIGURE_ARGS+=--with-rlm_perl
PLIST_SUB+=	RLMPERL=""
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

USE_LDCONFIG=	yes

MAN1=		radclient.1 radeapclient.1 radlast.1 radtest.1 radwho.1 \
		radzap.1
MAN5=		acct_users.5 clients.5 clients.conf.5 dictionary.5 naslist.5 \
		radiusd.conf.5 rlm_acct_unique.5 rlm_always.5 \
		rlm_attr_filter.5 rlm_attr_rewrite.5 rlm_chap.5 rlm_counter.5 \
		rlm_detail.5 rlm_expr.5 rlm_files.5 rlm_mschap.5 rlm_pap.5 \
		rlm_passwd.5 rlm_realm.5 rlm_sql.5 rlm_sql_log.5 rlm_unix.5 users.5
MAN8=		radiusd.8 radrelay.8 radsqlrelay.8 radwatch.8 rlm_ippool_tool.8

DICTS=		dictionary.3com dictionary.3gpp dictionary.3gpp2 dictionary.acc \
		dictionary.airespace dictionary.alcatel dictionary.alteon \
		dictionary.altiga dictionary.alvarion dictionary.aptis \
		dictionary.aruba dictionary.ascend dictionary.asn dictionary.avaya \
		dictionary.bay dictionary.bintec dictionary.bristol \
		dictionary.cablelabs dictionary.cabletron dictionary.cisco \
		dictionary.cisco.bbsm dictionary.cisco.vpn3000 dictionary.cisco.vpn5000 \
		dictionary.colubris dictionary.columbia_university dictionary.compat \
		dictionary.cosine dictionary.digium dictionary.epygi \
		dictionary.ericsson dictionary.erx dictionary.extreme \
		dictionary.fortinet dictionary.foundry dictionary.freeradius \
		dictionary.freeradius.internal dictionary.gandalf dictionary.garderos \
		dictionary.gemtek dictionary.hp dictionary.ipunplugged dictionary.issanni \
		dictionary.itk dictionary.juniper dictionary.karlnet \
		dictionary.livingston dictionary.localweb dictionary.lucent \
		dictionary.merit dictionary.microsoft dictionary.mikrotik \
		dictionary.motorola dictionary.navini dictionary.netscreen \
		dictionary.nokia dictionary.nomadix dictionary.nortel dictionary.ntua \
		dictionary.packeteer dictionary.patton \
		dictionary.propel dictionary.quintum \
		dictionary.redback dictionary.redcreek \
		dictionary.rfc2865 dictionary.rfc2866 dictionary.rfc2867 \
		dictionary.rfc2868 dictionary.rfc2869 dictionary.rfc3162 \
		dictionary.rfc3576 dictionary.rfc3580 dictionary.rfc4590 \
		dictionary.riverstone dictionary.roaringpenguin \
		dictionary.schulzrinne-sipping dictionary.shasta dictionary.shiva \
		dictionary.sofaware dictionary.sonicwall \
		dictionary.springtide dictionary.starent dictionary.t_systems_nova \
		dictionary.telebit dictionary.trapeze dictionary.tropos \
		dictionary.unix dictionary.usr dictionary.valemount \
		dictionary.versanet dictionary.walabi dictionary.waverider \
		dictionary.wispr dictionary.xedia dictionary.xylan dictionary.zyxel

SUB_LIST+=	REQUIRE="${_REQUIRE}"

post-patch:
# Patch Makefile / Makefile.in throughout the source tree to install in EXAMPLESDIR not raddb
	@for i in `${FIND} -E ${WRKSRC} -regex '.*Makefile(\.in)?$$' -print` ; do \
		${REINPLACE_CMD} -e "s:\$$(R)\$$(raddbdir):${EXAMPLESDIR}/raddb:g" $${i}; \
	done
	@for i in `${FIND} -E ${WRKSRC} -regex '.*Makefile(\.in)?\.(orig|bak)$$' -print` ; do \
		${RM} $${i}; \
	done
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's/-DNO_OPENSSL//' ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${PREFIX}/etc/raddb ${DATADIR}
.for dict in ${DICTS}
	${INSTALL_DATA} ${WRKSRC}/share/${dict} ${DATADIR}/${dict}
.endfor
	for i in `${FIND} ${EXAMPLESDIR}/raddb/ -type d -mindepth 1 -print \
	| ${SED} -e 's:^${EXAMPLESDIR}/raddb/::g'`; do \
		if [ ! -d ${PREFIX}/etc/raddb/$${i} ]; then \
			${MKDIR} ${PREFIX}/etc/raddb/$${i}; \
		fi; \
	done
	for i in `${FIND} ${EXAMPLESDIR}/raddb/ -type f -print \
	| ${SED} -e 's:^${EXAMPLESDIR}/raddb/::g'`; do \
		if [ ! -f ${PREFIX}/etc/raddb/$${i} ]; then \
			${CP} -p ${EXAMPLESDIR}/raddb/$${i} ${PREFIX}/etc/raddb/$${i}; \
		fi; \
	done

.include <bsd.port.post.mk>
