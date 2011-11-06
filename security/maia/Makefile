# Ports collection Makefile for:    maia
# Date created:                         03 Jan 2008
# Whom:                                 Janky Jay <ek@purplehat.org>
#
# $FreeBSD$
#

PORTNAME=	maia
DISTVERSION=	1.0.3-${SVNREVISION}
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.purplehat.org/downloads/maia/

MAINTAINER=	ek@purplehat.org
COMMENT=	A web-based management system based on amavisd-new and SpamAssassin

RUN_DEPENDS=	p5-Unix-Syslog>=0.94:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		p5-MIME-Tools>=4.116:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Convert-TNEF>=0.08:${PORTSDIR}/converters/p5-Convert-TNEF \
		p5-Convert-UUlib>=1.08,1:${PORTSDIR}/converters/p5-Convert-UUlib \
		p5-Net-CIDR-Lite>=0.18:${PORTSDIR}/net/p5-Net-CIDR-Lite \
		p5-forks>=0.34:${PORTSDIR}/devel/p5-forks \
		p5-Archive-Zip>=0.10:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-IO-stringy>=1.203:${PORTSDIR}/devel/p5-IO-stringy \
		p5-IO-Socket-INET6>=1.27:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Text-CSV>=1.02:${PORTSDIR}/textproc/p5-Text-CSV \
		p5-Data-UUID>=1.148:${PORTSDIR}/devel/p5-Data-UUID \
		p5-Template-Toolkit>=2.13:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Net-Server>=0.93:${PORTSDIR}/net/p5-Net-Server

# SVN source: https://www.maiamailguard.com/svn/branches/1.0
SVNREVISION=	r1575
WRKSRC=		${WRKDIR}/${PORTNAME}-1.0-${SVNREVISION}
USE_PERL5_RUN=	5.8.2+
NO_BUILD=	yes

DOCS=	LICENSE README maiad.conf.dist maia-mysql.sql maia-pgsql.sql maia.conf.dist

USERS=	vscan
GROUPS=	vscan
MAIADIR?=	/var/maiad
MAIAQUARANTINE?=	/var/maiad/virusmails
PEAR_DIR?=	${LOCALBASE}/share/pear

OPTIONS=	APACHE	"Use Apache web server"	off\
		LIGHTTPD	"Use LighTTPD web server"	off \
		WEBHOST	"PHP, PEAR, etc... for Maia web interface"	off \
		MYSQL	"Use MySQL datebase"		on \
		MYSQLSERVER	"Install MySQL Server"	on \
		PGSQL	"Use PgSQL database"		off \
		PGSQLSERVER	"Install PGSQL Server"	off \
		DOVECOT	"Use Dovecot IMAP/POP3"	on \
		POSTFIX	"Use Postfix MTA"	on \
		PFA	"Use Postfixadmin"	off \
		FUZZYOCR	"Use FuzzyOcr"	off \
		CLAMAV	"Use ClamAV anti-virus"	on \
		SPAMASSASSIN	"Use SpamAssassin"	on \
		GRAPHICS	"Enable pie chart stats"	off \
		BDB	"Use BerkeleyDB"	on \
		ALTERMIME	"Use AlterMime"	off \
		CRYPT	"Encryption support"	off \
		IPCOUNTRY	"SpamAssassin IP Country plugin"	on \
		DOMAINKEYS	"SpamAssassin DomainKey plugin"	on \
		SPF	"SpamAssassin SPF plugin"	on \
		DKIM	"SpamAssassin DKIM plugin"	on \
		FILE	"Use newer file(1) utility from ports"	on \
		RAR	"RAR support with archivers/rar"	off \
		UNRAR	"RAR support with archivers/unrar"	on \
		ARJ	"ARJ support with archivers/arj"	on \
		UNARJ	"ARJ support with archivers/unarj"	off \
		LHA	"LHA support with archivers/lha"	on \
		ARC	"ARC support with archivers/arc"	on \
		NOMARCH	"ARC support with archivers/nomarch"	off \
		CAB	"CAB support with archivers/cabextract"	on \
		RPM	"RPM support with archivers/rpm2cpio"	on \
		ZOO	"ZOO support with archivers/zoo"	on \
		UNZOO	"ZOO support with archivers/unzoo"	off \
		LZOP	"LZOP support with archivers/lzop"	off \
		FREEZE	"FREEZE support with archivers/freeze"	on \
		P7ZIP	"P7ZIP support with archivers/p7zip"	on \
		TNEF	"Add external tnef decoder"	off

