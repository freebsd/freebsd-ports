# New ports collection makefile for:	dspam-devel
# Date created:		24 Jun 2004
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	dspam-devel
PORTVERSION=	3.1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/ \
		http://people.tecnik93.com/~itetcu/FreeBSD/ports/dspam-devel/sources/
DISTFILES=	dspam-${PORTVERSION}.tar.gz

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Bayesian spam filter - development version

WRKSRC=		${WRKDIR}/dspam-${PORTVERSION}

## debug / log options
OPTIONS=	DEBUG "Enable debug in DSPAM_HOME/dspam.debug" on
OPTIONS+=	VERBOSE_DEBUG "Enable verbose debug" off
OPTIONS+=	USER_LOGGING	"Log mail in DSPAM_HOME/data/user/user.log" off
OPTIONS+=	SYSTEM_LOGGING	"Log some info DSPAM_HOME/system.log" on
OPTIONS+=	SAT "Log spam source addresses to syslog" on
## algorithm options
OPTIONS+=	TRAD_BAYES "Enable traditional-bayesian" on
OPTIONS+=	ALT_BAYES "Enable alternative-bayesian" on
OPTIONS+=	RNB "Use Robinson Naive Bayesian calculation" off
OPTIONS+=	CHI_SQUARE "Use Fisher-Robinson Inv Chi-Square" off
OPTIONS+=	RPV "Use Robinson technique combining p-values" off
OPTIONS+=	TEST_COND "More inoculous results rapidly, risk fps" on
OPTIONS+=	NO_BIAS "No bias toward innocent mail" off
OPTIONS+=	WHITELIST "Automatic whitelisting of ham" off
OPTIONS+=	NEURAL_NET "Enable neural networking" off
## run-time configure  options
OPTIONS+=	HOMEDIR_DOT "Dot files in ~/USER not DSPAM_HOME" off
OPTIONS+=	OPT_IN "Run only for users with .dspam" off
OPTIONS+=	TRUSTED_USERS "Disable trusted user security" off
## mesage taging options
OPTIONS+=	SPAM_SUBJ "Prepends SPAM to the Subject header" off
OPTIONS+=	SIGNATURE_HEADERS "Put signatures IDs in the header" off
OPTIONS+=	WEBMAIL "Only with mail stored server-side" off
## back-end
OPTIONS+=	MYSQL "Use MySQL as back-end" off
OPTIONS+=	MYSQL_COMPRESS "Compress dspam <--> MySQL" off
OPTIONS+=	POSTGRESQL73 "Use PostgreSQL v.7.3 as back-end" off
OPTIONS+=	POSTGRESQL74 "Use PostgreSQL v.7.4 as back-end" off
#OPTIONS+=	PGSQL_INSTALLED "You have the client installed" on
OPTIONS+=	ORACLE "Use Oracle as back-end (BROKEN)" off
OPTIONS+=	BDB4 "Use BDB4 as back-end (not recomanded)" off
OPTIONS+=	SQLITE "Use SQLite as back-end" on
OPTIONS+=	VIRT_USERS "Enable virtual users (needs SQL back-end)" off
OPTIONS+=	LONG_USERNAMES "Usernames longer that OS supports" off
OPTIONS+=	LARGE_SCALE "File structure for large scale" off
OPTIONS+=	DOMAIN_SCALE "File structure for multiple domains" off
OPTIONS+=	SIGNATURE_ATACH "Put server-side signature in mails" off
## MTA and LDA
OPTIONS+=	MAILDROP "Use Maildrop as local delivery agent" off
OPTIONS+=	PROCMAIL "Use Procmail as local delivery agent" off
OPTIONS+=	CYRUS_LDA "Use Cyrus's 1.6 deliver as LDA" off
OPTIONS+=	CYRUS21_LDA "Use Cyrus's 2.1 deliver as LDA" off
OPTIONS+=	CYRUS22_LDA "Use Cyrus's 2.2 deliver as LDA" off
OPTIONS+=	SENDMAIL_LDA "Use Sendmail as local delivery agent" off
OPTIONS+=	SENDMAIL "Play nice with sendmail server" off
OPTIONS+=	POSTFIX_MBC "Dspam as mailbox_command in Postfix" off
OPTIONS+=	QMAIL "Play nice with Qmail mail server" off
OPTIONS+=	BROKEN_ERR_CODES "99=spam, 0=not, other=error (qmailish)" off
OPTIONS+=	BROKEN_MTA "Enable if MTA pases ^M to dspam" off
OPTIONS+=	CGI "Install CGI (pulls in apache)" off

