# New ports collection makefile for:	dspam
# Date created:			3 August 2003
# Whom:				Dominic Marks <dom@wirespeed.org.uk>
#
# $FreeBSD$
#

PORTNAME=	dspam
PORTVERSION=	3.2.3${SNAP_DATE}
CATEGORIES=	mail
MASTER_SITES=	http://people.tecnik93.com/~itetcu/FreeBSD/ports/dspam/sources/
DISTFILES=	dspam.3.2.3.cvs.stable${SNAP_DATE}.tar.gz

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Bayesian spam filter - development version

WRKSRC=		${WRKDIR}/dspam-cvs-stable${SNAP_DATE}

SNAP_DATE=	.20041203.1245

## debug / log / admin options
OPTIONS=	DEBUG "Enable debugging logging" on
OPTIONS+=	VERBOSE_DEBUG "Enable debug in LOGDIR/dspam.debug" off
#OPTIONS+=	USER_LOGGING	"Log mail in DSPAM_HOME/data/user/user.log" off
#OPTIONS+=	SYSTEM_LOGGING	"Log some info DSPAM_HOME/system.log" on
#OPTIONS+=	SAT "Log spam source addresses to syslog" on
#OPTIONS+=	PARSE_TO_HEADERS "Get user from To header on fp spam" off
OPTIONS+=	PREF_EXT "Preferences in database not in files" off

## algorithm options
OPTIONS+=	GRAHAM_BAYES "Enable Graham (traditional) bayesian" on
OPTIONS+=	BURTON_BAYES "Enable Burton (alternative) bayesian" on
OPTIONS+=	RNB "Use Robinson Naive Bayesian calculation" off
OPTIONS+=	CHI_SQUARE "Use Fisher-Robinson Inv Chi-Square" off
OPTIONS+=	RPV "Use Robinson technique combining p-values" off
OPTIONS+=	TEST_COND "More inoculous results rapidly, risk fps" on
OPTIONS+=	NO_BIAS "No bias toward innocent mail" off
OPTIONS+=	WHITELIST "Automatic whitelisting of ham" off
OPTIONS+=	NEURAL_NET "Enable neural networking" off

## run-time configure  options
#OPTIONS+=	HOMEDIR_DOT "Dot files in ~/USER not DSPAM_HOME" off
OPTIONS+=	USER_HOMEDIR "Store user data in ~/.dspam" off
#OPTIONS+=	OPT_IN "Run only for users with .dspam" off
OPTIONS+=	TRUSTED_USERS "Disable trusted user security" off

## mesage taging options
#OPTIONS+=	SPAM_SUBJ "Prepends SPAM to the Subject header" off
#OPTIONS+=	SIGNATURE_HEADERS "Put signatures IDs ONLY in headers" off
#OPTIONS+=	WEBMAIL "Only with mail stored server-side" off

## back-end
OPTIONS+=	MYSQL40 "Use MySQL 4.0.x as back-end" off
OPTIONS+=	MYSQL41 "Use MySQL 4.1.x as back-end" off
OPTIONS+=	MYSQL50 "Use MySQL 5.0.x as back-end" off
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
#OPTIONS+=	SIGNATURE_ATACH "Put server-side signature in mails" off

## MTA and LDA
OPTIONS+=	CYRUS21_LDA "Use Cyrus's 2.1 deliver as LDA" off
OPTIONS+=	CYRUS22_LDA "Use Cyrus's 2.2 deliver as LDA" off
OPTIONS+=	EXIM_LDA "Use Exim as local delivery agent" off
OPTIONS+=	MAILDROP_LDA "Use Maildrop as local delivery agent" off
OPTIONS+=	PROCMAIL_LDA "Use Procmail as local delivery agent" off
OPTIONS+=	SENDMAIL_LDA "Use Sendmail as local delivery agent" off

OPTIONS+=	SENDMAIL "Play nice with sendmail server" off
OPTIONS+=	POSTFIX_MBC "Dspam as mailbox_command in Postfix" off
OPTIONS+=	QMAIL "Play nice with Qmail mail server" off
#OPTIONS+=	BROKEN_ERR_CODES "99=spam, 0=not, other=error (qmailish)" off
#OPTIONS+=	BROKEN_MTA "Enable if MTA pases ^M to dspam" off

