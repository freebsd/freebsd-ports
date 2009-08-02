# New ports collection makefile for:	dspam-devel
# Date created:		24 Jun 2004
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $Tecnik: ports/mail/dspam-devel/Makefile,v 1.55 2006/06/05 08:41:24 itetcu Exp $
# $FreeBSD$
#

# Note to commiters: If don't commit a maintainer patch and as a result PKGNAME
# or user variables (WITH*) changes please add an entry in ${FILESDIR}/UPDATING and
# modify _UPD_LINE_NO=(no_of_added_lines-1) in this Makefile.
# Else the port will be broken. Thanks.

PORTNAME=	dspam-devel
PORTVERSION=	${PORTVER_MAJ}${SNAP_DATE}
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	# set later

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Bayesian spam filter - development version

PORTVER_MAJ=	3.8.0
#SNAP_DATE=	.20061010.1118

MIN_OPTIONS_VER=	${PORTNAME}-3.6.8.20061010.1118_1

.ifdef(SNAP_DATE)
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
MASTER_SITE_SUBDIR=	itetcu
.else
MASTER_SITES=	http://dspam.irontec.com/sources/ \
	http://dspam.nuclearelephant.com/sources/ \
	http://dspam.systemadministrator.org/sources/ \
	http://dspam.sourceforge.net/sources/ \
	http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
DISTFILES=	dspam-${PORTVER_MAJ}.tar.gz
WRKSRC=		${WRKDIR}/dspam-${PORTVER_MAJ}
.endif

## debug / log / admin options
OPTIONS=	SYSLOG "Logs via syslog" on
OPTIONS+=	DEBUG "Enable debugging logging" on
OPTIONS+=	VERBOSE_DEBUG "Enable debug in LOGDIR/dspam.debug" off
OPTIONS+=	BNR_DEBUG "Enable debug for BNR" off
OPTIONS+=	PREF_EXT "Preferences in database not in files" off
OPTIONS+=	DAEMON "Daemonize dspam; speaks LMTP or DLMTP" on

#
OPTIONS+=	CLAMAV "Enable clamav support" on
OPTIONS+=	CLAMAV_DEVEL "Enable clamav support" off
OPTIONS+=	CLAMAV_LOCAL "RUN_DEPEND on selected clamav" on
#
OPTIONS+=	MYSQL40 "Use MySQL 4.0.x as back-end" off
OPTIONS+=	MYSQL41 "Use MySQL 4.1.x as back-end" off
OPTIONS+=	MYSQL50 "Use MySQL 5.0.x as back-end" on
OPTIONS+=	MYSQL51 "Use MySQL 5.1.x as back-end" off
OPTIONS+=	MYSQL_COMPRESS "Compress dspam <--> MySQL" off
OPTIONS+=	MYSQL_LOCAL "RUN_DEPEND on selected MySQL server ver." off
OPTIONS+=	POSTGRESQL "Use PostgreSQL as back-end" on
OPTIONS+=	POSTGRESQL_LOCAL "RUN_DEPEND on PostgreSQL server" off
OPTIONS+=	SQLITE2 "Use SQLite v2.x as back-end" off
OPTIONS+=	SQLITE3 "Use SQLite v3.x as back-end" on
OPTIONS+=	HASH "Use hash driver" on
#
OPTIONS+=	LDAP "Enable recipient verification via LDAP" off

# layout
OPTIONS+=	USER_HOMEDIR "Store user data in ~/.dspam" off
OPTIONS+=	TRUSTED_USERS "Disable trusted user security" off
OPTIONS+=	VIRT_USERS "Enable virtual users (needs SQL back-end)" off
OPTIONS+=	LONG_USERNAMES "Usernames longer that OS supports" off
OPTIONS+=	LARGE_SCALE "File structure for large scale" off
OPTIONS+=	DOMAIN_SCALE "File structure for multiple domains" off

