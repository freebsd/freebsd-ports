# Created by: Janky Jay <ek@purplehat.org>
# $FreeBSD$

PORTNAME=	maia
DISTVERSION=	1.0.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://www.purplehat.org/downloads/maia/

MAINTAINER=	ek@purplehat.org
COMMENT=	Web-based management system based on amavisd-new and SpamAssassin

RUN_DEPENDS=	p5-Unix-Syslog>=0.94:sysutils/p5-Unix-Syslog \
		p5-MIME-Tools>=4.116:mail/p5-MIME-Tools \
		p5-Convert-TNEF>=0.08:converters/p5-Convert-TNEF \
		p5-Convert-UUlib>=1.08,1:converters/p5-Convert-UUlib \
		p5-Net-CIDR-Lite>=0.18:net/p5-Net-CIDR-Lite \
		p5-forks>=0.34:devel/p5-forks \
		p5-Archive-Zip>=0.10:archivers/p5-Archive-Zip \
		p5-IO-stringy>=1.203:devel/p5-IO-stringy \
		p5-IO-Socket-INET6>=1.27:net/p5-IO-Socket-INET6 \
		p5-Text-CSV>=1.02:textproc/p5-Text-CSV \
		p5-Data-UUID>=1.148:devel/p5-Data-UUID \
		p5-Template-Toolkit>=2.13:www/p5-Template-Toolkit \
		p5-Net-Server>=0.93:net/p5-Net-Server

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes

DOCS=	LICENSE.txt README.md maiad.conf.dist maia-mysql.sql maia-pgsql.sql maia.conf.dist

USERS=	vscan
GROUPS=	vscan
MAIAHOME=	/var/maiad
MAIAQUARANTINE?=	/var/maiad/virusmails

PEAR_DIR?=	${LOCALBASE}/share/pear
PLIST_SUB+=	USERS="${USERS}" GROUPS="${GROUPS}" WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"

OPTIONS_DEFINE=	APACHE LIGHTTPD WEBHOST MYSQL MYSQLSERVER PGSQL PGSQLSERVER DOVECOT2 \
		POSTFIX PFA FUZZYOCR CLAMAV SPAMASSASSIN BDB ALTERMIME CRYPT \
		IPCOUNTRY DOMAINKEYS SPF DKIM FILE RAR ARJ UNARJ LHA ARC NOMARCH CAB \
		RPM ZOO UNZOO LZOP FREEZE P7ZIP TNEF DOCS

OPTIONS_DEFAULT=	MYSQL CLAMAV SPAMASSASSIN BDB IPCOUNTRY \
			DOMAINKEYS SPF DKIM FILE UNRAR ARJ LHA ARC CAB RPM \
			ZOO P7ZIP
APACHE_DESC=		Use Apache web server
LIGHTTPD_DESC=		Use LighTTPD web server
WEBHOST_DESC=		PHP, PEAR, etc... for Maia web interface
MYSQL_DESC=		Use MySQL datebase
MYSQLSERVER_DESC=	Install MySQL Server
PGSQL_DESC=		Use PgSQL database
PGSQLSERVER_DESC=	Install PGSQL Server
DOVECOT2_DESC=		Use Dovecot 2.x IMAP/POP3
POSTFIX_DESC=		Use Postfix MTA
PFA_DESC=		Use Postfixadmin
FUZZYOCR_DESC=		Use FuzzyOcr
CLAMAV_DESC=		Use ClamAV anti-virus
SPAMASSASSIN_DESC=	Use SpamAssassin
BDB_DESC=		Use BerkeleyDB
ALTERMIME_DESC=		Use AlterMime
CRYPT_DESC=		Encryption support
IPCOUNTRY_DESC=		SpamAssassin IP Country plugin
DOMAINKEYS_DESC=	SpamAssassin DomainKey plugin
SPF_DESC=		SpamAssassin SPF plugin
DKIM_DESC=		SpamAssassin DKIM plugin
FILE_DESC=		Use newer file(1) utility from ports
RAR_DESC=		RAR support with archivers/rar
UNRAR_DESC=		RAR support with archivers/unrar
ARJ_DESC=		ARJ support with archivers/arj
UNARJ_DESC=		ARJ support with archivers/unarj
LHA_DESC=		LHA support with archivers/lha
ARC_DESC=		ARC support with archivers/arc
NOMARCH_DESC=		ARC support with archivers/nomarch
CAB_DESC=		CAB support with archivers/cabextract
RPM_DESC=		RPM support with archivers/rpm2cpio
ZOO_DESC=		ZOO support with archivers/zoo
UNZOO_DESC=		ZOO support with archivers/unzoo
LZOP_DESC=		LZOP support with archivers/lzop
FREEZE_DESC=		FREEZE support with archivers/freeze
P7ZIP_DESC=		P7ZIP support with archivers/p7zip
TNEF_DESC=		Add external tnef decoder