OPTIONS+=	CGI "Install CGI (pulls in apache)" off

#USE_GNOME=	pkgconfig lthack
#USE_INC_LIBTOOL_VER=13
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PKGMESSAGE=	${WRKSRC}/README.FreeBSD

CONFLICTS=	dspam-2* dspam-3.0*

SIGNATURE_LIFE?=	15
_VAR_DIR=	/var
LOG_DIR?=	${_VAR_DIR}/log/dspam
DSPAM_HOME?=	${_VAR_DIR}/db/dspam
DSPAM_HOME_MODE?=	0660

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-logdir=${LOG_DIR}
PLIST_SUB+=	LOG_DIR=${LOG_DIR}

CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}
PLIST_SUB+=	DSPAM_HOME=${DSPAM_HOME}

.if defined(DSPAM_HOME_OWNER)
CONFIGURE_ARGS+=	--with-dspam-home-owner=${DSPAM_HOME_OWNER}
.endif
.if defined(DSPAM_HOME_GROUP)
CONFIGURE_ARGS+=	--with-dspam-home-group=${DSPAM_HOME_GROUP}
.endif
.if defined(DSPAM_HOME_MODE)
CONFIGURE_ARGS+=	--with-dspam-home-mode=${DSPAM_HOME_MODE}
.endif

.if defined(DSPAM_OWNER)
CONFIGURE_ARGS+=	--with-dspam-owner=${DSPAM_OWNER}
.endif
.if defined(DSPAM_GROUP)
CONFIGURE_ARGS+=	--with-dspam-group=${DSPAM_HOME_GROUP}
.endif
.if defined(DSPAM_MODE)
CONFIGURE_ARGS+=	--with-dspam-mode=${DSPAM_HOME_MODE}
.endif

SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%PKGNAME%%,${PKGNAME},g' \
		-e 's,%%DSPAM_HOME%%,${DSPAM_HOME},g'

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_VERBOSE_DEBUG)
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif

# conf option
#.if defined(WITH_SYSTEM_LOGGING)
#CONFIGURE_ARGS+=	--enable-logging
#.else
#CONFIGURE_ARGS+=	--disable-system-logging
#.endif

# conf option
#.if defined(WITH_USER_LOGGING)
#CONFIGURE_ARGS+=	--enable-user-logging
#.else
#CONFIGURE_ARGS+=	--disable-user-logging
#.endif

# conf
#.if defined(WITH_SAT)
#CONFIGURE_ARGS+=	--enable-source-address-tracking
#.endif

# conf
#.if defined(PARSE_TO_HEADERS)
#CONFIGURE_ARGS+=	--enable-parse-to-headers
#.endif

.if defined(WITH_PREF_EXT)
CONFIGURE_ARGS+=	--enable-preferences-extension
.endif

.if !defined(WITH_GRAHAM_BAYES)
CONFIGURE_ARGS+=	--disable-traditional-bayesian
.endif

.if !defined(WITH_BURTON_BAYES)
CONFIGURE_ARGS+=	--disable-alternative-bayesian
.endif

.if defined(WITH_RNB)
CONFIGURE_ARGS+=	 --enable-robinson
.endif

.if defined(WITH_CHI_SQUARE)
CONFIGURE_ARGS+=	 --enable-robinson
.endif

.if defined(WITH_RPV)
CONFIGURE_ARGS+=	 --enable-robinson-pvalues
.endif

.if !defined(WITH_TEST_COND)
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

#.if defined(WITH_HOMEDIR_DOT)
#CONFIGURE_ARGS+=	  --enable-homedir-dotfiles
#.endif

.if defined(WITH_USER_HOMEDIR)
CONFIGURE_ARGS+=	--enable-homedir
## XXXXXXXX
# to check incompatibility with CGI and warn user
# to install setuid root
.endif

# conf
#.if defined(WITH_OPT_IN)
#CONFIGURE_ARGS+=	  --enable-opt-in
#.endif

.if defined(WITH_TRUSTED_USERS)
CONFIGURE_ARGS+=	--disable-trusted-user-security
.endif

# conf
#.if defined(WITH_SPAM_SUBJ)
#CONFIGURE_ARGS+=	--enable-spam-subject
#.endif