USE_GNOME=	pkgconfig
USE_INC_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

CONFLICTS=	dspam-2* dspam-3*

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g'

WITH_SIGNATURE_LIFE?=	15

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.else
CONFIGURE_ARGS+=	--disable-debug
.endif

.if defined(WITH_VERBOSE_DEBUG)
CONFIGURE_ARGS+=	--enable-verbose-debug
.else
CONFIGURE_ARGS+=	--disable-verbose-debug
.endif

.if defined(WITH_SYSTEM_LOGGING)
CONFIGURE_ARGS+=	--enable-logging
.else
CONFIGURE_ARGS+=	--disable-system-logging
.endif

.if defined(WITH_USER_LOGGING)
CONFIGURE_ARGS+=	--enable-user-logging
.else
CONFIGURE_ARGS+=	--disable-user-logging
.endif

.if defined(WITH_SAT)
CONFIGURE_ARGS+=	--enable-source-address-tracking
.endif

.if defined(WITH_TRAD_BAYES)
CONFIGURE_ARGS+=	--enable-traditional-bayesian
HAVE_ALG=yes
.else
CONFIGURE_ARGS+=	--disable-traditional-bayesian
.endif

.if defined(WITH_ALT_BAYES)
CONFIGURE_ARGS+=	--enable-alternative-bayesian
HAVE_ALG=yes
.else
CONFIGURE_ARGS+=	--disable-alternative-bayesian
.endif

.if defined(WITH_RNB)
CONFIGURE_ARGS+=	 --enable-robinson
HAVE_ALG=yes
.else
CONFIGURE_ARGS+=	 --disable-robinson
.endif

.if defined(WITH_CHI_SQUARE)
CONFIGURE_ARGS+=	 --enable-robinson
HAVE_ALG=yes
.else
CONFIGURE_ARGS+=	 --disable-robinson
.endif

.if defined(WITH_RPV)
CONFIGURE_ARGS+=	 --enable-robinson-pvalues
HAVE_ALG=yes
.else
CONFIGURE_ARGS+=	 --disable-robinson-pvalues
.endif

# redundant with options for BATCH=yes and no OPTIONS defined builds
.if !defined(HAVE_ALG) && defined(BATCH)
CONFIGURE_ARGS+=	--enable-traditional-bayesian
CONFIGURE_ARGS+=	--enable-alternative-bayesian
.endif

.if defined(WITH_TEST_COND)
CONFIGURE_ARGS+=	 --enable-test-conditional
.else
CONFIGURE_ARGS+=	 --disable-test-conditional
.endif

.if defined(WITH_NO_BIAS)
CONFIGURE_ARGS+=	--disable-bias
.endif

.if defined(WITH_WHITELIST)
CONFIGURE_ARGS+=	--enable-whitelist
.endif

.if defined(WITH_NEURAL_NET)
CONFIGURE_ARGS+=	--enable-neural-networking
.endif

.if defined(WITH_HOMEDIR_DOT)
CONFIGURE_ARGS+=	  --enable-homedir-dotfiles
.endif

.if defined(WITH_OPT_IN)
CONFIGURE_ARGS+=	  --enable-opt-in
.endif

.if defined(WITH_TRUSTED_USERS)
CONFIGURE_ARGS+=	--disable-trusted-user-security
.endif

.if defined(WITH_SPAM_SUBJ)
CONFIGURE_ARGS+=	--enable-spam-subject
.endif

.if defined(WITH_SIGNATURE_HEADERS)
CONFIGURE_ARGS+=	--enable-signature-headers
.endif

.if defined(SIGNATURE_ATACH)
CONFIGURE_ARGS+=	--enable-signature-attachments
.endif

.if defined(WITH_WEBMAIL)
CONFIGURE_ARGS+=	--enable-webmail
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-storage-driver=mysql_drv \
		--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL=""
PLIST_SUB+=	PGSQL="@comment "
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e 's,%%MYSQL%%,,g'
SED_SCRIPT+=	-e '/%%PGSQL%%/D'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
.if defined(WITH_MYSQL_COMPRESS)
CONFIGURE_ARGS+=	--enable-client-compression
.endif
.endif

.if defined(WITH_POSTGRESQL73)
LIB_DEPENDS=	pq.3:${PORTSDIR}/databases/postgresql73
#BUILD_DEPENDS= ${LIB_DEPENDS}
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv \
		--with-pgsql-includes=${LOCALBASE}/include \
		--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL=""
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
.endif

