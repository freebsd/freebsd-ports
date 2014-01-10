# Created by: Anthony Kim
# $FreeBSD$

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	3.3.2
PORTREVISION?=	8		# committer: please bump PORTREVISION on Slaves
CATEGORIES?=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:apache/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	spamassassin/source/:apache Mail/:cpan
PKGNAMEPREFIX?=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:apache,cpan

MAINTAINER?=	perl@FreeBSD.org
COMMENT?=	A highly efficient mail filter for identifying spam

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-NetAddr-IP>=4.00.7:${PORTSDIR}/net-mgmt/p5-NetAddr-IP \
		p5-Net-DNS>=0.63:${PORTSDIR}/dns/p5-Net-DNS \
		p5-HTML-Parser>=3.46:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-Encode-Detect>=0:${PORTSDIR}/converters/p5-Encode-Detect \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS?=	ja-p5-Mail-SpamAssassin-[0-9]* p5-Mail-SpamAssassin-devel-[0-9]* p5-Mail-SpamAssassin-Alt-[0-9]*

USES=		perl5
USE_PERL5=	configure
USE_LDCONFIG=	yes
DBDIR?=		/var/db
ETCDIR?=	${PREFIX}/etc/mail/spamassassin
CONTACT_ADDRESS?=	The administrator of that system
USERS?=		spamd
GROUPS?=	spamd
CONFIGURE_ARGS=	SYSCONFDIR="${PREFIX}/etc" \
	       	CONTACT_ADDRESS="${CONTACT_ADDRESS}" \
		LOCALSTATEDIR="${DBDIR}/spamassassin"

OPTIONS_DEFINE=	AS_ROOT SPAMC SACOMPILE DKIM SSL GNUPG MYSQL PGSQL RAZOR \
		SPF_QUERY RELAY_COUNTRY DCC IPV6
OPTIONS_DEFAULT=	AS_ROOT SPAMC DKIM SSL GNUPG RAZOR
AS_ROOT_DESC=		Run spamd as root (recommended)
SPAMC_DESC=		Build spamd/spamc (not for amavisd)
SACOMPILE_DESC=		sa-compile
DKIM_DESC=		DKIM/DomainKeys Identified Mail
SSL_DESC=		Build with SSL support for spamd/spamc
GNUPG_DESC=		Install GnuPG (for sa-update)
RAZOR_DESC=		Add Vipul's Razor support
SPF_QUERY_DESC=		Add SPF query support
RELAY_COUNTRY_DESC=	Relay country support
DCC_DESC=		Add DCC support (see LICENSE)
IPV6_DESC=		IPv6 sockets support

SUB_FILES=	pkg-install
SUB_LIST=	USER=${USERS} GROUP=${GROUPS} INSTALL="${INSTALL}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=	yes
.endif

.if ${PORT_OPTIONS:MSPAMC}
CONFIGURE_ARGS+=	BUILD_SPAMC=yes
.else
CONFIGURE_ARGS+=	BUILD_SPAMC=no
WITH_AS_ROOT=
WITHOUT_SSL=1
.endif

.if ${PORT_OPTIONS:MSPF_QUERY}
RUN_DEPENDS+=	p5-Mail-SPF>=0:${PORTSDIR}/mail/p5-Mail-SPF
.endif
.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif

.if ${PORT_OPTIONS:MSSL}
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
CONFIGURE_ARGS+=	ENABLE_SSL=yes
PLIST_SUB+=	SSL=""
.else
CONFIGURE_ARGS+=	ENABLE_SSL=no
PLIST_SUB+=	SSL="@comment "
.endif

.if ${PORT_OPTIONS:MGNUPG}
RUN_DEPENDS+=	gnupg1>=1.4.7:${PORTSDIR}/security/gnupg1
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MRAZOR}
RUN_DEPENDS+=	razor-agents>=2.84:${PORTSDIR}/mail/razor-agents
.else
.if   ${PERL_LEVEL} < 501000
.if ! ${PORT_OPTIONS:MDKIM}
RUN_DEPENDS+=	p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1
.endif
.endif
.endif

.if ${PORT_OPTIONS:MDKIM}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
. if ${PERL_LEVEL} < 501000
RUN_DEPENDS+=	p5-Digest-SHA>=0:${PORTSDIR}/security/p5-Digest-SHA
. endif
RUN_DEPENDS+=	p5-Mail-DKIM>=0.37:${PORTSDIR}/mail/p5-Mail-DKIM
. if ${PERL_LEVEL} < 501400
RUN_DEPENDS+=	p5-Crypt-OpenSSL-RSA>=0.24:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA
. else
RUN_DEPENDS+=	p5-Crypt-OpenSSL-RSA>=0.26_1:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA
. endif
.endif

.if ${PORT_OPTIONS:MSACOMPILE}
RUN_DEPENDS+=	re2c>=.12.0:${PORTSDIR}/devel/re2c
.endif