SUB_FILES=	maiad pkg-message
SHEBANG_FILES=	maiad
SUB_LIST+=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		MAIAHOME=${MAIAHOME} \
		MAIAQUARANTINE=${MAIAQUARANTINE} \
		ETCDIR=${ETCDIR}
USE_RC_SUBR+=	maiad

.include <bsd.port.options.mk>

# Code is a bit fiddly here; we can't use USE variables after pre.mk so we have
# to duplicate some WITH_ parts like WEBHOST that use pre.mk vars as well as
# setting USE_ variables. C'est la vie.

.if ${PORT_OPTIONS:MAPACHE}
USES+=		apache:run,2.2+
.endif

.if ${PORT_OPTIONS:MWEBHOST}
USE_PHP=	bcmath ctype dom gettext hash iconv imap json mbstring \
		mcrypt pdo pdo_sqlite posix session simplexml sockets \
		sqlite3 tokenizer xml wddx xmlreader xmlwriter xmlrpc

RUN_DEPENDS+=	${PEAR_DIR}/Mail/mime.php:mail/pear-Mail_Mime@${PHP_FLAVOR} \
		${PEAR_DIR}/Mail/mimeDecode.php:mail/pear-Mail_mimeDecode@${PHP_FLAVOR} \
		${PEAR_DIR}/DB.php:databases/pear-DB@${PHP_FLAVOR} \
		${PEAR_DIR}/Pager/Pager.php:devel/pear-Pager@${PHP_FLAVOR} \
		${PEAR_DIR}/Net/Socket.php:net/pear-Net_Socket@${PHP_FLAVOR} \
		${PEAR_DIR}/Net/SMTP.php:net/pear-Net_SMTP@${PHP_FLAVOR} \
		${PEAR_DIR}/Log.php:sysutils/pear-Log@${PHP_FLAVOR} \
		${PEAR_DIR}/HTMLPurifier.php:devel/pear-htmlpurifier@${PHP_FLAVOR} \
		${PEAR_DIR}/Net/IMAP.php:mail/pear-Net_IMAP@${PHP_FLAVOR} \
		${PEAR_DIR}/Net/POP3.php:net/pear-Net_POP3@${PHP_FLAVOR} \
		${PEAR_DIR}/Auth/SASL.php:security/pear-Auth_SASL@${PHP_FLAVOR} \
		${PEAR_DIR}/Image/Color.php:graphics/pear-Image_Color@${PHP_FLAVOR} \
		${PEAR_DIR}/Image/Canvas.php:graphics/pear-Image_Canvas@${PHP_FLAVOR} \
		${PEAR_DIR}/Image/Graph.php:graphics/pear-Image_Graph@${PHP_FLAVOR} \
		${PEAR_DIR}/Numbers/Roman.php:textproc/pear-Numbers_Roman@${PHP_FLAVOR} \
		${PEAR_DIR}/Numbers/Words.php:textproc/pear-Numbers_Words@${PHP_FLAVOR} \
		${PEAR_DIR}/MDB2.php:databases/pear-MDB2@${PHP_FLAVOR} \
		${PEAR_DIR}/MDB2/Driver/mysql.php:databases/pear-MDB2_Driver_mysql@${PHP_FLAVOR} \
		${LOCALBASE}/share/smarty/Smarty.class.php:www/smarty2@${PHP_FLAVOR} \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/scrypt.so:security/pecl-scrypt@${PHP_FLAVOR}