.if defined(WITH_POSTGRESQL74)
LIB_DEPENDS=	ecpg.4:${PORTSDIR}/databases/postgresql7
#BUILD_DEPENDS=	${LIB_DEPENDS}
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv \
		--with-pgsql-includes=${LOCALBASE}/include \
		--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL=""
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS=	${LOCALBASE}/oracle7/rdbms/lib/libnlsrtl3.a:\
	${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS+=	--with-storage-driver=ora_drv \
		--with-oracle-home=	${LOCALBASE}/oracle7
.endif

.if defined(WITH_BDB)
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--with-storage-driver=libdb4_drv \
	--with-db4-includes=${LOCALBASE}/include/db41
PLIST_SUB+=	DB4=""
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL="@comment "
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e '/%%PGSQL%%/D'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
.endif

.if !(defined(WITH_MYSQL) || defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74) || defined(WITH_ORACLE) || defined(WITH_BDB))
WITH_SQLITE=	on
LIB_DEPENDS+=	sqlite.2:${PORTSDIR}/databases/sqlite
CONFIGURE_ARGS+=	--with-storage-driver=sqlite_drv \
	--with-sqlite-includes=${LOCALBASE}/include \
	--with-sqlite-libraries=${LOCALBASE}/lib
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL="@comment "
PLIST_SUB+=	SQLITE=""
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e '/%%PGSQL%%/D'
SED_SCRIPT+=	-e 's,%%SQLITE%%,,g'
.endif

.if defined(WITH_VIRT_USERS)
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

.if defined(WITH_LONG_USERNAMES)
CONFIGURE_ARGS+=	--enable-long-usernames
.endif
.if defined(WITH_LARGE_SCALE)
CONFIGURE_ARGS+=	--enable-large-scale
.endif
.if defined(WITH_DOMAIN_SCALE)
CONFIGURE_ARGS+=	--enable-domain-scale
.endif

.if defined(WITH_MAILDROP)
RUN_DEPENDS+=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/maildrop $u'
.endif

.if defined(WITH_PROCMAIL)
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/procmail $u'
.endif