SUB_FILES=	pkg-install pkg-deinstall pkg-message
SUB_LIST+=	MAIAUSER=${USERS} \
		MAIAGROUP=${GROUPS} \
		MAIADIR=${MAIADIR} \
		MAIAQUARANTINE=${MAIAQUARANTINE}
USE_RC_SUBR+=	maiad

.include <bsd.port.options.mk>

# Code is a bit fiddly here; we can't use USE variables after pre.mk so we have
# to duplicate some WITH_ parts like WEBHOST that use pre.mk vars as well as
# setting USE_ variables. C'est la vie.

.if defined(WITH_APACHE)
USE_APACHE=	20+
.endif

.if defined(WITH_WEBHOST)
USE_PHP=	bcmath ctype dom gettext hash iconv imap json mbstring \
		mcrypt pdo pdo_sqlite posix session simplexml sockets \
		sqlite tokenizer xml wddx xmlreader xmlwriter xmlrpc
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
USE_PHP+=	mysql mysqli
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
USE_PHP+=	pgsql
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if defined(WITH_WEBHOST)
RUN_DEPENDS+=	${PEAR_DIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		${PEAR_DIR}/Mail/mimeDecode.php:${PORTSDIR}/mail/pear-Mail_mimeDecode \
		${PEAR_DIR}/DB.php:${PORTSDIR}/databases/pear-DB \
		${PEAR_DIR}/Pager/Pager.php:${PORTSDIR}/devel/pear-Pager \
		${PEAR_DIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEAR_DIR}/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP \
		${PEAR_DIR}/Log.php:${PORTSDIR}/sysutils/pear-Log \
		${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty
.endif

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_MYSQLSERVER)
RUN_DEPENDS+=	${LOCALBASE}/bin/mysqld_safe:${PORTSDIR}/databases/mysql55-server
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
.endif

.if defined(WITH_PGSQLSERVER)
RUN_DEPENDS+=	${LOCALBASE}/bin/pg_ctl:${PORTSDIR}/databases/postgresql84-server
.endif

.if defined(WITH_DOVECOT)
RUN_DEPENDS+=	dovecot:${PORTSDIR}/mail/dovecot
.endif

.if defined(WITH_POSTFIX)
RUN_DEPENDS+=	postfix:${PORTSDIR}/mail/postfix
.endif

.if defined(WITH_PFA)
RUN_DEPENDS+=	${LOCALBASE}/www/postfixadmin/config.inc.php:${PORTSDIR}/mail/postfixadmin
.endif

.if defined(WITH_FUZZYOCR)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SpamAssassin/Plugin/FuzzyOcr.pm:${PORTSDIR}/mail/p5-FuzzyOcr-devel
.endif

.if defined(WITH_CLAMAV)
RUN_DEPENDS+=	clamd:${PORTSDIR}/security/clamav
.endif

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SpamAssassin.pm:${PORTSDIR}/mail/p5-Mail-SpamAssassin
.endif

.if defined(WITH_GRAPHICS)
RUN_DEPENDS+=	${PEAR_DIR}/Image/Color.php:${PORTSDIR}/graphics/pear-Image_Color \
		${PEAR_DIR}/Image/Canvas.php:${PORTSDIR}/graphics/pear-Image_Canvas \
		${PEAR_DIR}/Image/Graph.php:${PORTSDIR}/graphics/pear-Image_Graph \
		${PEAR_DIR}/Numbers/Roman.php:${PORTSDIR}/textproc/pear-Numbers_Roman \
		${PEAR_DIR}/Numbers/Words.php:${PORTSDIR}/textproc/pear-Numbers_Words
.endif

.if defined(WITH_BDB)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB
.endif

.if defined(WITH_ALTERMIME)
RUN_DEPENDS+=	altermime:${PORTSDIR}/mail/altermime
.endif

.if defined(WITH_CRYPT)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Crypt/Blowfish.pm:${PORTSDIR}/security/p5-Crypt-Blowfish \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/Crypt/CBC.pm:${PORTSDIR}/security/p5-Crypt-CBC
.endif

.if defined(WITH_IPCOUNTRY)
RUN_DEPENDS+=	${SITE_PERL}/IP/Country.pm:${PORTSDIR}/net/p5-IP-Country
.endif

.if defined(WITH_DOMAINKEYS)
RUN_DEPENDS+=	${SITE_PERL}/Mail/DomainKeys.pm:${PORTSDIR}/mail/p5-Mail-DomainKeys
.endif

.if defined(WITH_SPF)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SPF.pm:${PORTSDIR}/mail/p5-Mail-SPF
.endif

.if defined(WITH_DKIM)
RUN_DEPENDS+=	${SITE_PERL}/Mail/DKIM.pm:${PORTSDIR}/mail/p5-Mail-DKIM
.endif

.if defined(WITH_FILE)
# security fix, file > 4.21 needed
RUN_DEPENDS+=	file>=4.21:${PORTSDIR}/sysutils/file
.endif

# archviers/rar is a 32-bit binary port, we don't want the install to fail
# at that port, therefore we will block instantly here if the platform does
# not suit rar.
.if defined(WITH_RAR)
IA32_BINARY_PORT=	yes
RUN_DEPENDS+=	rar:${PORTSDIR}/archivers/rar
.endif

.if defined(WITH_UNRAR)
RUN_DEPENDS+=	unrar:${PORTSDIR}/archivers/unrar
.endif

.if defined(WITH_ARJ)
RUN_DEPENDS+=	arj:${PORTSDIR}/archivers/arj
.endif

.if defined(WITH_UNARJ)
RUN_DEPENDS+=	unarj:${PORTSDIR}/archivers/unarj
.endif

.if defined(WITH_LHA)
RUN_DEPENDS+=	lha:${PORTSDIR}/archivers/lha
.endif

.if defined(WITH_ARC)
RUN_DEPENDS+=	arc:${PORTSDIR}/archivers/arc
.endif

.if defined(WITH_NOMARCH)
RUN_DEPENDS+=	nomarch:${PORTSDIR}/archivers/nomarch
.endif

.if defined(WITH_CAB)
RUN_DEPENDS+=	cabextract:${PORTSDIR}/archivers/cabextract
.endif

.if defined(WITH_RPM)
RUN_DEPENDS+=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
.endif

.if defined(WITH_ZOO)
# DOS condition in 2.10.1_2
RUN_DEPENDS+=	zoo>=2.10.1_2:${PORTSDIR}/archivers/zoo
.endif

.if defined(WITH_UNZOO)
RUN_DEPENDS+=	unzoo>=4.4_1:${PORTSDIR}/archivers/unzoo
.endif

.if defined(WITH_LZOP)
RUN_DEPENDS+=	lzop:${PORTSDIR}/archivers/lzop
.endif

.if defined(WITH_FREEZE)
RUN_DEPENDS+=	unfreeze:${PORTSDIR}/archivers/freeze
.endif

.if defined(WITH_P7ZIP)
RUN_DEPENDS+=	7zr:${PORTSDIR}/archivers/p7zip
.endif

.if defined(WITH_TNEF)
RUN_DEPENDS+=	tnef:${PORTSDIR}/converters/tnef
.endif

post-patch:
.for m in scripts/configtest.pl scripts/expire-quarantine-cache.pl \
	scripts/generate-key.pl scripts/load-sa-rules.pl scripts/maiadbtool.pl \
	scripts/process-quarantine.pl scripts/resend.pl scripts/send-quarantine-digests.pl \
	scripts/send-quarantine-reminders.pl scripts/stats-snapshot.pl
		@${REINPLACE_CMD} -e "s|/etc/maia/maia.conf|${PREFIX}/etc/maia.conf|" \
			${WRKSRC}/${m}

.endfor
.for a in maiad.conf.dist
	@${REINPLACE_CMD} -e "s|daemon_user  = 'maia'|daemon_user  = '${USERS}'|" \
		-e "s|daemon_group = 'maia'|daemon_group = '${GROUPS}'|" \
		-e "s|/var/lib/maia|${MAIADIR}|" \
		-e "s|/var/log/maia|${MAIADIR}|" ${WRKSRC}/${a}
.endfor
.for i in maia.conf.dist
	@${REINPLACE_CMD} -e "s|/etc/maia.conf|${PREFIX}/etc/maia.conf|" \
		-e "s|username = 'maia'|username = '${USERS}'|" \
		-e "s|/var/lib/maia|${MAIADIR}/maia|" \
		-e "s|/usr/bin/sa-learn|/usr/local/bin/sa-learn|" \
		-e "s|local_cf_dir = undef|local_cf_dir = '${PREFIX}/etc/mail/spamassassin'|" \
		-e "s|system_rules_dir = undef|system_rules_dir = '/var/db/spamassassin'|" \
		-e "s|user_rules_dir = undef|user_rules_dir = '${MAIADIR}/.spamassassin'|" \
		-e "s|pid_dir = '/var/run/maia/'|pid_dir = '${MAIADIR}/'|" \
		-e "s|log_dir = '/var/log/maia'|log_dir = '${MAIADIR}'|" \
		-e "s|template_dir = '/etc/maia/templates/'|template_dir = '${MAIADIR}/maia/templates/'|" \
			${WRKSRC}/${i}
.endfor
.for a in maiad
	@${REINPLACE_CMD} -e "s|/etc/maia/maiad.conf|${PREFIX}/etc/maiad.conf|" \
		-e "s|/var/lib/maia|${MAIADIR}|" \
		-e "s@'zoo'\]@['zoo','unzoo'] ]@" ${WRKSRC}/${a}
.endfor
	@${FIND} -E ${WRKSRC} -iregex '.*(bak|~)$$' -delete

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

do-install:
	@${INSTALL} -d ${WWWDIR}
	@cd ${WRKSRC}/php && ${FIND} . | ${CPIO} --quiet -pdm -L ${WWWDIR}
	@cd ${WRKSRC}/scripts && ${FIND} . | ${CPIO} --quiet -pdm -L ${MAIADIR}/maia/scripts
	@cd ${WRKSRC}/templates && ${FIND} . | ${CPIO} --quiet -pdm -L ${MAIADIR}/maia/templates

.for i in maiad
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/sbin
.endfor
	@${INSTALL_SCRIPT} -m 640 ${WRKSRC}/maiad.conf.dist ${PREFIX}/etc/maiad.conf.dist
	@${INSTALL_SCRIPT} -m 640 ${WRKSRC}/maia.conf.dist ${PREFIX}/etc/maia.conf.dist
#
#  This can contain sensitive information, e.g. SQL passwords, so it should be handled
#  with care.
#
.if !exists(${PREFIX}/www/${PORTNAME}/config.php)
	@${INSTALL} -o ${WWWOWN} -g ${WWWGRP} -m 640 \
		${WRKSRC}/php/config.php.dist \
		${PREFIX}/www/${PORTNAME}/config.php
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
.for maiaconf in maia maiad
	@if [ ! -f ${PREFIX}/etc/${maiaconf}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${maiaconf}.conf.dist \
		${PREFIX}/etc/${maiaconf}.conf ; \
	fi
	@${CHOWN} ${USERS}:${GROUPS} ${PREFIX}/etc/${maiaconf}.conf \
		${PREFIX}/etc/${maiaconf}.conf.dist
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHOWN} -R ${USERS}:${GROUPS} ${MAIADIR}/
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${USERS}:${GROUPS} ${MAIADIR}' >> ${TMPPLIST}
	@${LN} -s ${PREFIX}/share/smarty ${PREFIX}/www/${PORTNAME}/libs/Smarty
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
