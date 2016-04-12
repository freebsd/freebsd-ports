# Created by: Anthony Kim
# $FreeBSD$

PORTNAME=	spamassassin
PORTVERSION=	3.4.1
PORTREVISION?=	6	# also bump japanese/spamassassin
CATEGORIES?=	mail perl5
MASTER_SITES=	APACHE/spamassassin/source CPAN/Mail
DISTNAME=	Mail-SpamAssassin-${PORTVERSION}

MAINTAINER?=	adamw@FreeBSD.org
COMMENT?=	Highly efficient mail filter for identifying spam

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Encode-Detect>=0:converters/p5-Encode-Detect \
		p5-HTML-Parser>=3.46:www/p5-HTML-Parser \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-IO-Socket-IP>=0:net/p5-IO-Socket-IP \
		p5-Net-DNS>=0.63:dns/p5-Net-DNS \
		p5-NetAddr-IP>=4.010:net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		re2c>=.12.0:devel/re2c

.for dep in DCC DKIM MYSQL PGSQL PYZOR RAZOR RELAY_COUNTRY SPF_QUERY SSL
TEST_DEPENDS+=	${${dep}_RUN_DEPENDS}
.endfor

CONFLICTS?=	ja-spamassassin-[0-9]*

CPE_VENDOR=	apache

USES=		perl5 cpe
USE_PERL5=	configure
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/spamassassin
DBDIR?=		/var/db
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
ETCDIR?=	${PREFIX}/etc/mail/spamassassin

SPAMASSASSIN_CONTACT_ADDRESS?=	The administrator of that system
USERS?=		spamd
GROUPS?=	spamd
CONFIGURE_ARGS=	SYSCONFDIR="${PREFIX}/etc" \
		CONTACT_ADDRESS="${SPAMASSASSIN_CONTACT_ADDRESS}" \
		LOCALSTATEDIR="${DBDIR}/spamassassin" \
		BUILD_SPAMC=yes

OPTIONS_DEFINE=		AS_ROOT SSL UPDATE_AND_COMPILE
OPTIONS_GROUP=		DATABASE GPG PLUGINS
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL
OPTIONS_GROUP_PLUGINS=	DCC DKIM PYZOR RAZOR RELAY_COUNTRY SPF_QUERY
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG_NONE GNUPG GNUPG2
OPTIONS_DEFAULT=	AS_ROOT GNUPG SSL UPDATE_AND_COMPILE

AS_ROOT_DESC=		Run spamd as root (recommended)
SSL_DESC=		Build spamd/spamc with SSL support
UPDATE_AND_COMPILE_DESC=Download and compile rulesets (recommended)

DATABASE_DESC=		Optional user-config/bayes database backends

GPG_DESC=		GnuPG (for sa-update, optional)
GNUPG_NONE_DESC=	Do not use GnuPG
GNUPG_DESC=		GnuPG 1 (security/gnupg1)
GNUPG2_DESC=		GnuPG 2 (security/gnupg)

PLUGINS_DESC=		Optional SpamAssassin plugins
DCC_DESC=		DCC digest list support (mail/dcc-dccd)
DKIM_DESC=		Verify DKIM records (mail/p5-Mail-DKIM)
PYZOR_DESC=		Pyzor digest list support (mail/pyzor)
RAZOR_DESC=		Vipul's Razor digest list support (mail/razor-agents)
RELAY_COUNTRY_DESC=	Location-based scoring (net/p5-Geo-IP)
SPF_QUERY_DESC=		Verify SPF records (mail/p5-Mail-SPF)

SUB_FILES=	pkg-message
SUB_LIST+=	SPAMD_OWN="${USERS}:${GROUPS}"
PLIST_SUB+=	USER=${USERS} GROUP=${GROUPS}
OPTIONS_SUB=	yes

DCC_RUN_DEPENDS=	dcc-dccd>=1.3.111:mail/dcc-dccd
DKIM_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
			p5-Mail-DKIM>=0.37:mail/p5-Mail-DKIM \
			p5-Crypt-OpenSSL-RSA>=0.26_1:security/p5-Crypt-OpenSSL-RSA
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PYZOR_RUN_DEPENDS=	pyzor:mail/pyzor
RAZOR_RUN_DEPENDS=	razor-agents>=2.84:mail/razor-agents
RELAY_COUNTRY_RUN_DEPENDS=	p5-Geo-IP>=0:net/p5-Geo-IP
SPF_QUERY_RUN_DEPENDS=	p5-Mail-SPF>=0:mail/p5-Mail-SPF

