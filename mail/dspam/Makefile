# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	3.0.0
CATEGORIES=	mail
MASTER_SITES=	http://www.nuclearelephant.com/projects/dspam/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	A server-side bayesian spam filter

## debug / log options
OPTIONS=	NO_CONFLICTS "DO NOT conflict with dspam-2.x" off
OPTIONS+=	DEBUG "Enable debug in DSPAM_HOME/dspam.debug" on
OPTIONS+=	VERBOSE_DEBUG "Enable verbose debug" on
OPTIONS+=	USER_LOGGING	"Log mail in DSPAM_HOME/data/user/user.log" on
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
OPTIONS+=	VIRT_USERS "Enable virtual users (needs SQL back-end)" off
OPTIONS+=	LONG_USERNAMES "Usernames longer that OS supports" off
OPTIONS+=	LARGE_SCALE "File structure for large scale" off
OPTIONS+=	DOMAIN_SCALE "File structure for multiple domains" off
OPTIONS+=	SIGNATURE_ATACH "Put server-side signature in mails" off
## MTA and LDA
OPTIONS+=	MAILDROP "Use Maildrop as local delivery agent" off
OPTIONS+=	PROCMAIL "Use Procmail as local delivery agent" off
OPTIONS+=	SENDMAIL_LDA "Use Sendmail as local delivery agent" off
OPTIONS+=	SENDMAIL "Play nice with sendmail server" off
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

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g'

WITH_SIGNATURE_LIFE?=	28

.include <bsd.port.pre.mk>

.if !defined(WITH_NO_CONFLICTS)
CONFLICTS=	dspam-2*
.endif

.if defined(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--disable-debug
.else
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITHOUT_VERBOSE_DEBUG)
CONFIGURE_ARGS+=	--disable-verbose-debug
.else
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif

.if defined(WITHOUT_SYSTEM_LOGGING)
CONFIGURE_ARGS+=	--disable-system-logging
.else
CONFIGURE_ARGS+=	--enable-logging
.endif

.if defined(WITHOUT_USER_LOGGING)
CONFIGURE_ARGS+=	--disable-user-logging
.else
CONFIGURE_ARGS+=	--enable-user-logging
.endif

.if !defined(WITHOUT_SAT)
CONFIGURE_ARGS+=	--enable-source-address-tracking
.endif

.if defined(WITHOUT_TRAD_BAYES)
CONFIGURE_ARGS+=	--disable-traditional-bayesian
.else
CONFIGURE_ARGS+=	--enable-traditional-bayesian
.endif

.if defined(WITHOUT_ALT_BAYES)
CONFIGURE_ARGS+=	--disable-alternative-bayesian
.else
CONFIGURE_ARGS+=	--enable-alternative-bayesian
.endif

.if defined(WITH_RNB)
CONFIGURE_ARGS+=	 --enable-robinson
.else
CONFIGURE_ARGS+=	 --disable-robinson
.endif

.if defined(WITH_CHI_SQUARE)
CONFIGURE_ARGS+=	 --enable-robinson
.else
CONFIGURE_ARGS+=	 --disable-robinson
.endif

.if defined(WITH_RPV)
CONFIGURE_ARGS+=	 --enable-robinson-pvalues
.else
CONFIGURE_ARGS+=	 --disable-robinson-pvalues
.endif

.if defined(WITHOUT_TEST_COND)
CONFIGURE_ARGS+=	 --disable-test-conditional
.else
CONFIGURE_ARGS+=	 --enable-test-conditional
.endif

.if defined(WITH_NO_BIAS)
CONFIGURE_ARGS+=	--disable-bias
.endif

.if defined(WITH_WHITELIST)
CONFIGURE_ARGS+=	--enable-whitelist
.endif

.if defined(WITH_NEURAL_NET)
CONFIGURE_ARGS+=	--enable-neural-networking
#NEED_M_P=. @${TRUE}
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
SED_SCRIPT+=	-e 's,%%MYSQL%%,,g'
SED_SCRIPT+=	-e '/%%PGSQL%%/D'
.if defined(WITH_MYSQL_COMPRESS)
CONFIGURE_ARGS+=	--enable-client-compression
.endif
.endif

