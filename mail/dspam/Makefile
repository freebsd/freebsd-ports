# Created by: Dominic Marks <dom@wirespeed.org.uk>
# $FreeBSD$

# Note to committers: If don't commit a maintainer patch and as a result PKGNAME
# or user variables (WITH*) changes please add an entry in ${FILESDIR}/UPDATING
# Thanks.

PORTNAME=	dspam
PORTVERSION=	3.9.0
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Bayesian spam filter

MIN_OPTIONS_VER=	${PORTNAME}-3.9.0

OPTIONS_DEFINE=	SYSLOG DEBUG VERBOSE_DEBUG BNR_DEBUG PREF_EXT DAEMON \
		CLAMAV CLAMAV_DEVEL CLAMAV_LOCAL EXTERNAL_LOOKUP \
		USER_HOMEDIR TRUSTED_USERS VIRT_USERS LONG_USERNAMES \
		LARGE_SCALE DOMAIN_SCALE NICESENDMAIL POSTFIX_MBC \
		QMAIL WEBUI LIGHTTPD

OPTIONS_MULTI=	DB
OPTIONS_MULTI_DB=	HASH MYSQL MYSQL_COMPRESS MYSQL_LOCAL \
			PGSQL PGSQL_LOCAL SQLITE2 SQLITE3

OPTIONS_RADIO=	LDA
OPTIONS_RADIO_LDA=	CYRUS21 CYRUS22 CYRUS23 CYRUS24 DOVECOT1 \
		DOVECOT2 EXIM MAILDROP PROCMAIL SAFECAT SENDMAIL

VERBOSE_DEBUG_DESC=	Debug in LOGDIR/dspam.debug
BNR_DEBUG_DESC=	Debug for BNR
PREF_EXT_DESC=	Preferences in database not in files
DAEMON_DESC=	Daemonize dspam; speaks LMTP or DLMTP
CLAMAV_DESC=	ClamAV support
CLAMAV_DEVEL_DESC=	ClamAV devel version support
CLAMAV_LOCAL_DESC=	RUN_DEPEND on selected ClamAV
MYSQL_DESC=	MySQL 5.X.x as back-end
MYSQL_COMPRESS_DESC=	Compress dspam <--> MySQL
MYSQL_LOCAL_DESC=	RUN_DEPEND on MySQL server
PGSQL_DESC=	PostgreSQL as back-end
PGSQL_LOCAL_DESC=	RUN_DEPEND on PostgreSQL server
SQLITE2_DESC=	SQLite v2.x as back-end
SQLITE3_DESC=	SQLite v3.x as back-end
HASH_DESC=	Hash driver
EXTERNAL_LOOKUP_DESC=	RCPT verification via extlookup
USER_HOMEDIR_DESC=	Store user data in ~/.dspam
TRUSTED_USERS_DESC=	Disable trusted user security
VIRT_USERS_DESC=	Virtual users (needs SQL back-end)
LONG_USERNAMES_DESC=	Usernames longer that OS supports
LARGE_SCALE_DESC=	File structure for large scale
DOMAIN_SCALE_DESC=	File structure for multiple domains
CYRUS21_DESC=	Cyrus's 2.1 deliver as LDA
CYRUS22_DESC=	Cyrus's 2.2 deliver as LDA
CYRUS23_DESC=	Cyrus's 2.3 deliver as LDA
CYRUS24_DESC=	Cyrus's 2.4 deliver as LDA
DOVECOT1_DESC=	Dovecot 1.2 deliver as LDA
DOVECOT2_DESC=	Dovecot 2.2 dovecot-lda as LDA
EXIM_DESC=	Exim as local delivery agent
MAILDROP_DESC=	Maildrop as local delivery agent
PROCMAIL_DESC=	Procmail as local delivery agent
SAFECAT_DESC=	Safecat as local delivery agent
SENDMAIL_DESC=	Sendmail as local delivery agent
NICESENDMAIL_DESC=	Play nice with sendmail server
POSTFIX_MBC_DESC=	Dspam as mailbox_command in Postfix
QMAIL_DESC=	Play nice with Qmail mail server
WEBUI_DESC=	Install WebUI, pulls in Apache or see below

OPTIONS_DEFAULT=	SYSLOG DEBUG DAEMON CLAMAV CLAMAV_LOCAL \
			HASH MYSQL MYSQL_COMPRESS PGSQL SQLITE3

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	${PTHREAD_CFLAGS}