# .conf option
#.if defined(WITH_SIGNATURE_HEADERS)
#CONFIGURE_ARGS+=	--enable-signature-headers
#SED_SCRIPT+=	-e 's,%%SIGHDR%%,,g'
#.else
#SED_SCRIPT+=	-e '/%%SIGHDR%%/D'
#.endif

# not supported anymore
#.if defined(SIGNATURE_ATACH)
#CONFIGURE_ARGS+=	--enable-signature-attachments
#.endif

#.if defined(WITH_WEBMAIL)
#CONFIGURE_ARGS+=	--enable-webmail
#.endif

DBDRV_TOTAL_COUNT=	oooooooo # 8
DBDRV_COUNT=	${DBDRV_TOTAL_COUNT}

.if defined(WITH_MYSQL40)
WANT_MYSQL_VER=	40
#PKGNAMESUFFIX=	-mysql40
.elseif defined(WITH_MYSQL41)
WANT_MYSQL_VER=	41
#PKGNAMESUFFIX=	-mysql41
.elseif defined(WITH_MYSQL50)
WANT_MYSQL_VER=	50
#PKGNAMESUFFIX=	-mysql50
.endif

.if defined(WITH_MYSQL40) || defined(WITH_MYSQL41) || defined(WITH_MYSQL50)
HAVE_MYSQL=	yes
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
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
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
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
#PKGNAMESUFFIX=	-pgsql73
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
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
PLIST_SUB+=	SQLITE="@comment "
SED_SCRIPT+=	-e '/%%MYSQL%%/D'
SED_SCRIPT+=	-e 's,%%PGSQL%%,,g'
SED_SCRIPT+=	-e '/%%SQLITE%%/D'
#PKGNAMESUFFIX=	-pgsql74
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
.endif

.if defined(WITH_ORACLE)
BUILD_DEPENDS+=	${LOCALBASE}/oracle7/rdbms/lib/libnlsrtl3.a:\
	${PORTSDIR}/databases/oracle7-client
CONFIGURE_ARGS+=	--with-storage-driver=ora_drv \
		--with-oracle-home=	${LOCALBASE}/oracle7
#PKGNAMESUFFIX=	-oracle
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
.endif

.if defined(WITH_BDB4)
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
#PKGNAMESUFFIX=	-bdb
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
.endif