## MTA and LDA
OPTIONS+=	CYRUS21_LDA "Use Cyrus's 2.1 deliver as LDA" off
OPTIONS+=	CYRUS22_LDA "Use Cyrus's 2.2 deliver as LDA" off
OPTIONS+=       CYRUS23_LDA "Use Cyrus's 2.3 deliver as LDA" off
OPTIONS+=	EXIM_LDA "Use Exim as local delivery agent" off
OPTIONS+=	MAILDROP_LDA "Use Maildrop as local delivery agent" off
OPTIONS+=	PROCMAIL_LDA "Use Procmail as local delivery agent" off
OPTIONS+=	SAFECAT_LDA "Use Safecat as local delivery agent" off
OPTIONS+=	SENDMAIL_LDA "Use Sendmail as local delivery agent" off

OPTIONS+=	SENDMAIL "Play nice with sendmail server" off
OPTIONS+=	POSTFIX_MBC "Dspam as mailbox_command in Postfix" off
OPTIONS+=	QMAIL "Play nice with Qmail mail server" off

OPTIONS+=	CGI "Install CGI (pulls in Apache or see below)" off
OPTIONS+=	LIGHTTPD "RUN_DEPEND on LightHTTPD, not Apache" off

USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22
.ifdef(SNAP_DATE)
USE_AUTOTOOLS+=	autoconf:262:env automake:19
.endif
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
#CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.ifdef(GDBS)
CFLAGS+=	-g -DDEBUG
STRIP=
.endif

PKGMESSAGE=	 ${WRKSRC}/src/README.FreeBSD

CONFLICTS=	dspam-[0-9]*

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

