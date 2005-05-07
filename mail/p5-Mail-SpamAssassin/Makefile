# New ports collection makefile for:	p5-Mail-SpamAssassin
# Date created:				Nov 26 2001
# Whom:					Anthony Kim
#
# $FreeBSD$
#

PORTNAME=	Mail-SpamAssassin
PORTVERSION=	3.0.3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:apache/} ${MASTER_SITE_PERL_CPAN:S/$/:cpan/}
MASTER_SITE_SUBDIR=	spamassassin/:apache Mail/:cpan
PKGNAMEPREFIX=	p5-
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:apache,cpan

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A highly efficient mail filter for identifying spam

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/Mail/Internet.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS} \
		razor-client:${PORTSDIR}/mail/razor-agents

PERL_CONFIGURE=	yes
CONFIGURE_ARGS=	SYSCONFDIR="${PREFIX}/etc" \
	       	CONTACT_ADDRESS="the administrator of that system" \
		BUILD_SPAMC=yes RUN_NET_TESTS=yes

.if defined(WITH_SPF_QUERY)
RUN_DEPENDS+=	spfd:${PORTSDIR}/mail/p5-Mail-SPF-Query
.endif

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}
CONFIGURE_ARGS+=	ENABLE_SSL=yes
.else
CONFIGURE_ARGS+=	ENABLE_SSL=no
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
USE_SQLDB=	yes
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
USE_SQLDB=	yes
.endif

MAN3=		Mail::SpamAssassin.3 \
		Mail::SpamAssassin::ArchiveIterator.3 \
		Mail::SpamAssassin::AutoWhitelist.3 \
		Mail::SpamAssassin::Bayes.3 \
		Mail::SpamAssassin::BayesStore.3 \
		Mail::SpamAssassin::BayesStore::SQL.3 \
		Mail::SpamAssassin::Conf.3 \
		Mail::SpamAssassin::Conf::LDAP.3 \
		Mail::SpamAssassin::Conf::Parser.3 \
		Mail::SpamAssassin::Conf::SQL.3 \
		Mail::SpamAssassin::Message.3 \
		Mail::SpamAssassin::Message::Metadata.3 \
		Mail::SpamAssassin::Message::Node.3 \
		Mail::SpamAssassin::PerMsgLearner.3 \
		Mail::SpamAssassin::PerMsgStatus.3 \
		Mail::SpamAssassin::PersistentAddrList.3 \
		Mail::SpamAssassin::Plugin.3 \
		Mail::SpamAssassin::Plugin::Hashcash.3 \
		Mail::SpamAssassin::Plugin::RelayCountry.3 \
		Mail::SpamAssassin::Plugin::SPF.3 \
		Mail::SpamAssassin::Plugin::URIDNSBL.3 \
		Mail::SpamAssassin::PluginHandler.3 \
		Mail::SpamAssassin::SQLBasedAddrList.3

MAN1=		spamd.1 spamassassin.1 spamc.1 sa-learn.1

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/spamassassin
DOCS=		BUGS CREDITS Changes INSTALL LICENSE NOTICE PACKAGING README STATUS TRADEMARK UPGRADE USAGE procmailrc.example
DOCSSQL=	README README.awl README.bayes awl_mysql.sql awl_pg.sql bayes_mysql.sql bayes_pg.sql userpref_mysql.sql userpref_pg.sql
DOCSCONTRIB=	mbox-to-check run-corpora run-masses
DOCSLDAP=	README README.testing sa_test.ldif
PORTDOCS=	${DOCS} sql contrib ldap

USE_RC_SUBR=	yes
SED_SCRIPT=	-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%RC_SUBR%%|${RC_SUBR}|g'
.if defined(USE_SQLDB)
SED_SCRIPT+=	-e 's|%%SQL_FLAG%%|-Q|g'
.else
SED_SCRIPT+=	-e 's|%%SQL_FLAG%%||g'
.endif

pre-patch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "================================================================"
	@${ECHO_MSG} "You can use folowed options to install SpamAssassin with"
	@${ECHO_MSG} "	an addition features:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITHOUT_SSL=yes	 - disable SSL,"
	@${ECHO_MSG} "WITH_MYSQL=yes	 - add MySQL support,"
	@${ECHO_MSG} "WITH_PGSQL=yes	 - add PostgreSQL support,"
	@${ECHO_MSG} "WITH_SPF_QUERY=yes - add SPF query support."
	@${ECHO_MSG} "================================================================"
	@${ECHO_MSG} ""

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${SED} -e 's#B_CONFDIR)/local.cf#B_CONFDIR)/local.cf.sample#g' \
		-e 's#B_CONFDIR)/init.pre#B_CONFDIR)/init.pre.sample#g' \
		-e 's/require DBI/0/' \
		${WRKSRC}/Makefile.PL > ${WRKSRC}/Makefile.PL.sed
	@${MV} ${WRKSRC}/Makefile.PL.sed ${WRKSRC}/Makefile.PL

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/spamd.sh > ${WRKDIR}/sa-spamd.sh

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/spamc
	@${INSTALL_SCRIPT} ${WRKDIR}/sa-spamd.sh ${PREFIX}/etc/rc.d/sa-spamd.sh
	@[ -f ${PREFIX}/etc/mail/spamassassin/init.pre ] || \
		${CP} ${PREFIX}/etc/mail/spamassassin/init.pre.sample \
			${PREFIX}/etc/mail/spamassassin/init.pre
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/sql ${DOCSDIR}/contrib ${DOCSDIR}/ldap
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCSSQL:S|^|${WRKSRC}/sql/|} ${DOCSDIR}/sql
	@${INSTALL_DATA} ${DOCSCONTRIB:S|^|${WRKSRC}/contrib/|} ${DOCSDIR}/contrib
	@${INSTALL_DATA} ${DOCSLDAP:S|^|${WRKSRC}/ldap/|} ${DOCSDIR}/ldap

.endif
	@${SED} -e 's#PREFIX#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Needs perl 5.6.1 or higher, install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
.endif

.include <bsd.port.post.mk>