.if ${DBDRV_TOTAL_COUNT}==${DBDRV_COUNT} || defined(WITH_SQLITE)
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
#PKGNAMESUFFIX=	-sqlite2
DBDRV_COUNT:=	${DBDRV_COUNT:S/o//}
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

# add one 'o' here for each new LDA
LDA_TOTAL_COUNT=	ooooooo	#7
LDA_COUNT=	${LDA_TOTAL_COUNT}

.if defined(WITH_CYRUS21_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd2
#CONFIGURE_ARGS+=\
#--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver -e -r $${sender} -m $${extension} $${user} $$u'
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_CYRUS22_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd22
#CONFIGURE_ARGS+=\
#--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver -e -r $${sender} -m $${extension} $${user} $$u'
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_EXIM_LDA)
.	if defined(WITH_MYSQL40) || (WITH_MYSQL41)
_EXIM_EXT=	-mysql
.	elseif defined(WITH_POSTGRESQL74) || defined(WITH_POSTGRESQL73)
####
### fix me for pg 7.3: how to pass the db option to exim port ?
###
_EXIM_EXT=	-postgresql
.	endif
RUN_DEPENDS+=	exim:${PORTSDIR}/mail/exim${_EXIM_EXT}
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/exim'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_MAILDROP_LDA)
RUN_DEPENDS+=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/maildrop -d $$u'
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/maildrop'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_PROCMAIL_LDA)
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/procmail -d $$u'
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/procmail'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_SENDMAIL_LDA) && exists(/usr/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent=/usr/sbin/sendmail
LDA_COUNT:=	${LDA_COUNT:S/o//}
.else
.	if defined(WITH_SENDMAIL_LDA) && exists(${LOCALBASE}/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/sendmail'
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/sendmail'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.	endif
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

# conf
#.if defined(WITH_BROKEN_ERR_CODES)
#CONFIGURE_ARGS+=	--enable-broken-return-codes
#.endif

# conf
#.if defined(WITH_BROKEN_MTA)
#CONFIGURE_ARGS+=	--enable-broken-mta
#.endif

# conf option
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
CONFIGURE_ARGS+=--enable-logging
CONFIGURE_ARGS+=--enable-user-logging
USE_PERL5_RUN=	yes
PLIST_SUB+=	CGI=""
CGI_PATH?=	${PREFIX}/www/vhosts/dspam
SED_SCRIPT+=	-e 's,%%CGI%%,,g'
SED_SCRIPT+=	-e 's,%%CGI_PATH%%,${CGI_PATH},g'
#SED_FILES=      ${LS} ${WRKSRC}/cgi/*.pl
#SED_FILES+=     ${LS} $PWRKSRC}/cgi/*.cgi
.else
PLIST_SUB+=	CGI="@comment "
SED_SCRIPT+=	-e '/%%CGI%%/D'
.endif

MAN1=	dspam.1 dspam_clean.1 dspam_corpus.1 dspam_dump.1 dspam_merge.1 \
	dspam_stats.1
MAN3=	libdspam.3
MLINKS=		libdspam.3 dspam_init.3
MLINKS+=	libdspam.3 dspam_create.3
MLINKS+=	libdspam.3 dspam_addattribute.3
MLINKS+=	libdspam.3 dspam_attach.3
MLINKS+=	libdspam.3 dspam_process.3
MLINKS+=	libdspam.3 dspam_getsource.3
MLINKS+=	libdspam.3 dspam_destroy.3
MLINKS+=	libdspam.3 dspam_detach.3

DOCS=	CHANGELOG LICENSE README README.FreeBSD README.courier README.exim \
	README.pop3filter README.postfix README.qmail README.sendmail \
	RELEASE.NOTES

pre-extract:
	@${ECHO_CMD} ""
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} "Warning: If upgrading please proceed as stated in"
	@${ECHO_CMD} "${FILESDIR}/UPDATING"
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} ""
.if defined(WITH_EXIM_LDA) && defined(WITH_POSTGRESQL73)
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} "You have both EXIM_LDA and POSTGRESQL73 defined. To have exim"
	@${ECHO_CMD} "built with the right pgsql please hit Ctrl-C now and do:"
	@${ECHO_CMD} "cd ${PORTSDIR}/mail/exim-postgresql && make POSTGRESQL_PORT=postgresql73 install"
	@${ECHO_CMD} "then return here and do:"
	@${ECHO_CMD} "make clean && make install"
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} ""
.endif

	@${ECHO_CMD} "Define vars below before make-ing if you need:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "SIGNATURE_LIFE (default 15)"
	@${ECHO_CMD} "DSPAM_OWNER (default: root)"
	@${ECHO_CMD} "DSPAM_GROUP (default: mail)"
	@${ECHO_CMD} "DSPAM_MODE"
	@${ECHO_CMD} "DSPAM_HOME (default: ${_VAR_DIR}/dspam)"
	@${ECHO_CMD} "DSPAM_HOME_OWNER"
	@${ECHO_CMD} "DSPAM_HOME_GROUP"
	@${ECHO_CMD} "DSPAM_HOME_MODE (default: 0660)"
	@${ECHO_CMD} "LOG_DIR (default: ${_VAR_DIR}/log/dspam)"
	@${ECHO_CMD} "QUARANTINE_AGENT (default: mail.local)"
.	if defined(WITH_CGI)
		@${ECHO_CMD} "Define CGI_PATH before make-ing if you need the CGI files"
		@${ECHO_CMD} "installed in other place that this installation's default"
		@${ECHO_CMD} "${PREFIX}/www/vhosts/dspam"
.	endif
	@${ECHO_CMD} ""
	@sleep 5

.for old_opt in MAILDROP PROCMAIL TRAD_BAYES ALT_BAYES WITH_SPAM_SUBJ \
	USER_LOGGING SYSTEM_LOGGING WEBMAIL OPT_IN SAT PARSE_TO_HEADERS \
	BROKEN_MTA BROKEN_ERR_CODES SIGNATURE_HEADERS SIGNATURE_ATACH \
	HOMEDIR_DOT SIGNATURE_LIFE
