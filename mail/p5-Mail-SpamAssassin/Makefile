# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	3.1.1
PORTREVISION=	4
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:apache/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	spamassassin/source/:apache Mail/:cpan
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:apache,cpan

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A highly efficient mail filter for identifying spam

BUILD_DEPENDS=	p5-Net-DNS>=0.53:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/Bundle/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		gpg:${PORTSDIR}/security/gnupg

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	SYSCONFDIR="${PREFIX}/etc" \
	       	CONTACT_ADDRESS="${CONTACT_ADDRESS}" \
		BUILD_SPAMC=yes

# You can override it if you like
CONTACT_ADDRESS?=	The administrator of that system

OPTIONS=	AS_ROOT "Run spamd as root (recommended)" on \
		DOMAINKEYS "DomainKeys support" off \
		SSL "Build with SSL support for spamd/spamc" on \
		MYSQL "Add MySQL support" off \
		PGSQL "Add PostreSQL support" off \
		RAZOR "Add Vipul's Razor support" on \
		SPF_QUERY "Add SPF query support" off \
		RELAY_COUNTRY "Relay country support" off \
		TOOLS "Install SpamAssassin tools" off

.include <bsd.port.pre.mk>

.if defined(WITH_SPF_QUERY)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query
.endif

.if !defined(WITHOUT_SSL)
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
USE_OPENSSL=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
CONFIGURE_ARGS+=	ENABLE_SSL=yes
.else
CONFIGURE_ARGS+=	ENABLE_SSL=no
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_RAZOR)
RUN_DEPENDS+=	razor-agents>=2.81:${PORTSDIR}/mail/razor-agents
.endif

.if defined(WITH_DOMAINKEYS)
RUN_DEPENDS+=	p5-Mail-DomainKeys>=0.80:${PORTSDIR}/mail/p5-Mail-DomainKeys
.endif

.if defined(WITH_RELAY_COUNTRY)
RUN_DEPENDS+=	${SITE_PERL}/IP/Country/Fast.pm:${PORTSDIR}/net/p5-IP-Country
.endif

.if defined(WITH_TOOLS)
RUN_DEPENDS+=	${SITE_PERL}/Parse/Syslog.pm:${PORTSDIR}/textproc/p5-Parse-Syslog \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Net/CIDR/Lite.pm:${PORTSDIR}/net/p5-Net-CIDR-Lite
TOOLS=		""
.else
TOOLS=		"@comment "
.endif

MAN3=		Mail::SpamAssassin.3 \
		Mail::SpamAssassin::ArchiveIterator.3 \
		Mail::SpamAssassin::AutoWhitelist.3 \
		Mail::SpamAssassin::Bayes.3 \
		Mail::SpamAssassin::BayesStore.3 \
		Mail::SpamAssassin::BayesStore::MySQL.3 \
		Mail::SpamAssassin::BayesStore::PgSQL.3 \
		Mail::SpamAssassin::BayesStore::SQL.3 \
		Mail::SpamAssassin::Client.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::Conf::LDAP.3 \
		Mail::SpamAssassin::Conf::Parser.3 \
		Mail::SpamAssassin::Conf::SQL.3 \
		Mail::SpamAssassin::DnsResolver.3 \
		Mail::SpamAssassin::Logger.3 \
		Mail::SpamAssassin::Logger::File.3 \
		Mail::SpamAssassin::Logger::Stderr.3 \
		Mail::SpamAssassin::Logger::Syslog.3 \
		Mail::SpamAssassin::Message.3 \
		Mail::SpamAssassin::Message::Metadata.3 \
		Mail::SpamAssassin::Message::Node.3 \
		Mail::SpamAssassin::PerMsgLearner.3 \
		Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::PersistentAddrList.3 \
		Mail::SpamAssassin::Plugin.3 \
		Mail::SpamAssassin::Plugin::AWL.3 \
		Mail::SpamAssassin::Plugin::AccessDB.3 \
		Mail::SpamAssassin::Plugin::AntiVirus.3 \
		Mail::SpamAssassin::Plugin::AutoLearnThreshold.3 \
		Mail::SpamAssassin::Plugin::DCC.3 \
		Mail::SpamAssassin::Plugin::DomainKeys.3 \
		Mail::SpamAssassin::Plugin::Hashcash.3 \
		Mail::SpamAssassin::Plugin::MIMEHeader.3 \
		Mail::SpamAssassin::Plugin::Pyzor.3 \
		Mail::SpamAssassin::Plugin::Razor2.3 \
		Mail::SpamAssassin::Plugin::RelayCountry.3 \
		Mail::SpamAssassin::Plugin::ReplaceTags.3 \
		Mail::SpamAssassin::Plugin::SPF.3 \
		Mail::SpamAssassin::Plugin::SpamCop.3 \
		Mail::SpamAssassin::Plugin::Test.3 \
		Mail::SpamAssassin::Plugin::TextCat.3 \
		Mail::SpamAssassin::Plugin::URIDNSBL.3 \
		Mail::SpamAssassin::Plugin::WhiteListSubject.3 \
		Mail::SpamAssassin::PluginHandler.3 \
		Mail::SpamAssassin::SQLBasedAddrList.3 \
		Mail::SpamAssassin::SubProcBackChannel.3 \
		Mail::SpamAssassin::Timeout.3 \
		Mail::SpamAssassin::Util.3 \
		Mail::SpamAssassin::Util::Progress.3 \
		spamassassin-run.3

