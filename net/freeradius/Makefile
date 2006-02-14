# New ports collection makefile for:    freeradius
# Date created:         May 9 2002
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freeradius
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.freeradius.org/pub/radius/ \
		http://freeradius.portal-to-web.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free RADIUS server implementation

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

LOGDIR?=	/var/log

CONFLICTS=	gnu-radius-1.* openradius-0.* radiusd-cistron-1.*

USE_RC_SUBR=	radiusd.sh
USE_AUTOTOOLS=	libltdl:15 libtool:13
USE_GMAKE=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --quiet --with-logdir=${LOGDIR} \
		--localstatedir=/var \
		--disable-ltdl-install \
		--with-ltdl-include=${LOCALBASE}/include \
		--with-ltdl-lib=${LOCALBASE}/lib \
		--with-large-files --without-rlm_sql_unixodbc \
		--without-rlm_sql_oracle --without-rlm_sql_iodbc \
		--without-rlm_sql_db2
MAKE_ARGS+=	LDFLAGS=-L${LOCALBASE}/lib

PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS=	KERBEROS	"With Kerberos support" off \
		HEIMDAL		"With Heimdal Kerberos support" off \
		LDAP		"With LDAP user database" off \
		MYSQL		"With MySQL user database" off \
		PGSQL		"With PostgreSQL use database" off \
		SNMP		"With SNMP support" off \
		EXPERIMENTAL	"Build experimental modules" off

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CFLAGS+=	-fPIC
.endif

.if defined(WITH_HEIMDAL) && !defined(WITH_KERBEROS)
WITH_KERBEROS=	yes
.endif

.ifdef(WITH_KERBEROS)
.ifdef(WITH_HEIMDAL)
LIB_DEPENDS+=	krb5.20:${PORTSDIR}/security/heimdal
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

.ifdef(WITH_LDAP)
USE_OPENLDAP=	YES
PLIST_SUB+=	LDAP=""
.else
CONFIGURE_ARGS+=--without-rlm_ldap
PLIST_SUB+=	LDAP="@comment "
.endif

.ifdef(WITH_MYSQL)
USE_MYSQL=	YES
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

.ifdef(WITH_PGSQL)
USE_PGSQL=	YES
PLIST_SUB+=	PGSQL=""
.else
CONFIGURE_ARGS+=--without-rlm_sql_postgresql
PLIST_SUB+=	PGSQL="@comment "
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

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

# rlm_x99_token seems broken
#CONFIGURE_ARGS+=--without-rlm_x99_token
PLIST_SUB+=	TOKEN=""

# rlm_perl does not build on 4.x
.if ${OSVERSION} < 500000
PLIST_SUB+=	RLMPERL="@comment "
.else
PLIST_SUB+=	RLMPERL=""
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--with-pic
.endif

INSTALLS_SHLIB=	yes

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
		dictionary.altiga dictionary.aptis dictionary.aruba dictionary.ascend \
		dictionary.avaya dictionary.bay dictionary.bintec dictionary.bristol \
		dictionary.cablelabs dictionary.cabletron dictionary.cisco \
		dictionary.cisco.bbsm dictionary.cisco.vpn3000 dictionary.cisco.vpn5000 \
		dictionary.colubris dictionary.columbia_university dictionary.compat \
		dictionary.cosine dictionary.digest dictionary.epygi \
		dictionary.ericsson dictionary.erx dictionary.extreme \
		dictionary.fortinet dictionary.foundry dictionary.freeradius \
		dictionary.freeradius.internal dictionary.gandalf dictionary.garderos \
		dictionary.gemtek dictionary.ipunplugged dictionary.issanni \
		dictionary.itk dictionary.juniper dictionary.karlnet \
		dictionary.livingston dictionary.localweb dictionary.lucent \
		dictionary.merit dictionary.microsoft dictionary.mikrotik \
		dictionary.motorola dictionary.navini dictionary.netscreen \
		dictionary.nokia dictionary.nomadix dictionary.ntua \
		dictionary.packeteer dictionary.propel dictionary.quintum \
		dictionary.redback dictionary.redcreek dictionary.rfc2865 \
		dictionary.rfc2866 dictionary.rfc2867 dictionary.rfc2868 \
		dictionary.rfc2869 dictionary.rfc3162 dictionary.rfc3576 \
		dictionary.rfc3580 dictionary.roaringpenguin dictionary.shasta \
		dictionary.shiva dictionary.sonicwall dictionary.springtide \
		dictionary.starent dictionary.t_systems_nova dictionary.telebit \
		dictionary.trapeze dictionary.unix dictionary.usr dictionary.valemount \
		dictionary.versanet dictionary.waverider dictionary.wispr \
		dictionary.xedia dictionary.xylan dictionary.zyxel

post-patch:
	@${RM} ${WRKSRC}/doc/Makefile.orig

post-install:
	@${MKDIR} ${PREFIX}/etc/raddb ${DATADIR} ${EXAMPLESDIR}
.for dict in ${DICTS}
	${INSTALL_DATA} ${WRKSRC}/share/${dict} ${DATADIR}/${dict}
.endfor
.ifdef(WITH_MYSQL)
	${INSTALL_DATA} \
	${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_mysql/db_mysql.sql \
	${EXAMPLESDIR}/db_mysql.sql
.endif

.ifdef(WITH_PGSQL)
	${INSTALL_DATA} \
	${WRKSRC}/src/modules/rlm_sql/drivers/rlm_sql_postgresql/db_postgresql.sql \
	${EXAMPLESDIR}/db_postgresql.sql
.endif

.include <bsd.port.post.mk>