.	if defined(WITH_${old_opt}) || defined(WITHOUT_${old_opt})
	@${ECHO_CMD} ""
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} "Either:"
	@${ECHO_CMD} "an old option ${old_opt} or "
	@${ECHO_CMD} "OPTIONS config-file ${_OPTIONS_READ} has been detected !!!"
	@${ECHO_CMD} "Trying to prevent self-shooting this port's make ends here."
	@${ECHO_CMD} "You shold always read ${PORTSDIR}/UPDATING before installing/updating"
	@${ECHO_CMD} "any port. Please remove/adjust your pkgtools.conf, environment and"
	@${ECHO_CMD} "your make command-line and/or do 'make rmconfig' as appropiate."
	@${ECHO_CMD} "But before read ${FILESDIR}/UPDATING"
	@${ECHO_CMD} "as a lot of things have changed, notably the majority of"
	@${ECHO_CMD} "compile-time options can/must now be set in"
	@${ECHO_CMD} "${PREFIX}/etc/dspam.conf"
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} "******************************************************************"
	@${ECHO_CMD} ""
	@${FALSE}
.	endif
.endfor

post-patch:
	${REINPLACE_CMD} -e 's|%%PORTNAME%%|${PORTNAME}|; \
		s|%%PKGNAME%%|${PKGNAME}|; s|%%MAINTAINER%%|${MAINTAINER}|; \
		s|%%LIBTOOLFLAGS%%|${LIBTOOLFLAGS}|g; \
		s|-ldb-4.1|-ldb41|g;' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|where @a-14 > to_days(created_on);|where @a-${SIGNATURE_LIFE} > to_days(created_on);|' ${WRKSRC}/tools.mysql_drv/purge.sql
	@${REINPLACE_CMD} -e 's|WHERE CURRENT_DATE - created_on > 14;|WHERE CURRENT_DATE - created_on > ${SIGNATURE_LIFE};|' ${WRKSRC}/tools.pgsql_drv/purge.sql
	@${REINPLACE_CMD} -e 's|where SYSDATE-created_on > 14|where SYSDATE-created_on > ${SIGNATURE_LIFE};|' ${WRKSRC}/tools.ora_drv/purge.sql
	@${REINPLACE_CMD} -e "s|where date('now')-date(created_on) > 14;|where date('now')-date(created_on) > ${SIGNATURE_LIFE};|" ${WRKSRC}/tools.sqlite_drv/purge.sql

pre-configure:
	@${ECHO_CMD}
.if !( ${LDA_TOTAL_COUNT:S/o//}==${LDA_COUNT} || ${LDA_TOTAL_COUNT}==${LDA_COUNT} )
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${ECHO_CMD} "See ${LOCALBASE}/etc/dspam.conf for how to chage it at run time."
	@${FALSE}
.endif
.if ${DBDRV_TOTAL_COUNT:S/o//}!=${DBDRV_COUNT}
	@${ECHO_CMD}
	@${ECHO_CMD} "You can use one and only one database back-end at once."
	@${FALSE}
.endif
.if defined(WITH_NEURAL_NET) && !(defined(HAVE_MYSQL) || defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74))
	@${ECHO_CMD} "You need MySQL or POSTGRESQL to use neural networking."
	@${FALSE}
.endif
.if defined(WITH_VIRT_USERS) && !(defined(HAVE_MYSQL) || \
	defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74) || defined(WITH_ORACLE))
	@${ECHO_CMD} "You need MySQL, POSTGRESQL or ORACLE for virtual users."
	@${FALSE}
.endif
.if defined(WITH_PREF_EXT) && !( defined(HAVE_MYSQL) || \
	defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74) )
	@${ECHO_CMD} "You need MySQL or Postgres for preferences extension"
	@${FALSE}
.endif
.if defined(WITH_USER_HOMEDIR) && defined(WITH_CGI)
	@${ECHO_CMD} "USER_HOMEDIR and CGI are incopatible"
	@${FALSE}
.endif