.if ${PORT_OPTIONS:MRELAY_COUNTRY}
RUN_DEPENDS+=	p5-IP-Country>=0:${PORTSDIR}/net/p5-IP-Country
.endif

.if ${PORT_OPTIONS:MDCC}
RUN_DEPENDS+=	dcc-dccd>=1.3.111:${PORTSDIR}/mail/dcc-dccd
.endif

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/spamassassin
DOCS=		CREDITS Changes INSTALL NOTICE PACKAGING README TRADEMARK UPGRADE USAGE procmailrc.example
DOCSSQL=	README README.awl README.bayes awl_mysql.sql awl_pg.sql bayes_mysql.sql bayes_pg.sql userpref_mysql.sql userpref_pg.sql
DOCSLDAP=	README README.testing sa_test.ldif
PORTDOCS=	${DOCS} sql ldap

USE_RC_SUBR=	sa-spamd

.if ${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}
SUB_LIST+=	SQL_FLAG="-Q"
.else
SUB_LIST+=	SQL_FLAG=""
.endif
.if ! ${PORT_OPTIONS:MAS_ROOT}
SUB_LIST+=	RUN_AS_USER="-u ${USERS} -H /var/spool/spamd"
.else
SUB_LIST+=	RUN_AS_USER=""
.endif

post-patch::
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${REINPLACE_CMD} -e 's#B_CONFDIR)/local.cf#B_CONFDIR)/local.cf.sample#g' \
		-e 's#B_CONFDIR)/init.pre#B_CONFDIR)/init.pre.sample#g' \
		-e 's#B_CONFDIR)/v310.pre#B_CONFDIR)/v310.pre.sample#g' \
		-e 's#B_CONFDIR)/v312.pre#B_CONFDIR)/v312.pre.sample#g' \
		-e 's#B_CONFDIR)/v320.pre#B_CONFDIR)/v320.pre.sample#g' \
		-e 's#B_CONFDIR)/v330.pre#B_CONFDIR)/v330.pre.sample#g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e '/^CC =/d; \
		s|@SSLCFLAGS@|& $${CFLAGS}|g' ${WRKSRC}/spamc/Makefile.in

.if ${PORT_OPTIONS:MRAZOR}
	${REINPLACE_CMD} -e '/Razor2/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v312.pre
.endif
.if ${PORT_OPTIONS:MRELAY_COUNTRY}
	${REINPLACE_CMD} -e '/RelayCountry/s/^# ?loadplugin/loadplugin/' ${WRKSRC}/rules/init.pre
.endif
.if ! ${PORT_OPTIONS:MDKIM}
	${REINPLACE_CMD} -e '/DKIM/s/^loadplugin/#loadplugin/' ${WRKSRC}/rules/v312.pre
.endif
.if ! ${PORT_OPTIONS:MSPF_QUERY}
	${REINPLACE_CMD} -e '/SPF/s/^loadplugin/#loadplugin/' ${WRKSRC}/rules/init.pre
.endif
.if ${PORT_OPTIONS:MDCC}
	${REINPLACE_CMD} -e '/DCC/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v310.pre
.endif
.if ${PORT_OPTIONS:MSACOMPILE}
	${REINPLACE_CMD} -e '/Rule2XSBody/s/^# loadplugin/loadplugin/' ${WRKSRC}/rules/v320.pre
.endif

post-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} spamc/libspamc.so)
.if ${PORT_OPTIONS:MSSL}
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} spamc/libsslspamc.so)
.endif

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_PROGRAM} ${WRKSRC}/spamc/libspamc.so ${STAGEDIR}${PREFIX}/lib/libspamc.so.0
	@${LN} -sf libspamc.so.0 ${STAGEDIR}${PREFIX}/lib/libspamc.so
.if ${PORT_OPTIONS:MSSL}
	@${INSTALL_PROGRAM} ${WRKSRC}/spamc/libsslspamc.so ${STAGEDIR}${PREFIX}/lib/libsslspamc.so.0
	@${LN} -sf libsslspamc.so.0 ${STAGEDIR}${PREFIX}/lib/libsslspamc.so
.endif
	@${INSTALL_DATA} ${WRKSRC}/spamc/libspamc.h ${STAGEDIR}${PREFIX}/include

post-install::
.if ${PORT_OPTIONS:MSPAMC}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/spamc
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/sql ${STAGEDIR}${DOCSDIR}/ldap
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${DOCSSQL:S|^|${WRKSRC}/sql/|} ${STAGEDIR}${DOCSDIR}/sql
	@${INSTALL_DATA} ${DOCSLDAP:S|^|${WRKSRC}/ldap/|} ${STAGEDIR}${DOCSDIR}/ldap
.endif

.include <bsd.port.post.mk>
