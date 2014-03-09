# Created by: Anthony Kim
# $FreeBSD$

PORTNAME=		Mail-SpamAssassin
PORTVERSION=	3.4.0
PORTREVISION?=	1		# committer: please bump PORTREVISION on Slaves
CATEGORIES?=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:apache/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	spamassassin/source/:apache Mail/:cpan
PKGNAMEPREFIX?=	p5-
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}:apache,cpan

MAINTAINER?=	adamw@FreeBSD.org
COMMENT?=		Highly efficient mail filter for identifying spam

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-NetAddr-IP>=4.00.7:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
				p5-Net-DNS>=0.63:${PORTSDIR}/dns/p5-Net-DNS \
				p5-HTML-Parser>=3.46:${PORTSDIR}/www/p5-HTML-Parser \
				p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
				p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
				p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
				re2c>=.12.0:${PORTSDIR}/devel/re2c

CONFLICTS?=	ja-p5-Mail-SpamAssassin-[0-9]*

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes

DATADIR=	${PREFIX}/share/spamassassin
DBDIR?=		/var/db
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
ETCDIR?=	${PREFIX}/etc/mail/spamassassin

CONTACT_ADDRESS?=	The administrator of that system
USERS?=		spamd
GROUPS?=	spamd
CONFIGURE_ARGS=	SYSCONFDIR="${PREFIX}/etc" \
				CONTACT_ADDRESS="${CONTACT_ADDRESS}" \
				LOCALSTATEDIR="${DBDIR}/spamassassin" \
				BUILD_SPAMC=yes

OPTIONS_DEFINE=	AS_ROOT GNUPG IPV6 MYSQL PGSQL SSL UPDATE_AND_COMPILE
OPTIONS_GROUP=	PLUGINS
OPTIONS_GROUP_PLUGINS=	DCC DKIM PYZOR RAZOR RELAY_COUNTRY SPF_QUERY
OPTIONS_DEFAULT=AS_ROOT DKIM GNUPG RAZOR SSL UPDATE_AND_COMPILE

AS_ROOT_DESC=		Run spamd as root (recommended)
GNUPG_DESC=			Install GnuPG (for sa-update, optional)
IPV6_DESC=			IPv6 sockets support
SSL_DESC=			Build spamd/spamc with SSL support
UPDATE_AND_COMPILE_DESC=	Download and compile rulesets (recommended)

PLUGINS_DESC=		Select SpamAssassin plugins
DCC_DESC=			Add DCC support (mail/dcc-dccd)
DKIM_DESC=			DKIM/DomainKeys Identified Mail (mail/p5-Mail-DKIM)
PYZOR_DESC=			Add Pyzor support (mail/pyzor)
RAZOR_DESC=			Add Vipul's Razor support (mail/razor-agents)
RELAY_COUNTRY_DESC=	Relay country support (net/p5-IP-Country)
SPF_QUERY_DESC=		Add SPF query support (mail/p5-Mail-SPF)

SUB_FILES=	pkg-message
PLIST_SUB+=	USER=${USERS} GROUP=${GROUPS}
OPTIONS_SUB=yes

DCC_RUN_DEPENDS=	dcc-dccd>=1.3.111:${PORTSDIR}/mail/dcc-dccd
DKIM_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
					p5-Mail-DKIM>=0.37:${PORTSDIR}/mail/p5-Mail-DKIM \
					p5-Crypt-OpenSSL-RSA>=0.26_1:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA
GNUPG_RUN_DEPENDS=	gnupg1>=1.4.7:${PORTSDIR}/security/gnupg1
IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
PYZOR_RUN_DEPENDS=	pyzor:${PORTSDIR}/mail/pyzor
RAZOR_RUN_DEPENDS=	razor-agents>=2.84:${PORTSDIR}/mail/razor-agents
RELAY_COUNTRY_RUN_DEPENDS=	p5-IP-Country>=0:${PORTSDIR}/net/p5-IP-Country
SPF_QUERY_RUN_DEPENDS=	p5-Mail-SPF>=0:${PORTSDIR}/mail/p5-Mail-SPF

SSL_USE=			OPENSSL=yes
SSL_RUN_DEPENDS=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
SSL_CONFIGURE_ON=	ENABLE_SSL=yes
SSL_CONFIGURE_OFF=	ENABLE_SSL=no

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
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${REINPLACE_CMD} -e 's#B_CONFDIR)/local.cf#B_CONFDIR)/local.cf.sample#g' \
		-e 's#B_CONFDIR)/init.pre#B_CONFDIR)/init.pre.sample#g' \
		-e 's#B_CONFDIR)/v310.pre#B_CONFDIR)/v310.pre.sample#g' \
		-e 's#B_CONFDIR)/v312.pre#B_CONFDIR)/v312.pre.sample#g' \
		-e 's#B_CONFDIR)/v320.pre#B_CONFDIR)/v320.pre.sample#g' \
		-e 's#B_CONFDIR)/v330.pre#B_CONFDIR)/v330.pre.sample#g' \
		-e 's#B_CONFDIR)/v340.pre#B_CONFDIR)/v340.pre.sample#g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^CC =/d; \
		s|@SSLCFLAGS@|& $${CFLAGS}|g' ${WRKSRC}/spamc/Makefile.in

.if ${PORT_OPTIONS:MDCC}
	${REINPLACE_CMD} -e '/DCC/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v310.pre
.endif
.if empty(PORT_OPTIONS:MDKIM)
	${REINPLACE_CMD} -e '/DKIM/s/^loadplugin/#loadplugin/' ${WRKSRC}/rules/v312.pre
.endif
.if empty(PORT_OPTIONS:MPYZOR)
	${REINPLACE_CMD} -e '/Pyzor/s/^loadplugin/#loadplugin/' ${WRKSRC}/rules/v310.pre
.endif
.if ${PORT_OPTIONS:MRAZOR}
	${REINPLACE_CMD} -e '/Razor2/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v312.pre
.endif
.if ${PORT_OPTIONS:MRELAY_COUNTRY}
	${REINPLACE_CMD} -e '/RelayCountry/s/^# ?loadplugin/loadplugin/' ${WRKSRC}/rules/init.pre
.endif
.if empty(PORT_OPTIONS:MSPF_QUERY)
	${REINPLACE_CMD} -e '/SPF/s/^loadplugin/#loadplugin/' ${WRKSRC}/rules/init.pre
.endif
.if ${PORT_OPTIONS:MSACOMPILE}
	${REINPLACE_CMD} -e '/Rule2XSBody/s/^# loadplugin/loadplugin/' ${WRKSRC}/rules/v320.pre
.endif

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
	@${MKDIR} ${STAGEDIR}/var/lib/spamassassin ${STAGEDIR}${DBDIR}/spamassassin
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/sql ${STAGEDIR}${DOCSDIR}/ldap
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/sql/* ${STAGEDIR}${DOCSDIR}/sql
	${INSTALL_DATA} ${WRKSRC}/ldap/* ${STAGEDIR}${DOCSDIR}/ldap

.include <bsd.port.post.mk>