.if defined(WITH_SENDMAIL_LDA) && exists(/usr/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent=/usr/sbin/sendmail
.else
.if defined(WITH_SENDMAIL_LDA) && exists(${LOCALBASE}/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/sendmail'
.endif
.endif

.if defined(WITH_CYRUS_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus
CONFIGURE_ARGS+=\
--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver -e -r $${sender} -m $${extension} $${user} $$u'
.endif

.if defined(WITH_CYRUS21_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd2
CONFIGURE_ARGS+=\
--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver -e -r $${sender} -m $${extension} $${user} $$u'
.endif

.if defined(WITH_CYRUS22_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd22
CONFIGURE_ARGS+=\
--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver -e -r $${sender} -m $${extension} $${user} $$u"
.endif

.if defined(WITH_SENDMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_POSTFIX_MBC)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
SED_SCRIPT+=	-e 's,%%POSTFIX_MBC%%,,g'
.else
SED_SCRIPT+=	-e '/%%POSTFIX_MBC%%/D'
.endif

.if defined(WITH_QMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_BROKEN_ERR_CODES)
CONFIGURE_ARGS+=	--enable-broken-return-codes
.endif

.if defined(DSPAM_HOME)
CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}
.else
CONFIGURE_ARGS+=	--with-dspam-home=${PREFIX}/etc/dspam
DSPAM_HOME=	${PREFIX}/etc/dspam
.endif

.if defined(DSPAM_OWNER)
CONFIGURE_ARGS+=	--with-dspam-home-owner=${DSPAM_OWNER}
.endif

.if defined(DSPAM_GROUP)
CONFIGURE_ARGS+=	--with-dspam-home-group=${DSPAM_GROUP}
.endif

.if defined(WITH_BROKEN_MTA)
CONFIGURE_ARGS+=	--enable-broken-mta
.endif

.if defined(WITH_SIGNATURE_LIFE)
CONFIGURE_ARGS+=	--with-signature-life=${WITH_SIGNATURE_LIFE}
.endif

.if defined(QUARANTINE_AGENT)
CONFIGURE_ARGS+=	--with-quarantine-agent=${QUARANTINE_AGENT}
.endif

.if defined(WITH_CGI)
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS+=	${LOCALBASE}/sbin/apachectl:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS+=	${SITE_PERL}/mach/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS+=	${SITE_PERL}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d
RUN_DEPENDS+=	${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
USE_PERL5_RUN=	yes
PLIST_SUB+=	CGI=""
.if !defined(CGI_PATH)
CGI_PATH=	${PREFIX}/www/vhosts/dspam
.endif
SED_SCRIPT+=	-e 's,%%CGI%%,,g'
SED_SCRIPT+=	-e 's,%%CGI_PATH%%,${CGI_PATH},g'
SED_SCRIPT+=	-e 's,%%DSPAM_HOME%%,${DSPAM_HOME},g'
#SED_FILES=      ${LS} ${WRKSRC}/cgi/*.pl
#SED_FILES+=     ${LS} $PWRKSRC}/cgi/*.cgi
.else
PLIT_SUB+=	CGI="@comment "
.endif

MAN1=	dspam.1 dspam_clean.1 dspam_corpus.1 dspam_dump.1 dspam_merge.1 \
	dspam_stats.1

DOCS=	CHANGELOG README LICENSE RELEASE.NOTES

pre-everything::
	@${ECHO_CMD} "Define vars below before make-ing if you need:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WITH_SIGNATURE_LIFE (default 15)"
	@${ECHO_CMD} "DSPAM_OWNER (default: root)"
	@${ECHO_CMD} "DSPAM_GROUP (default: mail)"
	@${ECHO_CMD} "DSPAM_HOME (default: ${PREFIX}/etc/dspam)"
	@${ECHO_CMD} "QUARANTINE_AGENT (default: -)"
.if defined(WITH_CGI)
	@${ECHO_CMD} "Define CGI_PATH before make-ing if you need the CGI files"
	@${ECHO_CMD} "installed in other place that this installation's default"
	@${ECHO_CMD} "${PREFIX}/www/vhosts/dspam"
.endif
	@${ECHO_CMD} ""
	@${ECHO_CMD} "I hope you selected  only 1 database beck-end above"
	@${ECHO_CMD} ""
	@sleep 5
post-patch:
	@${REINPLACE_CMD} -e 's|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g ; \
		s|-ldb-4.1|-ldb41|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
	${WRKSRC}/Makefile.in

pre-configure:
.if defined(WITH_MAILDROP) && (defined(WITH_PROCMAIL) || defined(WITH_SENDMAIL_LDA))
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${FALSE}
.endif
.if defined(WITH_PROCMAIL) && (defined(WITH_MAILDROP) || defined(WITH_SENDMAIL_LDA))
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${FALSE}
.endif
.if defined(WITH_NEURAL_NET) && !(defined(WITH_MYSQL) || defined(WITH_POSTGRESQL))
	@${ECHO_CMD} "You need MySQL or POSTGRESQL to use neural networking."
	@${FALSE}
.endif
.if defined(WITH_VIRT_USERS) && !(defined(WITH_MYSQL) || \
	defined(WITH_POSTGRESQL) || defined(WITH_ORACLE))
	@${ECHO_CMD} "You need MySQL, POSTGRESQL or ORACLE for virtual users."
	@${FALSE}
.endif

post-install:
.if defined(WITH_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}/mysql
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README *.sql* ${EXAMPLESDIR}/mysql
	@${INSTALL_DATA} ${FILESDIR}/mysql.data ${EXAMPLESDIR}/mysql
	@${INSTALL_DATA} ${FILESDIR}/2x_to_3x_db.sql ${EXAMPLESDIR}/mysql
.endif
.if defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74)
	@${MKDIR} ${EXAMPLESDIR}/pgsql
	cd @${WRKSRC}/tools.pgsql_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/pgsql
	${INSTALL_DATA} ${FILESDIR}/pgsql.data ${EXAMPLESDIR}/pgsql
.endif
.if defined(WITH_SQLITE)
	@${MKDIR} ${EXAMPLESDIR}/sqlite
	cd ${WRKSRC}/tools.sqlite_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/sqlite
.endif

.if defined(WITH_CGI)
.for I in admin.cgi admingraph.cgi configure.pl dspam.cgi graph.cgi
	@${SED} -i '' -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/cgi/${I}
.endfor
	cd ${WRKSRC}/cgi && ${MKDIR} ${CGI_PATH} && \
		${INSTALL_SCRIPT} *.pl ${CGI_PATH}/ && \
		${INSTALL_SCRIPT} *.cgi ${CGI_PATH}
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} base.css logo.gif rgb.txt ${CGI_PATH}/
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} default.prefs ${CGI_PATH}/default.prefs.sample
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} admins ${CGI_PATH}/admins.sample
	@${MKDIR} ${CGI_PATH}/templates && cd ${WRKSRC}/cgi/templates && \
		${INSTALL_DATA} *.html ${CGI_PATH}/templates/
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} ${SED_SCRIPT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
