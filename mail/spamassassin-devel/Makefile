PORTNAME=	spamassassin
PORTVERSION=	${SA_COMMIT_DATE}
PORTREVISION=	1
CATEGORIES?=	mail perl5
PKGNAMESUFFIX=	-devel

MAINTAINER?=	cy@FreeBSD.org
COMMENT?=	Highly efficient mail filter for identifying spam
WWW=		https://spamassassin.apache.org/

USE_GITHUB=	yes
GH_ACCOUNT=	apache
GH_TAGNAME=	f2a0189c2
SA_COMMIT_DATE=	2025.09.24

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-Encode-Detect>=0:converters/p5-Encode-Detect \
		p5-HTML-Parser>=3.46:www/p5-HTML-Parser \
		p5-HTTP-Date>=0:www/p5-HTTP-Date \
		p5-Net-DNS>=0.63:dns/p5-Net-DNS \
		p5-NetAddr-IP>=4.010:net-mgmt/p5-NetAddr-IP
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite \
		p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode \
		p5-Net-LibIDN>=0:dns/p5-Net-LibIDN \
		p5-URI>=0:net/p5-URI \
		p5-Class-XSAccessor>=0:devel/p5-Class-XSAccessor \
		p5-XString>=0:textproc/p5-XString \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		re2c>=.12.0:devel/re2c

.for dep in DCC DKIM DMARC MYSQL PGSQL PYZOR RAZOR RELAY_COUNTRY RLIMIT SPF_QUERY SSL
TEST_DEPENDS+=	${${dep}_RUN_DEPENDS}
.endfor

CONFLICTS?=	ja-spamassassin spamassassin

CPE_VENDOR=	apache

USES=		cpe perl5
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

OPTIONS_DEFINE=		AS_ROOT DOCS SSL
OPTIONS_GROUP=		DATABASE GPG PLUGINS
OPTIONS_GROUP_DATABASE=	MYSQL PGSQL
OPTIONS_GROUP_PLUGINS=	DCC DKIM DMARC PYZOR RAZOR RELAY_COUNTRY RLIMIT SPF_QUERY
OPTIONS_SINGLE=		GPG
OPTIONS_SINGLE_GPG=	GNUPG_NONE GNUPG GNUPG2
OPTIONS_DEFAULT=	AS_ROOT DKIM GNUPG SSL SPF_QUERY

AS_ROOT_DESC=		Run spamd as root (recommended)

DATABASE_DESC=		Optional user-config/bayes database backends

GPG_DESC=		GnuPG (for sa-update)
GNUPG_NONE_DESC=	Do not use GnuPG
GNUPG_DESC=		GnuPG 1 (security/gnupg1)
GNUPG2_DESC=		GnuPG 2 (security/gnupg)

PLUGINS_DESC=		Optional SpamAssassin plugins
DCC_DESC=		DCC digest list support (mail/dcc-dccd)
DKIM_DESC=		Verify DKIM records (mail/p5-Mail-DKIM)
DMARC_DESC=		Verify DMARC records (mail/p5-Mail-DMARC)
PYZOR_DESC=		Pyzor digest list support (mail/pyzor)
RAZOR_DESC=		Vipul's Razor digest list support (mail/razor-agents)
RELAY_COUNTRY_DESC=	Location-based scoring (net/p5-GeoIP2)
RLIMIT_DESC=		Resource limits (devel/p5-BSD-Resource)
SPF_QUERY_DESC=		Verify SPF records (mail/p5-Mail-SPF)

SUB_FILES=	pkg-message
SUB_LIST+=	SPAMD_OWN="${USERS}:${GROUPS}"
PLIST_SUB+=	USER=${USERS} GROUP=${GROUPS}
OPTIONS_SUB=	yes

AS_ROOT_SUB_LIST=	RUN_AS_USER="-u ${USERS} -H /var/spool/spamd"
AS_ROOT_SUB_LIST_OFF=	RUN_AS_USER=
DCC_RUN_DEPENDS=	dcc-dccd>=1.3.111:mail/dcc-dccd
DKIM_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
			p5-Mail-DKIM>=0.37:mail/p5-Mail-DKIM \
			p5-Crypt-OpenSSL-RSA>=0.26_1:security/p5-Crypt-OpenSSL-RSA