PLIST_SUB+=     WEBHOST=""
.else
PLIST_SUB+=     WEBHOST="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.endif
.if ${PORT_OPTIONS:MMYSQL} && ${PORT_OPTIONS:MWEBHOST}
USE_PHP+=	mysql mysqli
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
.endif
.if ${PORT_OPTIONS:MPGSQL} && ${PORT_OPTIONS:MWEBHOST}
USE_PHP+=	pgsql
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:www/lighttpd
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MMYSQLSERVER}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
.endif

.if ${PORT_OPTIONS:MPGSQLSERVER}
USES:=		${USES:Npgsql} pgsql
WANT_PGSQL=	server
.endif

.if ${PORT_OPTIONS:MDOVECOT2}
RUN_DEPENDS+=	dovecot:mail/dovecot
.endif

.if ${PORT_OPTIONS:MPOSTFIX}
RUN_DEPENDS+=	postfix:mail/postfix
.endif

.if ${PORT_OPTIONS:MPFA}
RUN_DEPENDS+=	${LOCALBASE}/www/postfixadmin/config.inc.php:mail/postfixadmin
.endif

.if ${PORT_OPTIONS:MFUZZYOCR}
RUN_DEPENDS+=	p5-FuzzyOcr-devel>=0:mail/p5-FuzzyOcr-devel
.endif

.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	clamd:security/clamav
.endif

.if ${PORT_OPTIONS:MSPAMASSASSIN}
RUN_DEPENDS+=	spamassassin>=0:mail/spamassassin
.endif

.if ${PORT_OPTIONS:MBDB}
RUN_DEPENDS+=	p5-BerkeleyDB>=0:databases/p5-BerkeleyDB
.endif

.if ${PORT_OPTIONS:MALTERMIME}
RUN_DEPENDS+=	altermime:mail/altermime
.endif

.if ${PORT_OPTIONS:MCRYPT}
RUN_DEPENDS+=	p5-Crypt-Blowfish>=0:security/p5-Crypt-Blowfish \
		p5-Crypt-OpenSSL-RSA>=0:security/p5-Crypt-OpenSSL-RSA \
		p5-Crypt-CBC>=0:security/p5-Crypt-CBC
.endif

.if ${PORT_OPTIONS:MIPCOUNTRY}
RUN_DEPENDS+=	p5-IP-Country>=0:net/p5-IP-Country
.endif

.if ${PORT_OPTIONS:MDOMAINKEYS}
RUN_DEPENDS+=	p5-Mail-DomainKeys>=0:mail/p5-Mail-DomainKeys
.endif

.if ${PORT_OPTIONS:MSPF}
RUN_DEPENDS+=	p5-Mail-SPF>=0:mail/p5-Mail-SPF
.endif

.if ${PORT_OPTIONS:MDKIM}
RUN_DEPENDS+=	p5-Mail-DKIM>=0:mail/p5-Mail-DKIM
.endif

.if ${PORT_OPTIONS:MFILE}
# security fix, file > 4.21 needed
RUN_DEPENDS+=	file>=4.21:sysutils/file
.endif

# archivers/rar is a 32-bit binary port, we don't want the install to fail
# at that port, therefore we will block instantly here if the platform does
# not suit rar.
.if ${PORT_OPTIONS:MRAR}
IA32_BINARY_PORT=	yes
RUN_DEPENDS+=	rar:archivers/rar
.endif

.if ${PORT_OPTIONS:MUNRAR}
RUN_DEPENDS+=	unrar:archivers/unrar
.endif

.if ${PORT_OPTIONS:MARJ}
RUN_DEPENDS+=	arj:archivers/arj
.endif

.if ${PORT_OPTIONS:MUNARJ}
RUN_DEPENDS+=	unarj:archivers/unarj
.endif

.if ${PORT_OPTIONS:MLHA}
RUN_DEPENDS+=	lha:archivers/lha
.endif

.if ${PORT_OPTIONS:MARC}
RUN_DEPENDS+=	arc:archivers/arc
.endif

.if ${PORT_OPTIONS:MNOMARCH}
RUN_DEPENDS+=	nomarch:archivers/nomarch
.endif

.if ${PORT_OPTIONS:MCAB}
RUN_DEPENDS+=	cabextract:archivers/cabextract
.endif

.if ${PORT_OPTIONS:MRPM}
RUN_DEPENDS+=	rpm2cpio.pl:archivers/rpm2cpio
.endif