.ifdef(GDBS)
CFLAGS+=	-g -DDEBUG
STRIP=
.endif

PKGMESSAGE=	${WRKSRC}/README.FreeBSD

CONFLICTS=	dspam-devel-[0-9]*

SIGNATURE_LIFE?=	15

_VAR_DIR=	/var
LOG_DIR?=	${_VAR_DIR}/log/dspam
LOGFILE?=	${LOG_DIR}/dspam.log

DSPAM_MODE?=	4510
DSPAM_OWNER?=	root
DSPAM_GROUP?=	mail

DSPAM_ETC?=	${LOCALBASE}/etc
DSPAM_HOME?=	${_VAR_DIR}/db/dspam
DSPAM_HOME_OWNER?=	${DSPAM_OWNER}
DSPAM_HOME_GROUP?=	${DSPAM_GROUP}
DSPAM_HOME_MODE?=	0770

.for s in OWNER GROUP HOME_OWNER HOME_GROUP
PLIST_SUB+=	DSPAM_$s=${DSPAM_$s}
.endfor

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--sysconfdir=${DSPAM_ETC}
CONFIGURE_ARGS+=	--with-logdir=${LOG_DIR}
PLIST_SUB+=	LOG_DIR=${LOG_DIR}

CONFIGURE_ARGS+=	--with-dspam-home=${DSPAM_HOME}
CONFIGURE_ARGS+=	--with-dspam-home-owner=${DSPAM_HOME_OWNER}
CONFIGURE_ARGS+=	--with-dspam-home-group=${DSPAM_HOME_GROUP}
CONFIGURE_ARGS+=	--with-dspam-home-mode=${DSPAM_HOME_MODE}
PLIST_SUB+=	DSPAM_HOME=${DSPAM_HOME}

CONFIGURE_ARGS+=	--with-dspam-owner=${DSPAM_OWNER}
CONFIGURE_ARGS+=	--with-dspam-group=${DSPAM_GROUP}
# we set DSPAM_MODE at the end as some LDAs want specific mode

_SED_SCRIPT=	-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g' \
		-e 's,%%DSPAM_HOME%%,${DSPAM_HOME},g' \
		-e 's,%%PORTNAME%%,${PORTNAME},g' \
		-e 's,%%_VAR_DIR%%,${_VAR_DIR},g' \
		-e '/^%%FreeBSD/D' \
		-e '/^%%Tecnik%%/D'

.if ${PORT_OPTIONS:MSYSLOG}
CONFIGURE_ARGS+=	--enable-syslog
.else
CONFIGURE_ARGS+=	--disable-syslog
CONFIGURE_ARGS+=	--with-logfile=${LOGFILE}
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MVERBOSE_DEBUG}
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif

.if ${PORT_OPTIONS:MBNR_DEBUG}
CONFIGURE_ARGS+=	--enable-bnr-debug
.endif

.if ${PORT_OPTIONS:MPREF_EXT}
CONFIGURE_ARGS+=	--enable-preferences-extension
.endif

.if ${PORT_OPTIONS:MDAEMON}
CONFIGURE_ARGS+=	--enable-daemon
USE_RC_SUBR=	${PORTNAME}
_SED_SCRIPT+=	-e 's,%%DAEMON%%,,g'
SUB_LIST+=	DSPAM_HOME=${DSPAM_HOME}
.else
_SED_SCRIPT+=	-e '/%%DAEMON%%/D'
.endif

.if ${PORT_OPTIONS:MCLAMAV}
CONFIGURE_ARGS+=	--enable-clamav
.	if ${PORT_OPTIONS:MCLAMAV_LOCAL}
RUN_DEPENDS+=	clamav>=0:${PORTSDIR}/security/clamav
SUB_LIST+=	CLAMD=clamd
.	else
SUB_LIST+=	CLAMD=
.	endif
.endif
.if ${PORT_OPTIONS:MCLAMAV_DEVEL}
CONFIGURE_ARGS+=	--enable-clamav
.	if ${PORT_OPTIONS:MCLAMAV_LOCAL}
RUN_DEPENDS+=	clamav-devel>=0:${PORTSDIR}/security/clamav-devel
SUB_LIST+=	CLAMD=clamd
.	else
SUB_LIST+=	CLAMD=
.	endif
.endif