post-install:
### to patch dspam.conf
	${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' ${WRKSRC}/dspam.conf
	@${CP} ${WRKSRC}/dspam.conf ${WRKSRC}/dspam.conf.sample
	cd ${WRKSRC}/ && \
		${INSTALL_DATA}	dspam.conf.sample ${PREFIX}/etc
#	@${MKDIR} ${LOG_DIR}
#	@${MKDIR} ${DSPAM_HOME}

.if defined(HAVE_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}/mysql
	cd ${WRKSRC}/tools.mysql_drv && \
		${INSTALL_DATA} README mysql_objects-space.sql \
			mysql_objects-speed.sql purge.sql \
			virtual_users.sql mysql_objects-4.1.sql \
			purge-4.1.sql neural.sql  ${EXAMPLESDIR}/mysql
	@${INSTALL_DATA} ${FILESDIR}/2x_to_3x_db.sql ${EXAMPLESDIR}/mysql
	@${INSTALL_DATA} ${FILESDIR}/310_to_320.my.sql ${EXAMPLESDIR}/mysql
.endif
.if defined(WITH_POSTGRESQL73) || defined(WITH_POSTGRESQL74)
	@${MKDIR} ${EXAMPLESDIR}/pgsql
	@cd ${WRKSRC}/tools.pgsql_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/pgsql
#	${INSTALL_DATA} ${FILESDIR}/pgsql.data ${EXAMPLESDIR}/pgsql
.endif
.if defined(WITH_SQLITE)
	@${MKDIR} ${EXAMPLESDIR}/sqlite
	cd ${WRKSRC}/tools.sqlite_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/sqlite
.endif
.if defined(WITH_ORACLE)
	@${MKDIR} ${EXAMPLESDIR}/oracle
	cd ${WRKSRC}/tools.ora_drv && \
		${INSTALL_DATA} README *.sql ${EXAMPLESDIR}/oracle
.endif

.if defined(WITH_CGI)
.	for I in admin.cgi admingraph.cgi configure.pl dspam.cgi graph.cgi
		@${SED} -i '' -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/cgi/${I}
.	endfor
	cd ${WRKSRC}/cgi && ${MV} configure.pl configure.pl.sample
	cd ${WRKSRC}/cgi && ${MKDIR} ${CGI_PATH} && \
		${INSTALL_SCRIPT} configure.pl.sample ${CGI_PATH}/ && \
		${INSTALL_SCRIPT} *.cgi ${CGI_PATH}
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} base.css dspam-logo-small.gif rgb.txt ${CGI_PATH}/
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} default.prefs ${CGI_PATH}/default.prefs.sample
	cd ${WRKSRC}/cgi && \
		${INSTALL_DATA} admins ${CGI_PATH}/admins.sample
#	cd ${WRKSRC}/cgi && \
#		${INSTALL_DATA} configure.pl.sample ${CGI_PATH}/configure.pl.sample
	@${MKDIR} ${CGI_PATH}/templates && cd ${WRKSRC}/cgi/templates && \
		${INSTALL_DATA} *.html ${CGI_PATH}/templates/
.endif

	@${SED} ${SED_SCRIPT} ${.CURDIR}/pkg-message > ${WRKSRC}/README.FreeBSD
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	cd ${FILESDIR} && ${INSTALL_DATA} UPDATING ${DOCSDIR}
.endif

	@${MKDIR} -m ${DSPAM_HOME_MODE} ${DSPAM_HOME}
	@${CHOWN} ${DSPAM_HOME_OWNER}:${DSPAM_HOME_GROUP} ${DSPAM_HOME}
.for _file in firstrun.txt firstspam.txt quarantinefull.txt
	if ! ${TEST} -e ${WRKSRC}/txt/${_file}.sample;\
	then\
		cd ${WRKSRC}/txt && \
		${MV} ${_file} ${_file}.sample;\
	fi
	cd ${WRKSRC}/txt && \
		${INSTALL_DATA} ${_file}.sample ${DSPAM_HOME}
.endfor

	@${MKDIR} -m ${DSPAM_HOME_MODE} ${LOG_DIR}

	@${CAT} ${WRKSRC}/README.FreeBSD
	@${ECHO_CMD} "If you haven't defined NOPORTDOCS you can review this"
	@${ECHO_CMD} "message in ${DOCSDIR}/README.FreeBSD"
	@${ECHO_CMD}

.include <bsd.port.post.mk>