.if ${PORT_OPTIONS:MZOO}
# DOS condition in 2.10.1_2
RUN_DEPENDS+=	zoo>=2.10.1_2:archivers/zoo
.endif

.if ${PORT_OPTIONS:MUNZOO}
RUN_DEPENDS+=	unzoo>=4.4_1:archivers/unzoo
.endif

.if ${PORT_OPTIONS:MLZOP}
RUN_DEPENDS+=	lzop:archivers/lzop
.endif

.if ${PORT_OPTIONS:MFREEZE}
RUN_DEPENDS+=	unfreeze:archivers/freeze
.endif

.if ${PORT_OPTIONS:MP7ZIP}
RUN_DEPENDS+=	7zr:archivers/p7zip
.endif

.if ${PORT_OPTIONS:MTNEF}
RUN_DEPENDS+=	tnef:converters/tnef
.endif

.include <bsd.port.pre.mk>

post-patch:
.for m in scripts/configtest.pl scripts/expire-quarantine-cache.pl \
	scripts/load-sa-rules.pl scripts/maiadbtool.pl \
	scripts/process-quarantine.pl scripts/resend.pl scripts/send-quarantine-digests.pl \
	scripts/send-quarantine-reminders.pl scripts/stats-snapshot.pl
		@${REINPLACE_CMD} -e "s|/etc/maia/maia.conf|${ETCDIR}/maia.conf|" \
			${WRKSRC}/${m}
.endfor

.for i in digest.tpl newuser.tpl reminder.tpl
	${MV} ${WRKSRC}/templates/${i} ${WRKSRC}/templates/${i}.dist
.endfor

	@${REINPLACE_CMD} -e "s|daemon_user  = 'maia'|daemon_user  = '${USERS}'|" \
		-e "s|daemon_group = 'maia'|daemon_group = '${GROUPS}'|" \
		-e "s|/var/lib/maia|${MAIAHOME}|" \
		-e "s|'unrar'|'unrar v -c- -p- --'|" \
		-e "s|DO_SYSLOG = 0|DO_SYSLOG = 1|" ${WRKSRC}/maiad.conf.dist

	@${REINPLACE_CMD} -e "s|/etc/maia.conf|${ETCDIR}/maia.conf|" \
		-e "s|username = 'maia'|username = '${USERS}'|" \
		-e "s|/var/lib/maia|${DATADIR}|" \
		-e "s|/usr/bin/sa-learn|${PREFIX}/bin/sa-learn|" \
		-e "s|local_cf_dir = undef|local_cf_dir = '${PREFIX}/etc/mail/spamassassin'|" \
		-e "s|system_rules_dir = undef|system_rules_dir = '/var/db/spamassassin'|" \
		-e "s|user_rules_dir = undef|user_rules_dir = '${MAIAHOME}/.spamassassin'|" \
		-e "s|template_dir = '/etc/maia/templates/'|template_dir = '${ETCDIR}/templates/'|" \
			${WRKSRC}/maia.conf.dist

	@${REINPLACE_CMD} -e "s|/etc/maia/maiad.conf|${ETCDIR}/maiad.conf|" \
		-e "s|/var/lib/maia|${DATADIR}|" \
		-e "s@'zoo'\]@['zoo','unzoo'] ]@" ${WRKSRC}/maiad

	@${FIND} -E ${WRKSRC} -iregex '.*(bak|~)$$' -delete

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/php && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	${LN} -s ${PREFIX}/share/smarty ${STAGEDIR}${WWWDIR}/libs/Smarty
	${MKDIR} -p ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripts
	${MKDIR} -p ${STAGEDIR}${ETCDIR}/templates
.for i in digest.tpl newuser.tpl reminder.tpl
	${INSTALL} -m 644 ${WRKSRC}/templates/${i}.dist ${STAGEDIR}${ETCDIR}/templates
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/maiad ${STAGEDIR}${PREFIX}/sbin
	${INSTALL} -m 640 ${WRKSRC}/maiad.conf.dist ${STAGEDIR}${ETCDIR}/maiad.conf.dist
	${INSTALL} -m 640 ${WRKSRC}/maia.conf.dist ${STAGEDIR}${ETCDIR}/maia.conf.dist

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