.ifndef(WITHOUT_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.else
CONFIGURE_ARGS+=	--disable-syslog
CONFIGURE_ARGS+=	--with-logfile=${LOGFILE}
.endif

.ifndef(WITHOUT_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.ifdef(WITH_VERBOSE_DEBUG)
CONFIGURE_ARGS+=	--enable-verbose-debug
.endif

.ifdef(WITH_BNR_DEBUG)
CONFIGURE_ARGS+=	--enable-bnr-debug
.endif

.ifdef(WITH_PREF_EXT)
CONFIGURE_ARGS+=	--enable-preferences-extension
.endif

.ifndef(WITHOUT_DAEMON)
CONFIGURE_ARGS+=	--enable-daemon
USE_RC_SUBR=	${PORTNAME}
_SED_SCRIPT+=	-e 's,%%DAEMON%%,,g'
SUB_LIST+=	DSPAM_HOME=${DSPAM_HOME}
.else
_SED_SCRIPT+=	-e '/%%DAEMON%%/D'
.endif

.ifndef(WITHOUT_CLAMAV)
CONFIGURE_ARGS+=	--enable-clamav
.	ifndef(WITHOUT_CLAMAV_LOCAL)
RUN_DEPENDS+=	clamav>=0:${PORTSDIR}/security/clamav
SUB_LIST+=	CLAMD=clamd
.	else
SUB_LIST+=	CLAMD=
.	endif
.endif
.ifdef(WITH_CLAMAV_DEVEL)
CONFIGURE_ARGS+=	--enable-clamav
.	ifndef(WITHOUT_CLAMAV_LOCAL)
RUN_DEPENDS+=	clamav-devel>=0:${PORTSDIR}/security/clamav-devel
SUB_LIST+=	CLAMD=clamd
.	else
SUB_LIST+=	CLAMD=
.	endif
.endif

# we need to know if we are building statically or dynamicaly for the plist
_DBDRV_COUNT=	# blank, but defined so we can check against it
_DBDRV=		pgsql_drv,sqlite3_drv,sqlite_drv,hash_drv,mysql_drv,

.ifndef(WITHOUT_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--with-pgsql-includes=${LOCALBASE}/include \
		--with-pgsql-libraries=${LOCALBASE}/lib
PLIST_SUB+=	PGSQL=""
#PKGNAMESUFFIX=	-pgsql
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.	if defined(WITH_POSTGRESQL_LOCAL)
RUN_DEPENDS+=	postgresql-server>=0:${PORTSDIR}/databases/postgresql${PGSQL_VER}-server
SUB_LIST+=	PGSQL=postgresql
.	else
SUB_LIST+=	PGSQL=
.	endif
.else
PLIST_SUB+=	PGSQL="@comment "
_DBDRV:=	${_DBDRV:S/pgsql_drv,//}
.endif

.ifndef(WITHOUT_SQLITE3)
USE_SQLITE=	3
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.else
_DBDRV:=	${_DBDRV:S/sqlite3_drv,//}
.endif

.if defined(WITH_SQLITE2)
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

.ifndef(WITHOUT_HASH)
PLIST_SUB+=	HASH=""
#PKGNAMESUFFIX=	-css
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.else
_DBDRV:=	${_DBDRV:S/hash_drv,//}
PLIST_SUB+=	HASH="@comment "
.endif

.ifdef(WITH_MYSQL40)
WANT_MYSQL_VER=	40
#PKGNAMESUFFIX=	-mysql40
.elifdef(WITH_MYSQL41)
WANT_MYSQL_VER=	41
#PKGNAMESUFFIX=	-mysql41
.elifndef(WITHOUT_MYSQL50)
WANT_MYSQL_VER=	50
#PKGNAMESUFFIX=	-mysql50
.elifdef(WITH_MYSQL51)
WANT_MYSQL_VER=	51
#PKGNAMESUFFIX=	-mysql51
.endif

.if defined(WITH_MYSQL40) || defined(WITH_MYSQL41) || \
	!defined(WITHOUT_MYSQL50) || defined(WITH_MYSQL51)
USE_MYSQL=	yes
CONFIGURE_ARGS+=	--with-mysql-includes=${LOCALBASE}/include/mysql \
		--with-mysql-libraries=${LOCALBASE}/lib/mysql
PLIST_SUB+=	MYSQL=""
_DBDRV_COUNT:=	${_DBDRV_COUNT}o
.	if defined(WITH_MYSQL_COMPRESS)
CONFIGURE_ARGS+=	--enable-client-compression
.	endif
.	if defined(WITH_MYSQL_LOCAL)
RUN_DEPENDS+=	mysql-server>=0:${PORTSDIR}/databases/mysql${WANT_MYSQL_VER}-server
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

.ifdef(WITH_LDAP)
CONFIGURE_ARGS+=	--enable-ldap
USE_OPENLDAP=	YES
#CPPFLAGS+=	-I${LOCALBASE}/include
#LDFLAGS+=	-lldap -llber
#CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.endif

.ifdef(WITH_USER_HOMEDIR)
CONFIGURE_ARGS+=	--enable-homedir
.endif

.ifdef(WITH_TRUSTED_USERS)
CONFIGURE_ARGS+=	--disable-trusted-user-security
.endif

.ifdef(WITH_VIRT_USERS)
CONFIGURE_ARGS+=	--enable-virtual-users
.endif

.ifdef(WITH_LONG_USERNAMES)
CONFIGURE_ARGS+=	--enable-long-usernames
.endif
.ifdef(WITH_LARGE_SCALE)
CONFIGURE_ARGS+=	--enable-large-scale
.endif
.ifdef(WITH_DOMAIN_SCALE)
CONFIGURE_ARGS+=	--enable-domain-scale
.endif

# add one 'o' here for each new LDA
LDA_TOTAL_COUNT=	ooooooooo	# 9
LDA_COUNT=	${LDA_TOTAL_COUNT}

.if defined(WITH_CYRUS21_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd2
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_CYRUS22_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd22
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.if defined(WITH_CYRUS23_LDA)
RUN_DEPENDS+=	${LOCALBASE}/cyrus/bin/deliver:${PORTSDIR}/mail/cyrus-imapd23
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/cyrus/bin/deliver'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.ifdef(WITH_EXIM_LDA)
.	ifdef(WITH_MYSQL40) || (WITH_MYSQL41)
_EXIM_EXT=	-mysql
.	elifdef(WITH_POSTGRESQL)
_EXIM_EXT=	-postgresql
.	endif
RUN_DEPENDS+=	exim:${PORTSDIR}/mail/exim${_EXIM_EXT}
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/exim'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.ifdef(WITH_MAILDROP_LDA)
RUN_DEPENDS+=	maildrop:${PORTSDIR}/mail/maildrop
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/maildrop'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.ifdef(WITH_PROCMAIL_LDA)
RUN_DEPENDS+=	procmail:${PORTSDIR}/mail/procmail
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/bin/procmail'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.ifdef(WITH_SAFECAT_LDA)
RUN_DEPENDS+=	safecat:${PORTSDIR}/sysutils/safecat
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/safecat tmp new'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.endif

.ifdef(WITH_SENDMAIL_LDA) && exists(/usr/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent=/usr/sbin/sendmail
LDA_COUNT:=	${LDA_COUNT:S/o//}
.else
.	ifdef(WITH_SENDMAIL_LDA) && exists(${LOCALBASE}/sbin/sendmail)
CONFIGURE_ARGS+=	--with-delivery-agent='${LOCALBASE}/sbin/sendmail'
LDA_COUNT:=	${LDA_COUNT:S/o//}
.	endif
.endif

.ifdef(WITH_SENDMAIL)
DSPAM_MODE=	4511
.endif

.ifdef(WITH_POSTFIX_MBC)
DSPAM_MODE=	4511
.endif

.ifdef(WITH_QMAIL)
DSPAM_MODE=	4511
.endif

.ifdef(DSPAM_MODE)
CONFIGURE_ARGS+=	--with-dspam-mode=${DSPAM_MODE}
.endif

.ifdef(WITH_CGI)
.	if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	${LOCALBASE}/sbin/lighttpd:${PORTSDIR}/www/lighttpd
.	else
USE_APACHE=	1.3+
.	endif
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS+=	${SITE_PERL}/mach/GD.pm:${PORTSDIR}/graphics/p5-GD
RUN_DEPENDS+=	${SITE_PERL}/GD/Graph.pm:${PORTSDIR}/graphics/p5-GD-Graph
RUN_DEPENDS+=	${SITE_PERL}/GD/Graph3d.pm:${PORTSDIR}/graphics/p5-GD-Graph3d
RUN_DEPENDS+=	${SITE_PERL}/GD/Text.pm:${PORTSDIR}/graphics/p5-GD-TextUtil
CONFIGURE_ARGS+=--enable-logging
CONFIGURE_ARGS+=--enable-user-logging
USE_PERL5=	yes
PLIST_SUB+=	CGI=""
CGI_PATH?=	${PREFIX}/www/vhosts/dspam
_SED_SCRIPT+=	-e 's/%%CGI%%//g'
_SED_SCRIPT+=	-e 's,%%CGI_PATH%%,${CGI_PATH},g'
#SED_FILES=	${LS}  ${WRKSRC}/cgi/*.pl
#SED_FILES+=	${LS} $PWRKSRC}/cgi/*.cgi
.else
PLIST_SUB+=	CGI="@comment "
_SED_SCRIPT+=	-e '/%%CGI%%/D'
.endif

MAN1=	dspam.1 dspam_clean.1 dspam_dump.1 dspam_merge.1 \
	dspam_stats.1 dspam_train.1
MAN3=	libdspam.3
MLINKS=		libdspam.3 dspam_init.3
MLINKS+=	libdspam.3 dspam_create.3
MLINKS+=	libdspam.3 dspam_addattribute.3
MLINKS+=	libdspam.3 dspam_attach.3
MLINKS+=	libdspam.3 dspam_process.3
MLINKS+=	libdspam.3 dspam_getsource.3
MLINKS+=	libdspam.3 dspam_destroy.3
MLINKS+=	libdspam.3 dspam_detach.3

_DOCS=	CHANGELOG LICENSE README README.FreeBSD RELEASE.NOTES UPGRADING
_DOCSL=	courier.txt exim.txt markov.txt mysql_drv.txt pgsql_drv.txt\
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

pre-extract:	check-options-version
.ifndef(MAINT)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define vars below before make-ing if you need:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "SIGNATURE_LIFE=${SIGNATURE_LIFE} (default 15)"
	@${ECHO_CMD} "DSPAM_OWNER=${DSPAM_OWNER} (default: root)"
	@${ECHO_CMD} "DSPAM_GROUP=${DSPAM_GROUP} (default: mail)"
	@${ECHO_CMD} "DSPAM_MODE=${DSPAM_MODE}"
	@${ECHO_CMD} "DSPAM_ETC=${DSPAM_ETC} (default: ${LOCALBASE}/etc"
	@${ECHO_CMD} "DSPAM_HOME=${DSPAM_HOME} (default: ${_VAR_DIR}/db/dspam)"
	@${ECHO_CMD} "DSPAM_HOME_OWNER=${DSPAM_HOME_OWNER}"
	@${ECHO_CMD} "DSPAM_HOME_GROUP=${DSPAM_HOME_GROUP}"
	@${ECHO_CMD} "DSPAM_HOME_MODE=${DSPAM_HOME_MODE} (default: 0770)"
	@${ECHO_CMD} "LOG_DIR=${LOG_DIR} (default: ${_VAR_DIR}/log/dspam)"
.	ifdef(WITHOUT_SYSLOG)
	@${ECHO_CMD} "LOGFILE=${LOGFILE} (default: ${_VAR_DIR}/log/dspam/dspam.log)"
.	endif
.	ifdef(WITH_CGI)
		@${ECHO_CMD} "Define CGI_PATH before make-ing if you need the CGI files"
		@${ECHO_CMD} "installed in other place that this installation's default"
		@${ECHO_CMD} "${PREFIX}/www/vhosts/dspam"
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
	@${REINPLACE_CMD} -e "s^%%PERL%%^${PERL}^; s^%%DSPAM_PATH%%^${PREFIX}/bin^" ${WRKSRC}/scripts/train.pl

pre-configure:
	@${ECHO_CMD}
.if !( ${LDA_TOTAL_COUNT:S/o//}==${LDA_COUNT} || ${LDA_TOTAL_COUNT}==${LDA_COUNT} )
	@${ECHO_CMD} "You can only use one local delivery agent at once."
	@${ECHO_CMD} "See ${DSPAM_ETC}/dspam.conf for how to change it at run time."
	@${FALSE}
.endif
.if ${_DBDRV}==""
	@${ECHO_CMD}
	@${ECHO_CMD} "You need to enable at least one database back-end."
	@${FALSE}
.endif
.if defined(WITH_VIRT_USERS) && !(defined(USE_MYSQL) || \
	!defined(WITHOUT_POSTGRESQL) || !defined(WITHOUT_HASH) )
	@${ECHO_CMD} "You need MySQL, POSTGRESQL or HASH for virtual users."
	@${FALSE}
.endif
.if defined(WITH_PREF_EXT) && !( defined(USE_MYSQL) || \
	!defined(WITHOUT_POSTGRESQL) )
	@${ECHO_CMD} "You need MySQL or Postgres for preferences extension"
	@${FALSE}
.endif
.ifndef(WITHOUT_DAEMON) && !( defined(USE_MYSQL) || \
	!defined(WITHOUT_POSTGRESQL) || !defined(WITHOUT_HASH) )
	@${ECHO_CMD} "You need MySQL, PostgreSQL or Hash for Daemon mode, because multithreading support is needed"
	@${FALSE}
.endif
.if ( defined(WITH_MYSQL40) && defined(WITH_MYSQL41) && !defined(WITHOUT_MYSQL50) && defined(WITH_MYSQL51))
	@${ECHO_CMD} "You can compile with only one MySQL version driver."
	@${FALSE}
.endif
.if defined(WITH_LDAP) && !( defined(USE_MYSQL) || \
	!defined(WITHOUT_POSTGRESQL) || defined(USE_SQLITE) )
	@${ECHO_CMD} "You need MySQL, Postgres or SQLITE for LDAP."
	@${FALSE}
.endif
.if defined(WITH_USER_HOMEDIR) && defined(WITH_CGI)
	@${ECHO_CMD} "USER_HOMEDIR and CGI are incopatible"
	@${FALSE}
.endif
.if defined(WITH_DOMAIN_SCALE) && defined(WITH_LARGE_SCALE)
	@${ECHO_CMD} "DOMAIN_SCALE and LARGE_SCALE are incopatible"
	@${FALSE}
.endif
.if defined(WITH_LIGHTHTTPD) && !defined(WITH_CGI)
	@${ECHO_CMD} "There's no reason to depend on LightHTTPD if you're not using CGI"
	@${FALSE}
.endif
.ifdef(SNAP_DATE)
	@${ECHO_CMD}
	@${ECHO_CMD} "You can safely ignore the following auto*  errors"
	@${ECHO_CMD}
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)
.endif

post-install:
	${CP} ${WRKSRC}/src/dspam.conf ${WRKSRC}/src/dspam.conf.sample
	cd ${WRKSRC}/src/ && \
		${INSTALL} -o ${DSPAM_OWNER} -g ${DSPAM_GROUP} -m 0640 \
			dspam.conf.sample ${PREFIX}/etc

########
# stupid hack until I figure out where/how to patch
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${MV} ${PREFIX}/lib/pkgconfig/dspam.pc ${PREFIX}/libdata/pkgconfig/dspam.pc
	${TEST} `ls -1 ${PREFIX}/lib/pkgconfig | wc -l` -eq 0 && \
		${RM} -R ${PREFIX}/lib/pkgconfig || true

.ifdef(USE_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}/mysql
	cd  ${WRKSRC}/src/tools.mysql_drv && \
		${INSTALL_DATA} mysql_objects-4.1.sql \
			mysql_objects-space.sql \
			mysql_objects-speed.sql \
			purge-4.1.sql purge.sql \
			virtual_user_aliases.sql \
			virtual_users.sql ${EXAMPLESDIR}/mysql
.endif
.ifndef(WITHOUT_POSTGRESQL)
	@${MKDIR} ${EXAMPLESDIR}/pgsql
	@cd  ${WRKSRC}/src/tools.pgsql_drv && \
		${INSTALL_DATA} *.sql ${EXAMPLESDIR}/pgsql
.endif
.ifdef(USE_SQLITE)
	@${MKDIR} ${EXAMPLESDIR}/sqlite
	cd ${WRKSRC}/src/tools.sqlite_drv && \
		${INSTALL_DATA} *.sql ${EXAMPLESDIR}/sqlite
.endif

.ifdef(WITH_CGI)
.	for I in admin.cgi admingraph.cgi configure.pl dspam.cgi graph.cgi
		@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" ${WRKSRC}/webui/cgi-bin/${I}
.	endfor
	cd ${WRKSRC}/webui/cgi-bin && ${MV} configure.pl configure.pl.sample
	cd ${WRKSRC}/webui/cgi-bin && ${MKDIR} ${CGI_PATH} && \
		${INSTALL_SCRIPT} configure.pl.sample ${CGI_PATH}/ && \
		${INSTALL_SCRIPT} *.cgi ${CGI_PATH} && \
		${INSTALL_DATA} rgb.txt ${CGI_PATH}/
	cd ${WRKSRC}/webui/htdocs && \
		${INSTALL_DATA} base.css dspam-logo-small.gif ${CGI_PATH}/
	cd ${WRKSRC}/webui/cgi-bin && \
		${INSTALL_DATA} default.prefs ${CGI_PATH}/default.prefs.sample
	cd ${WRKSRC}/webui/cgi-bin && \
		${INSTALL_DATA} admins ${CGI_PATH}/admins.sample
	${MKDIR} ${CGI_PATH}/templates && cd ${WRKSRC}/webui/cgi-bin/templates && \
		${INSTALL_DATA} *.html ${CGI_PATH}/templates/
.endif

	@${SED} ${_SED_SCRIPT} ${.CURDIR}/pkg-message > ${WRKSRC}/README.FreeBSD

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${_DOCS} ${DOCSDIR}
	@cd ${WRKSRC}/doc && ${INSTALL_DATA} ${_DOCSL} ${DOCSDIR}
	@cd ${FILESDIR} && ${INSTALL_DATA} UPDATING ${DOCSDIR}/UPDATING
.endif

	@${MKDIR} -m ${DSPAM_HOME_MODE} ${DSPAM_HOME}
	@${CHOWN} ${DSPAM_HOME_OWNER}:${DSPAM_HOME_GROUP} ${DSPAM_HOME}
.for _file in firstrun.txt firstspam.txt quarantinefull.txt
	@if ! ${TEST} -e ${WRKSRC}/txt/${_file}.sample;\
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

check-options-version:
.ifdef(_OPTIONS_READ)
	@(if ${PKG_VERSION} -t ${_OPTIONS_READ} ${MIN_OPTIONS_VER} | ${GREP} -q '<'; \
	 then	${ECHO_CMD} ""; \
		${ECHO_CMD} "===> You have unsupported (old) OPTIONS, please do a 'make config; make'"; \
		${ECHO_CMD} ""; \
		exit 1; \
	 fi)
.endif

.include <bsd.port.post.mk>