DMARC_RUN_DEPENDS=	p5-Mail-DMARC>=0:mail/p5-Mail-DMARC \
			p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
			p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
			p5-Config-Tiny>=0:devel/p5-Config-Tiny \
			p5-File-ShareDir-Install>=0:devel/p5-File-ShareDir-Install \
			p5-Net-IP>=0:net-mgmt/p5-Net-IP \
			p5-Socket6>=0:net/p5-Socket6 \
			p5-Email-MIME>=0:mail/p5-Email-MIME \
			p5-HTTP-Message>=0:www/p5-HTTP-Message \
			p5-HTTP-Tiny>=0:www/p5-HTTP-Tiny \
			p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL \
			p5-JSON>=0:converters/p5-JSON \
			p5-Net-SMTPS>=0:mail/p5-Net-SMTPS \
			p5-Net-SSLeay>=0:security/p5-Net-SSLeay \
			p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
			p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
			p5-DBIx-Simple>=0:databases/p5-DBIx-Simple \
			p5-Test-File-ShareDir>=0:devel/p5-Test-File-ShareDir \
			p5-CGI>=0:www/p5-CGI \
			p5-Email-Simple>=0:mail/p5-Email-Simple \
			p5-Mail-DKIM>=0:mail/p5-Mail-DKIM \
			p5-Net-IMAP-Simple>=0:mail/p5-Net-IMAP-Simple \
			p5-Net-Server>=0:net/p5-Net-Server \
			p5-Net-HTTP>=0:net/p5-Net-HTTP \
			p5-Test-Output>=0:devel/p5-Test-Output \
			p5-Net-DNS>=0:dns/p5-Net-DNS \
			p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode \
			p5-libwww>=0:www/p5-libwww \
			p5-URI>=0:net/p5-URI
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:security/gnupg1
GNUPG2_RUN_DEPENDS=	gpg2:security/gnupg
MYSQL_RUN_DEPENDS=	${DBD_MYSQL}
MYSQL_USES=		mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
PYZOR_RUN_DEPENDS=	pyzor:mail/pyzor
RAZOR_RUN_DEPENDS=	razor-agents>=2.84:mail/razor-agents \
			p5-Digest-SHA1>=2.13:security/p5-Digest-SHA1
RLIMIT_RUN_DEPENDS=	p5-BSD-Resource>=1.2911:devel/p5-BSD-Resource
RELAY_COUNTRY_RUN_DEPENDS=	p5-GeoIP2>=0:net/p5-GeoIP2 \
			p5-IP-Country>=0:net/p5-IP-Country
SPF_QUERY_RUN_DEPENDS=	p5-Mail-SPF>=0:mail/p5-Mail-SPF

SSL_USES=		ssl
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:security/p5-IO-Socket-SSL
SSL_CONFIGURE_ON=	ENABLE_SSL=yes
SSL_CONFIGURE_OFF=	ENABLE_SSL=no

# plugin names in rules/*.pre, for enabling/disabling
DCC_INITVAR=		DCC
DKIM_INITVAR=		DKIM
DMARC_INITVAR=		DMARC
PYZOR_INITVAR=		Pyzor
RAZOR_INITVAR=		Razor2
RELAY_COUNTRY_INITVAR=	RelayCountry
RLIMIT_INITVAR=		ResourceLimit
SPF_QUERY_INITVAR=	SPF

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

post-patch::
	${REINPLACE_CMD} -e 's,B_CONFDIR)/local.cf,B_CONFDIR)/local.cf.sample,g' \
		-e 's,B_CONFDIR)/init.pre,B_CONFDIR)/init.pre.sample,g' \
		-e 's,B_CONFDIR)/v310.pre,B_CONFDIR)/v310.pre.sample,g' \
		-e 's,B_CONFDIR)/v312.pre,B_CONFDIR)/v312.pre.sample,g' \
		-e 's,B_CONFDIR)/v320.pre,B_CONFDIR)/v320.pre.sample,g' \
		-e 's,B_CONFDIR)/v330.pre,B_CONFDIR)/v330.pre.sample,g' \
		-e 's,B_CONFDIR)/v340.pre,B_CONFDIR)/v340.pre.sample,g' \
		-e 's,B_CONFDIR)/v341.pre,B_CONFDIR)/v341.pre.sample,g' \
		-e 's,B_CONFDIR)/v342.pre,B_CONFDIR)/v342.pre.sample,g' \
		-e 's,B_CONFDIR)/v343.pre,B_CONFDIR)/v343.pre.sample,g' \
		-e 's,B_CONFDIR)/v400.pre,B_CONFDIR)/v400.pre.sample,g' \
		-e 's,B_CONFDIR)/v401.pre,B_CONFDIR)/v401.pre.sample,g' \
		-e 's,B_CONFDIR)/v402.pre,B_CONFDIR)/v402.pre.sample,g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL
	${REINPLACE_CMD} -e '/^CC =/d; \
		s|@SSLCFLAGS@|& $${CFLAGS}|g' ${WRKSRC}/spamc/Makefile.in

.for var in ${OPTIONS_GROUP_PLUGINS}
.  if ${PORT_OPTIONS:M${var}}
	${REINPLACE_CMD} -e '/${${var}_INITVAR}/s/^\#.*loadplugin/loadplugin/' ${WRKSRC}/rules/*.pre
.  else
	${REINPLACE_CMD} -e '/${${var}_INITVAR}/s/^loadplugin/\# loadplugin/' ${WRKSRC}/rules/*.pre
.  endif
.endfor

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
	@${MKDIR} ${STAGEDIR}${DBDIR}/spamassassin ${STAGEDIR}/var/run/spamd
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "sql ldap" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