# we need to know if we are building statically or dynamicaly for the plist
_DBDRV_COUNT=	# blank, but defined so we can check against it
_DBDRV=		pgsql_drv,sqlite3_drv,sqlite_drv,hash_drv,mysql_drv,

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql-includes=${LOCALBASE}/include \
			--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	PGSQL=""
#PKGNAMESUFFIX=	-pgsql
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.	if ${PORT_OPTIONS:MPGSQL_LOCAL}
USE_PGSQL=	server
SUB_LIST+=	PGSQL=postgresql
.	else
SUB_LIST+=	PGSQL=
.	endif
.else
PLIST_SUB+=	PGSQL="@comment "
_DBDRV:=	${_DBDRV:S/pgsql_drv,//}
.endif

.if ${PORT_OPTIONS:MSQLITE3}
USE_SQLITE=	3
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.else
_DBDRV:=	${_DBDRV:S/sqlite3_drv,//}
.endif

.if ${PORT_OPTIONS:MSQLITE2}
USE_SQLITE=	2
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.else
_DBDRV:=	${_DBDRV:S/sqlite_drv,//}
.endif

.if defined(USE_SQLITE)
CONFIGURE_ARGS+=	--with-sqlite-includes=${LOCALBASE}/include \
			--with-sqlite-libraries=${LOCALBASE}/lib
PLIST_SUB+=	SQLITE=""
.else
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MHASH}
PLIST_SUB+=	HASH=""
#PKGNAMESUFFIX=	-css
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.else
_DBDRV:=	${_DBDRV:S/hash_drv,//}
PLIST_SUB+=	HASH="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-includes=${LOCALBASE}/include/mysql \
			--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.	if ${PORT_OPTIONS:MMYSQL_COMPRESS}
CONFIGURE_ARGS+=	--enable-client-compression
.	endif
.	if ${PORT_OPTIONS:MMYSQL_LOCAL}
USE_MYSQL=	server
SUB_LIST+=	MYSQL=mysql
.	else
SUB_LIST+=	MYSQL=
.	endif
.else
_DBDRV:=	${_DBDRV:S/mysql_drv,//}
PLIST_SUB+=	MYSQL="@comment "
.endif

# now we have all the db backends the user wants and we remove last ','
CONFIGURE_ARGS+=	--with-storage-driver=${_DBDRV:S/,$//}

.if ${_DBDRV_COUNT} != "o"
PLIST_SUB+=	DYNAMIC=""
.else
PLIST_SUB+=	DYNAMIC="@comment "
.endif

.if ${PORT_OPTIONS:MEXTERNAL_LOOKUP}
CONFIGURE_ARGS+=	--enable-external-lookup
USE_OPENLDAP=	YES
#CPPFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-lldap -llber
#CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

.if ${PORT_OPTIONS:MUSER_HOMEDIR}
CONFIGURE_ARGS+=	--enable-homedir
.endif

.if ${PORT_OPTIONS:MTRUSTED_USERS}
CONFIGURE_ARGS+=	--disable-trusted-user-security
.endif

.if ${PORT_OPTIONS:MVIRT_USERS}
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

.if ${PORT_OPTIONS:MLONG_USERNAMES}
CONFIGURE_ARGS+=	--enable-long-usernames
.endif
.if ${PORT_OPTIONS:MLARGE_SCALE}
CONFIGURE_ARGS+=	--enable-large-scale
.endif
.if ${PORT_OPTIONS:MDOMAIN_SCALE}
CONFIGURE_ARGS+=	--enable-domain-scale
.endif

.if ${PORT_OPTIONS:MCYRUS21}
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd2
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
.endif

.if ${PORT_OPTIONS:MCYRUS22}
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd22
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
.endif

.if ${PORT_OPTIONS:MCYRUS23}
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd23
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
.endif

.if ${PORT_OPTIONS:MCYRUS24}
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd24
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
.endif

.if ${PORT_OPTIONS:MDOVECOT1}
RUN_DEPENDS+=	${LOCALBASE}/libexec/dovecot/deliver:${PORTSDIR}/mail/dovecot
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/libexec/dovecot/deliver'
.endif

.if ${PORT_OPTIONS:MDOVECOT2}
RUN_DEPENDS+=	${LOCALBASE}/libexec/dovecot/dovecot-lda:${PORTSDIR}/mail/dovecot2
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/libexec/dovecot/dovecot-lda'
.endif

.if ${PORT_OPTIONS:MEXIM}
.	if ${PORT_OPTIONS:MMYSQL}
_EXIM_EXT=	-mysql
.	elif ${PORT_OPTIONS:MPGSQL}
_EXIM_EXT=	-postgresql
.	endif
RUN_DEPENDS+=	exim:${PORTSDIR}/mail/exim${_EXIM_EXT}
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/exim'
.endif

.if ${PORT_OPTIONS:MMAILDROP}
RUN_DEPENDS+=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/maildrop'
.endif

.if ${PORT_OPTIONS:MPROCMAIL}
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/procmail'
.endif

.if ${PORT_OPTIONS:MSAFECAT}
RUN_DEPENDS+=	safecat:${PORTSDIR}/sysutils/safecat
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/safecat tmp new'
.endif

.if ${PORT_OPTIONS:MSENDMAIL} && exists(/usr/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent=/usr/sbin/sendmail
.else
.if ${PORT_OPTIONS:MSENDMAIL} && exists(${LOCALBASE}/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/sendmail'
.	endif
.endif

.if ${PORT_OPTIONS:MNICESENDMAIL}
DSPAM_MODE=	4511
.endif

.if ${PORT_OPTIONS:MPOSTFIX_MBC}
DSPAM_MODE=	4511
.endif

.if ${PORT_OPTIONS:MQMAIL}
DSPAM_MODE=	4511
.endif

.ifdef(DSPAM_MODE)
CONFIGURE_ARGS+=	--with-dspam-mode=${DSPAM_MODE}
.endif

.if ${PORT_OPTIONS:MWEBUI}
.	if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
.	else
USE_APACHE_RUN=	22+
.	endif
LIB_DEPENDS+=	gd:${PORTSDIR}/graphics/gd
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	p5-GD-Graph>=0:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS+=	p5-GD-Graph3d>=0:${PORTSDIR}/graphics/p5-GD-Graph3d
RUN_DEPENDS+=	p5-GD-TextUtil>=0:${PORTSDIR}/graphics/p5-GD-TextUtil
CONFIGURE_ARGS+=--enable-logging
CONFIGURE_ARGS+=--enable-user-logging
PLIST_SUB+=	WebUI=""
_SED_SCRIPT+=	-e 's/%%WebUI%%//g'
_SED_SCRIPT+=	-e 's,%%WWWDIR%%,${WWWDIR},g'
PLIST_SUB+=	WWWDIR=${WWWDIR_REL}
.else
PLIST_SUB+=	WebUI="@comment "
_SED_SCRIPT+=	-e '/%%WebUI%%/D'
.endif

_DOCS=	CHANGELOG LICENSE README README.FreeBSD RELEASE.NOTES UPGRADING
_DOCSL=	courier.txt exim.txt markov.txt mysql_drv.txt pgsql_drv.txt \
	pop3filter.txt postfix.txt qmail.txt relay.txt sendmail.txt \
	sqlite_drv.txt

pre-everything::
.ifndef(MAINT)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Last ${FILESDIR}/UPDATING entry:"
	@${ECHO_CMD} "###########################################################################"
	@${SED} -n < ${FILESDIR}/UPDATING "/^# ${PKGNAME}/,/^#####/p"
	@${ECHO_CMD} ""
	@sleep 5
.endif

pre-extract:
.ifndef(MAINT)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define vars below before make-ing if you need:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "SIGNATURE_LIFE=${SIGNATURE_LIFE} (default 15)"
	@${ECHO_CMD} "DSPAM_OWNER=${DSPAM_OWNER} (default: root)"
	@${ECHO_CMD} "DSPAM_GROUP=${DSPAM_GROUP} (default: mail)"
	@${ECHO_CMD} "DSPAM_MODE=${DSPAM_MODE}"
	@${ECHO_CMD} "DSPAM_ETC=${DSPAM_ETC} (default: ${PREFIX}/etc"
	@${ECHO_CMD} "DSPAM_HOME=${DSPAM_HOME} (default: ${_VAR_DIR}/db/dspam)"
	@${ECHO_CMD} "DSPAM_HOME_OWNER=${DSPAM_HOME_OWNER}"
	@${ECHO_CMD} "DSPAM_HOME_GROUP=${DSPAM_HOME_GROUP}"
	@${ECHO_CMD} "DSPAM_HOME_MODE=${DSPAM_HOME_MODE} (default: 0770)"
	@${ECHO_CMD} "LOG_DIR=${LOG_DIR} (default: ${_VAR_DIR}/log/dspam)"
.	ifdef(WITHOUT_SYSLOG)
	@${ECHO_CMD} "LOGFILE=${LOGFILE} (default: ${_VAR_DIR}/log/dspam/dspam.log)"
.	endif
.if ${PORT_OPTIONS:MWEBUI}
		@${ECHO_CMD} "Define WWWDIR before making if you need the WebUI files"
		@${ECHO_CMD} "installed in other place that this installation's default"
		@${ECHO_CMD} "${WWWDIR}"
.	endif
	@${ECHO_CMD} ""
	@sleep 5
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|where @a-14 > to_days(created_on);|where @a-${SIGNATURE_LIFE} > to_days(created_on);|' \
		${WRKSRC}/src/tools.mysql_drv/purge.sql
	@${REINPLACE_CMD} -e 's|where @a-14 > to_days(created_on);|where @a-${SIGNATURE_LIFE} > to_days(created_on);|' \
		${WRKSRC}/src/tools.mysql_drv/purge-4.1.sql
	@${REINPLACE_CMD} -e 's|WHERE CURRENT_DATE - created_on > 14;|WHERE CURRENT_DATE - created_on > ${SIGNATURE_LIFE};|' \
		${WRKSRC}/src/tools.pgsql_drv/purge.sql
	@${REINPLACE_CMD} -e "s|where date('now')-date(created_on) > 14;|where date('now')-date(created_on) > ${SIGNATURE_LIFE};|" \
		${WRKSRC}/src/tools.sqlite_drv/purge-2.sql
	@${REINPLACE_CMD} -e "s|where julianday('now')-julianday(created_on) > 14;|where julianday('now')-julianday(created_on) > ${SIGNATURE_LIFE};|" \
		 ${WRKSRC}/src/tools.sqlite_drv/purge-3.sql
	@${REINPLACE_CMD} -e "s|%%PERL%%|${PERL}|; s|%%DSPAM_PATH%%|${PREFIX}/bin|" ${WRKSRC}/scripts/train.pl

pre-configure:
.if ${PORT_OPTIONS:MVIRT_USERS} && !( defined(USE_MYSQL) || \
	${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MHASH} )
	@${ECHO_CMD} "You need MySQL, POSTGRESQL or HASH for virtual users."
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MPREF_EXT} && !( defined(USE_MYSQL) || \
	${PORT_OPTIONS:MPGSQL} )
	@${ECHO_CMD} "You need MySQL or Postgres for preferences extension"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MDAEMON} && !( defined(USE_MYSQL) || \
	${PORT_OPTIONS:MPGSQL} || ${PORT_OPTIONS:MHASH} )
	@${ECHO_CMD} "You need MySQL, PostgreSQL or Hash for Daemon mode, because multithreading support is needed"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MEXTERNAL_LOOKUP} && !( defined(USE_MYSQL) || \
	${PORT_OPTIONS:MPGSQL} || defined(USE_SQLITE) )
	@${ECHO_CMD} "You need MySQL, Postgres or SQLITE for EXTERNAL_LOOKUP."
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MUSER_HOMEDIR} && ${PORT_OPTIONS:MWEBUI}
	@${ECHO_CMD} "USER_HOMEDIR and WebUI are incopatible"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MDOMAIN_SCALE} && ${PORT_OPTIONS:MLARGE_SCALE}
	@${ECHO_CMD} "DOMAIN_SCALE and LARGE_SCALE are incopatible"
	@${FALSE}
.endif
.if ${PORT_OPTIONS:MLIGHTTPD} && ! ${PORT_OPTIONS:MWEBUI}
	@${ECHO_CMD} "There's no reason to depend on LightHTTPD if you're not using WebUI"
	@${FALSE}
.endif

post-install:
	${CP} ${WRKSRC}/src/dspam.conf ${WRKSRC}/src/dspam.conf.sample
	cd ${WRKSRC}/src/ && \
		${INSTALL_DATA} dspam.conf.sample ${STAGEDIR}${PREFIX}/etc

########
# stupid hack until I figure out where/how to patch
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/dspam.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/dspam.pc
	${RM} -R ${STAGEDIR}${PREFIX}/lib/pkgconfig || true

.if ${PORT_OPTIONS:MEXAMPLES}
.ifdef(USE_MYSQL)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/mysql
	cd  ${WRKSRC}/src/tools.mysql_drv && \
		${INSTALL_DATA} mysql_objects-4.1.sql \
			mysql_objects-space.sql \
			mysql_objects-speed.sql \
			purge-4.1.sql purge.sql \
			virtual_user_aliases.sql \
			virtual_users.sql ${STAGEDIR}${EXAMPLESDIR}/mysql
.endif
.if ${PORT_OPTIONS:MPGSQL}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pgsql
	@cd  ${WRKSRC}/src/tools.pgsql_drv && \
		${INSTALL_DATA} *.sql ${STAGEDIR}${EXAMPLESDIR}/pgsql
.endif
.ifdef(USE_SQLITE)
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/sqlite
	cd ${WRKSRC}/src/tools.sqlite_drv && \
		${INSTALL_DATA} *.sql ${STAGEDIR}${EXAMPLESDIR}/sqlite
.endif
.endif	# NOPORTEXAMPLES

.if ${PORT_OPTIONS:MWEBUI}
.	for I in admin.cgi admingraph.cgi configure.pl dspam.cgi graph.cgi templates/strings.pl
		${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/webui/cgi-bin/${I}
.	endfor
	${MV} ${WRKSRC}/webui/cgi-bin/configure.pl ${WRKSRC}/webui/cgi-bin/configure.pl.sample
	cd ${WRKSRC}/webui/cgi-bin && ${MKDIR} ${STAGEDIR}${WWWDIR} && \
		${INSTALL_SCRIPT} configure.pl.sample ${STAGEDIR}${WWWDIR}/ && \
		${INSTALL_SCRIPT} *.cgi ${STAGEDIR}${WWWDIR} && \
		${INSTALL_DATA} rgb.txt ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/webui/htdocs && \
		${INSTALL_DATA} base.css dspam-logo-small.gif ${STAGEDIR}${WWWDIR}/
	cd ${WRKSRC}/webui/cgi-bin && \
		${INSTALL_DATA} default.prefs ${STAGEDIR}${WWWDIR}/default.prefs.sample
	cd ${WRKSRC}/webui/cgi-bin && \
		${INSTALL_DATA} admins ${STAGEDIR}${WWWDIR}/admins.sample
	${MKDIR} ${STAGEDIR}${WWWDIR}/templates && cd ${WRKSRC}/webui/cgi-bin/templates && \
		${INSTALL_DATA} *.html ${STAGEDIR}${WWWDIR}/templates/ && \
		${INSTALL_SCRIPT} strings.pl ${STAGEDIR}${WWWDIR}/templates/ &&
		for _dir in de es-es fr he pt-br ro; do \
			${INSTALL_DATA} -d ${STAGEDIR}${WWWDIR}/templates/$${_dir} && \
			cd ${WRKSRC}/webui/cgi-bin/templates/$${_dir} && \
				${INSTALL_DATA} *.html ${STAGEDIR}${WWWDIR}/templates/$${_dir}; \
		done && \
		for _dir in de es-es pt-br; do \
			cd ${WRKSRC}/webui/cgi-bin/templates/$${_dir} && \
				${INSTALL_SCRIPT} strings.pl ${STAGEDIR}${WWWDIR}/templates/$${_dir}/; \
		done
.endif

	@${SED} ${_SED_SCRIPT} ${.CURDIR}/pkg-message > ${WRKSRC}/README.FreeBSD

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${_DOCSL} ${STAGEDIR}${DOCSDIR}
	@cd ${FILESDIR} && ${INSTALL_DATA} UPDATING ${STAGEDIR}${DOCSDIR}/UPDATING
.endif

	@${MKDIR} -m ${DSPAM_HOME_MODE} ${STAGEDIR}${DSPAM_HOME}
.for _file in firstrun.txt firstspam.txt quarantinefull.txt
	@if ! ${TEST} -e ${WRKSRC}/txt/${_file}.sample;\
	then\
		cd ${WRKSRC}/txt && \
		${MV} ${_file} ${_file}.sample;\
	fi
	cd ${WRKSRC}/txt && \
		${INSTALL_DATA} ${_file}.sample ${STAGEDIR}${DSPAM_HOME}
.endfor

	@${MKDIR} -m ${DSPAM_HOME_MODE} ${STAGEDIR}${LOG_DIR}

.include <bsd.port.post.mk>