.if defined(WITH_POSTGRESQL73)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql73
#BUILD_DEPENDS= ${LIB_DEPENDS}
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv \
		--with-pgsql-includes=${LOCALBASE}/include \
		--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL=""
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
.endif

.if defined(WITH_POSTGRESQL74)
LIB_DEPENDS+=	ecpg.4:${PORTSDIR}/databases/postgresql7
#BUILD_DEPENDS=	${LIB_DEPENDS}
CONFIGURE_ARGS+=	--with-storage-driver=pgsql_drv \
		--with-pgsql-includes=${LOCALBASE}/include \
		--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	DB4="@comment "
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL=""
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS+=	${LOCALBASE}/oracle7/rdbms/lib/libnlsrtl3.a:${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS+=	--with-storage-driver=ora_drv \
		--with-oracle-home=	${LOCALBASE}/oracle7
.endif

.if defined(WITH_VIRT_USERS)
CONFIGURE_ARGS+=	--enable-virtual-users
#NEED_M_P=. @${TRUE}
.endif

.if !(defined(WITH_MYSQL) || defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74) || defined(WITH_ORACLE))
LIB_DEPENDS+=	db41.1:${PORTSDIR}/databases/db41
CONFIGURE_ARGS+=	--with-db4-includes=${LOCALBASE}/include/db41
PLIST_SUB+=	DB4=""
PLIST_SUB+=	MYSQL="@comment "
PLIST_SUB+=	PGSQL="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e '/%%PGSQL%%/D'
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

.if defined(WITH_SENDMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_QMAIL)
CONFIGURE_ARGS+=	--with-dspam-mode=4511
.endif

.if defined(WITH_BROKEN_ERR_CODES)
CONFIGURE_ARGS+=	--enable-broken-return-codes
.endif

.if defined(DSPAM_HOME)
CONFIGURE_ARGS+=--with-dspam-home=${DSPAM_HOME}
.else
CONFIGURE_ARGS+=--with-dspam-home=${PREFIX}/etc/dspam
.endif

#  --with-dspam-home=DIR	  Specify directory where per-user dictionaries
#  --with-dspam-home-mode=MODE   Set access mode for DSPAM_HOME
#  --with-dspam-home-owner=OWNER  Set owner for DSPAM_HOME
#  --with-dspam-home-group=GROUP  Set group for DSPAM_HOME

#  --with-dspam-mode=MODE         Set access mode for dspam binary
#  --with-dspam-owner=OWNER       Set owner for dspam binary
#  --with-dspam-group=GROUP       Set group for dspam binary

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
RUN_DEPENDS+=	${LOCALBASE}/etc/apache/httpd.conf:${PORTSDIR}/${APACHE_PORT}
.endif

MAN1=	dspam.1 dspam_clean.1 dspam_corpus.1 dspam_dump.1 dspam_merge.1 dspam_stats.1

DOCS=	CHANGELOG README LICENSE RELEASE.NOTES

pre-everything::
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

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
.if defined(WITH_VIRT_USERS) && !(defined(WITH_MYSQL) || defined(WITH_POSTGRESQL) || defined(WITH_ORACLE))
	@${ECHO_CMD} "You need MySQL, POSTGRESQL or ORACLE for virtual users."
	@${FALSE}
.endif

post-install:
.if defined(WITH_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}/mysql
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README *.sql* ${EXAMPLESDIR}/mysql
	${INSTALL_DATA} ${FILESDIR}/mysql.data ${EXAMPLESDIR}/mysql
	${INSTALL_DATA} ${FILESDIR}/2x_to_3x_db.sql ${EXAMPLESDIR}/mysql
.endif
.if defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74)
	${MKDIR} ${EXAMPLESDIR}/pgsql
	cd ${WRKSRC}/tools.pgsql_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/pgsql
	${INSTALL_DATA} ${FILESDIR}/pgsql.data ${EXAMPLESDIR}/pgsql
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${SED} ${SED_SCRIPT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