SSL_USE=		OPENSSL=yes
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
SSL_CONFIGURE_ON=	ENABLE_SSL=yes
SSL_CONFIGURE_OFF=	ENABLE_SSL=no

# plugin names in rules/*.pre, for enabling/disabling
DCC_INITVAR=		DCC
DKIM_INITVAR=		DKIM
PYZOR_INITVAR=		Pyzor
RAZOR_INITVAR=		Razor2
RELAY_COUNTRY_INITVAR=	RelayCountry
SPF_QUERY_INITVAR=	SPF
UPDATE_AND_COMPILE_INITVAR=	Rule2XSBody

DOCS=		CREDITS Changes INSTALL NOTICE PACKAGING README TRADEMARK UPGRADE USAGE procmailrc.example
DOCSSQL=	README README.awl README.bayes awl_mysql.sql awl_pg.sql bayes_mysql.sql bayes_pg.sql userpref_mysql.sql userpref_pg.sql
DOCSLDAP=	README README.testing sa_test.ldif
PORTDOCS=	${DOCS} sql ldap

USE_RC_SUBR=	sa-spamd

ALL_TARGET=	all spamc/libspamc.so

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSSL}
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
ALL_TARGET+=	spamc/libsslspamc.so
.endif

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
SUB_LIST+=	SQL_FLAG="-Q"
.else
SUB_LIST+=	SQL_FLAG=""
.endif

.if empty(PORT_OPTIONS:MAS_ROOT)
SUB_LIST+=	RUN_AS_USER="-u ${USERS} -H /var/spool/spamd"
.else
SUB_LIST+=	RUN_AS_USER=""
.endif

.if ${PORT_OPTIONS:MUPDATE_AND_COMPILE} && empty(PACKAGE_BUILDING) && empty(BATCH)
PLIST_SUB+=	UPDATE_ON_INSTALL="yes"
.else
PLIST_SUB+=	UPDATE_ON_INSTALL="no"
.endif

post-patch::
	${REINPLACE_CMD} -e 's,B_CONFDIR)/local.cf,B_CONFDIR)/local.cf.sample,g' \
		-e 's,B_CONFDIR)/init.pre,B_CONFDIR)/init.pre.sample,g' \
		-e 's,B_CONFDIR)/v310.pre,B_CONFDIR)/v310.pre.sample,g' \
		-e 's,B_CONFDIR)/v312.pre,B_CONFDIR)/v312.pre.sample,g' \
		-e 's,B_CONFDIR)/v320.pre,B_CONFDIR)/v320.pre.sample,g' \
		-e 's,B_CONFDIR)/v330.pre,B_CONFDIR)/v330.pre.sample,g' \
		-e 's,B_CONFDIR)/v340.pre,B_CONFDIR)/v340.pre.sample,g' \
		-e 's,B_CONFDIR)/v341.pre,B_CONFDIR)/v341.pre.sample,g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL
	${REINPLACE_CMD} -e '/^CC =/d; \
		s|@SSLCFLAGS@|& $${CFLAGS}|g' ${WRKSRC}/spamc/Makefile.in

.for var in ${OPTIONS_GROUP_PLUGINS} UPDATE_AND_COMPILE
.  if ${PORT_OPTIONS:M${var}}
	${REINPLACE_CMD} -e '/${${var}_INITVAR}/s/^\#.*loadplugin/loadplugin/' ${WRKSRC}/rules/*.pre
.  else
	${REINPLACE_CMD} -e '/${${var}_INITVAR}/s/^loadplugin/\# loadplugin/' ${WRKSRC}/rules/*.pre
.  endif
.endfor

	${FIND} ${WRKSRC} -name '*.orig' -or -name '*.bak' -delete

pre-su-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_LIB} ${WRKSRC}/spamc/libspamc.so ${STAGEDIR}${PREFIX}/lib/libspamc.so.0
	${LN} -sf libspamc.so.0 ${STAGEDIR}${PREFIX}/lib/libspamc.so
.if ${PORT_OPTIONS:MSSL}
	${INSTALL_LIB} ${WRKSRC}/spamc/libsslspamc.so ${STAGEDIR}${PREFIX}/lib/libsslspamc.so.0
	${LN} -sf libsslspamc.so.0 ${STAGEDIR}${PREFIX}/lib/libsslspamc.so
.endif
	${INSTALL_DATA} ${WRKSRC}/spamc/libspamc.h ${STAGEDIR}${PREFIX}/include

post-install::
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spamc
	@${MKDIR} ${STAGEDIR}/var/lib/spamassassin ${STAGEDIR}${DBDIR}/spamassassin ${STAGEDIR}/var/run/spamd
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "sql ldap" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