MAN1=		spamd.1 spamassassin.1 spamc.1 sa-learn.1 sa-update.1 \
		spamassassin-run.1

PLIST_SUB+=	TOOLS=${TOOLS}

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/spamassassin
DOCS=		BUGS CREDITS Changes INSTALL LICENSE NOTICE PACKAGING README STATUS TRADEMARK UPGRADE USAGE procmailrc.example
DOCSSQL=	README README.awl README.bayes awl_mysql.sql awl_pg.sql bayes_mysql.sql bayes_pg.sql userpref_mysql.sql userpref_pg.sql
DOCSCONTRIB=	mbox-to-check run-corpora run-masses
DOCSLDAP=	README README.testing sa_test.ldif
PORTDOCS=	${DOCS} sql contrib ldap

USE_RC_SUBR=	sa-spamd.sh

.if defined(WITH_MYSQL) || defined(WITH_PGSQL)
SUB_LIST+=	SQL_FLAG="-Q"
.else
SUB_LIST+=	SQL_FLAG=""
.endif
.if !defined(WITH_AS_ROOT)
SUB_LIST+=	RUN_AS_USER="-u spamd -H /var/spool/spamd"
.else
SUB_LIST+=	RUN_AS_USER=""
.endif

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${REINPLACE_CMD} -e 's#B_CONFDIR)/local.cf#B_CONFDIR)/local.cf.sample#g' \
		-e 's#B_CONFDIR)/init.pre#B_CONFDIR)/init.pre.sample#g' \
		-e 's#B_CONFDIR)/v310.pre#B_CONFDIR)/v310.pre.sample#g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL
.if defined(WITH_RAZOR)
	${REINPLACE_CMD} -e '/Razor2/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v310.pre
.endif
.if defined(WITH_DOMAINKEYS)
	${REINPLACE_CMD} -e '/DomainKeys/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/v310.pre
.endif
.if defined(WITH_RELAY_COUNTRY)
	${REINPLACE_CMD} -e '/RelayCountry/s/^#loadplugin/loadplugin/' ${WRKSRC}/rules/init.pre
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/spamc
	@[ -f ${PREFIX}/etc/mail/spamassassin/init.pre ] || \
		${CP} ${PREFIX}/etc/mail/spamassassin/init.pre.sample \
			${PREFIX}/etc/mail/spamassassin/init.pre
	@[ -f ${PREFIX}/etc/mail/spamassassin/v310.pre ] || \
		${CP} ${PREFIX}/etc/mail/spamassassin/v310.pre.sample \
			${PREFIX}/etc/mail/spamassassin/v310.pre
.if defined(WITH_TOOLS)
	@${MKDIR} ${DATADIR}/tools
	@for f in ${WRKSRC}/tools/*; do \
		${INSTALL} $${f} ${DATADIR}/tools; \
	done
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/sql ${DOCSDIR}/contrib ${DOCSDIR}/ldap
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCSSQL:S|^|${WRKSRC}/sql/|} ${DOCSDIR}/sql
	@${INSTALL_DATA} ${DOCSCONTRIB:S|^|${WRKSRC}/contrib/|} ${DOCSDIR}/contrib
	@${INSTALL_DATA} ${DOCSLDAP:S|^|${WRKSRC}/ldap/|} ${DOCSDIR}/ldap

.endif
	@${SED} -e 's#PREFIX#${PREFIX}#' ${PKGMESSAGE}

.if ${PERL_LEVEL} < 500600
IGNORE=	needs perl 5.6.1 or higher, install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
