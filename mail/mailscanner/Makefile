# New ports collection makefile for:	MailScanner
# Date created:				17 March 2003
# Whom:					Jan-Peter Koopmann <j.koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	MailScanner
PORTVERSION=	4.78.9
CATEGORIES=	mail
MASTER_SITES=	http://www.mailscanner.info/files/4/tar/
DISTNAME=	${PORTNAME}-install-${PORTVERSION}-${PATCHLEVEL}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful virus/spam scanning framework for mail gateways

BUILD_DEPENDS=	\
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
	${SITE_PERL}/${PERL_ARCH}/Bundle/DBI.pm:${PORTSDIR}/databases/p5-DBI \
	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
	${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
	${SITE_PERL}/Convert/BinHex.pm:${PORTSDIR}/converters/p5-Convert-BinHex \
	${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
	${SITE_PERL}/Net/Ident.pm:${PORTSDIR}/net/p5-Net-Ident \
	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
	${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
	${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/${PERL_ARCH}/Filesys/Df.pm:${PORTSDIR}/sysutils/p5-Filesys-Df \
	${SITE_PERL}/Sys/Hostname/Long.pm:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
	${SITE_PERL}/${PERL_ARCH}/IO/Handle.pm:${PORTSDIR}/devel/p5-IO \
	${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite

RUN_DEPENDS=	${BUILD_DEPENDS} \
		bash:${PORTSDIR}/shells/bash \
		tnef:${PORTSDIR}/converters/tnef \
		wget:${PORTSDIR}/ftp/wget

OPTIONS=	SPAMASSASSIN "Install SpamAssassin" on \
		CLAMAV "Install ClamAV" on \
		CLAMAVMODULE "Install ClamAV Module" off \
		BDC "Install BitDefender" off

CONFLICTS=	MailScanner-devel-[0-9]*

PATCHLEVEL=	1

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-install-${PORTVERSION}
SUB_FILES=	pkg-message

MAN8=		MailScanner.8
MLINKS=		MailScanner.8 mailscanner.8

.include <bsd.port.pre.mk>

.if defined(WITH_SPAMASSASSIN)
RUN_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin
PLIST_SUB+=	SPAMASSASSIN=""
.else
PLIST_SUB+=	SPAMASSASSIN="@comment "
.endif

# backwards compatibility
.if defined(NO_SPAMASSASSIN_SYMLINK)
WITHOUT_SPAMASSASSIN_SYMLINK=${NO_SPAMASSASSIN_SYMLINK}
.endif

.if defined(WITHOUT_SPAMASSASSIN_SYMLINK)
PLIST_SUB+=	SPAMASSASSIN_SYMLINK="@comment "
.else
PLIST_SUB+=	SPAMASSASSIN_SYMLINK=""
.endif

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	clamscan:${PORTSDIR}/security/clamav
.endif

.if defined(WITH_CLAMAVMODULE)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Mail/ClamAV.pm:${PORTSDIR}/mail/p5-Mail-ClamAV
.endif

.if defined(WITH_CLAMAV)||defined(WITH_CLAMAVMODULE)
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		unarj:${PORTSDIR}/archivers/unarj \
		unace:${PORTSDIR}/archivers/unace \
		lha:${PORTSDIR}/archivers/lha
.endif

.if defined(WITH_BDC)
RUN_DEPENDS+=	bdc:${PORTSDIR}/security/bdc
.endif

DOC_FILES=	INSTALL.FreeBSD INSTALL.OpenBSD README
ETC_FILES=	MailScanner.conf filename.rules.conf \
		archives.filename.rules.conf archives.filetype.rules.conf \
		filetype.rules.conf spam.assassin.prefs.conf \
		spam.lists.conf virus.scanners.conf \
		phishing.safe.sites.conf \
		phishing.bad.sites.conf \
		country.domains.conf
MCP_FILES=	mcp.spam.assassin.prefs.conf \
		10_example.cf v320.pre
USRLOCAL_FILES_LIB=	\
		bitdefender-autoupdate f-prot-autoupdate \
		f-secure-wrapper inoculan-autoupdate \
		kavdaemonclient-wrapper mcafee-autoupdate \
		nod32-autoupdate rav-autoupdate \
		rav-wrapper sophos-autoupdate

USE_RC_SUBR=	mailscanner mta
SUB_LIST+=	RC_SUBR_SUFFIX=${RC_SUBR_SUFFIX}

post-extract:
	cd ${WRKSRC} && ${TAR} xvzf perl-tar/MailScanner-${PORTVERSION}-${PATCHLEVEL}.tar.gz > /dev/null && ${MV} MailScanner-${PORTVERSION}-${PATCHLEVEL}/* .

do-build:
	${PERL} -pi -e \
		's,/opt/MailScanner/lib,${PREFIX}/lib/MailScanner,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g;' \
		${WRKSRC}/bin/MailScanner
	${PERL} -pi -e \
		's,/opt/MailScanner/lib,${PREFIX}/libexec/MailScanner,g;' \
		${WRKSRC}/bin/mailscanner_create_locks
	${PERL} -pi -e \
		's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g; \
		s,/usr/lib/sendmail,/usr/sbin/sendmail,g; \
		s,/opt/MailScanner/bin,${PREFIX}/bin,g; \
		s,/opt/MailScanner/etc/reports,${DATADIR}/reports,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g; \
		s,/opt/MailScanner/lib,${PREFIX}/lib/MailScanner,g; \
		s,/usr/bin/unrar,${LOCALBASE}/bin/unrar,g; \
		s,/bin/gunzip,/usr/bin/gunzip,g; \
		s,/etc/mail/spamassassin,${LOCALBASE}/etc/mail/spamassassin,g; \
		s,/tmp/clamd.socket,/var/run/clamav/clamd.sock,g; \
		s,/usr/local/share/clamav,/var/db/clamav,g;' \
		${WRKSRC}/etc/MailScanner.conf
	${PERL} -pi -e \
		's,/opt/MailScanner/lib,${PREFIX}/libexec/MailScanner,g; \
		s,/bin/false,/usr/bin/false,;' ${WRKSRC}/etc/virus.scanners.conf
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g;' \
		${WRKSRC}/bin/update_virus_scanners
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g; \
		s,%%RC_SUBR%%,${RC_SUBR},g;' \
		${WRKSRC}/bin/cron/update_virus_scanners.cron
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g;' \
		${WRKSRC}/bin/update_bad_phishing_emails
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g;' \
		${WRKSRC}/bin/update_phishing_sites
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g;' \
		${WRKSRC}/bin/update_bad_phishing_sites
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g; \
		s,%%RC_SUBR%%,${RC_SUBR},g;' \
		${WRKSRC}/bin/cron/update_phishing_sites.cron
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g; \
		s,%%RC_SUBR%%,${RC_SUBR},g;' \
		${WRKSRC}/bin/cron/update_bad_phishing_sites.cron
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g; \
		s,%%RC_SUBR%%,${RC_SUBR},g;' \
		${WRKSRC}/bin/cron/update_spamassassin.cron
	${PERL} -pi -e \
		's,/bin/bash,${LOCALBASE}/bin/bash,g; \
		s,/etc/init.d/MailScanner,${LOCALBASE}/etc/rc.d/mailscanner,g; \
		s,/etc/mail/,${LOCALBASE}/etc/mail/,g; \
		s,/usr/bin/sa-compile,${LOCALBASE}/bin/sa-compile,g; \
		s,/usr/bin/sa-update,${LOCALBASE}/bin/sa-update,g;' \
		${WRKSRC}/bin/update_spamassassin
	${PERL} -pi -e \
		's,/etc/MailScanner/MailScanner.conf,${PREFIX}/etc/MailScanner/MailScanner.conf,g;' \
		${WRKSRC}/bin/clean.SA.cache
	${PERL} -pi -e \
		's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g; \
		s,/usr/lib/sendmail,/usr/sbin/sendmail,g; \
		s,/opt/MailScanner/bin,${PREFIX}/bin,g; \
		s,/opt/MailScanner/etc/reports,${DATADIR}/reports,g; \
		s,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g;' \
		${WRKSRC}/lib/MailScanner/ConfigDefs.pl
	${PERL} -pi -e \
		's,/bin/sed,/usr/bin/sed,g;' ${WRKSRC}/lib/MailScanner/SystemDefs.pm
	${PERL} -pi -e \
		's,/usr/bin/clamscan,${LOCALBASE}/bin/clamscan,g;' \
		${WRKSRC}/lib/clamav-wrapper
	${PERL} -pi -e \
		's,/usr/bin/wget,${LOCALBASE}/bin/wget,g;' \
		${WRKSRC}/lib/sophos-autoupdate
	${PERL} -pi -e \
		's,/usr/bin/unzip,${LOCALBASE}/bin/unzip,g;' \
		${WRKSRC}/lib/sophos-autoupdate
.for FILE in ${USRLOCAL_FILES_LIB}
	${PERL} -pi -e \
		's,/usr/local,${LOCALBASE},g;' \
		${WRKSRC}/lib/${FILE}
.endfor

do-install:
	#
	# Step 1: Install bin files
	#
	${INSTALL_SCRIPT} ${WRKSRC}/bin/MailScanner ${PREFIX}/sbin/mailscanner
	${LN} -s ${LOCALBASE}/sbin/mailscanner ${PREFIX}/sbin/MailScanner
	#
	# Step 2: Install libexec files
	#
	${MKDIR} ${PREFIX}/libexec/MailScanner
	${CHMOD} -R ${BINMODE} ${PREFIX}/libexec/MailScanner
	cd ${WRKSRC}/lib && ${FIND} * -name "*-wrapper" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/libexec/MailScanner/{}.sample \;
	cd ${WRKSRC}/lib && ${FIND} * -name "*-autoupdate" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/libexec/MailScanner/{}.sample \;
	${INSTALL_SCRIPT} ${WRKSRC}/bin/analyse_SpamAssassin_cache \
		${PREFIX}/libexec/MailScanner/analyse_SpamAssassin_cache
	${INSTALL_SCRIPT} ${WRKSRC}/bin/clean.SA.cache \
		${PREFIX}/libexec/MailScanner/clean.SA.cache
	${INSTALL_SCRIPT} ${WRKSRC}/bin/clean.quarantine \
		${PREFIX}/libexec/MailScanner/clean.quarantine
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mailscanner_create_locks \
		${PREFIX}/libexec/MailScanner/mailscanner_create_locks
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_bad_phishing_emails \
		${PREFIX}/libexec/MailScanner/update_bad_phishing_emails
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_phishing_sites \
		${PREFIX}/libexec/MailScanner/update_phishing_sites
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_bad_phishing_sites \
		${PREFIX}/libexec/MailScanner/update_bad_phishing_sites
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cron/update_phishing_sites.cron \
		${PREFIX}/libexec/MailScanner/update_phishing_sites.cron
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cron/update_bad_phishing_sites.cron \
		${PREFIX}/libexec/MailScanner/update_bad_phishing_sites.cron
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_virus_scanners \
		${PREFIX}/libexec/MailScanner/update_virus_scanners
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cron/update_virus_scanners.cron \
		${PREFIX}/libexec/MailScanner/update_virus_scanners.cron
	${INSTALL_SCRIPT} ${WRKSRC}/bin/update_spamassassin \
		${PREFIX}/libexec/MailScanner/update_spamassassin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cron/update_spamassassin.cron \
		${PREFIX}/libexec/MailScanner/update_spamassassin.cron
	#
	# Step 3: Install etc files
	#
	${MKDIR} ${PREFIX}/etc/MailScanner
	${CHMOD} ${BINMODE} ${PREFIX}/etc/MailScanner
.for FILE in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${PREFIX}/etc/MailScanner/${FILE}.sample
.endfor
	${MKDIR} ${PREFIX}/etc/MailScanner/rules
	cd ${WRKSRC}/etc/rules && \
		${INSTALL_DATA} EXAMPLES README ${PREFIX}/etc/MailScanner/rules
	${INSTALL_DATA} ${WRKSRC}/etc/rules/spam.whitelist.rules \
		${PREFIX}/etc/MailScanner/rules/spam.whitelist.rules.sample
	${INSTALL_DATA} ${WRKSRC}/etc/rules/bounce.rules \
		${PREFIX}/etc/MailScanner/rules/bounce.rules.sample
	${INSTALL_DATA} ${WRKSRC}/etc/rules/max.message.size.rules \
		${PREFIX}/etc/MailScanner/rules/max.message.size.rules.sample
	${MKDIR} ${PREFIX}/etc/MailScanner/mcp
	${CHMOD} ${BINMODE} ${PREFIX}/etc/MailScanner/mcp
.for FILE in ${MCP_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/mcp/${FILE} \
		${PREFIX}/etc/MailScanner/mcp/${FILE}.sample
.endfor
	#
	# Step 4: Install files in share
	#
	@${MKDIR} ${DATADIR}
	cd ${WRKSRC}/etc && ${FIND} reports -type d ! -name "*.old" -exec \
		${MKDIR} ${DATADIR}/{} \;
	# cd ${WRKSRC}/etc && ${FIND} reports -type f ! \( -name "*.orig" -exec ...
	cd ${WRKSRC}/etc && ${FIND} reports \( -type d -name "*.old" -prune \) \
		-o \( -type f ! \( -name "*.orig" -o -name "*.bak" \) \
		-exec ${INSTALL_DATA} {} ${DATADIR}/{}.sample \; \)
	${CHMOD} -R ${BINMODE} ${DATADIR}/reports
	#
	# Step 5: Install lib
	#
	${MKDIR} ${PREFIX}/lib/MailScanner/MailScanner
	${MKDIR} ${PREFIX}/lib/MailScanner/MailScanner/CustomFunctions
	${INSTALL_SCRIPT} ${WRKSRC}/lib/MailScanner.pm \
		${PREFIX}/lib/MailScanner/MailScanner.pm
	cd ${WRKSRC}/lib/MailScanner && ${FIND} * -type f ! -name "*.orig" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/lib/MailScanner/MailScanner/{} \;
	#
	# Step 6: Docs & Manpages
	#
	# Manpage
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD.port ${DOCSDIR}
	# Sophos install script
	${INSTALL_SCRIPT} ${FILESDIR}/Sophos.install.freebsd ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
	cd ${FILESDIR} && ${INSTALL_DATA} CHANGES.port ${DOCSDIR}
.endif
	cd ${FILESDIR} && \
		${INSTALL_MAN} ${MAN8} ${MAN5PREFIX}/man/man8
	${PERL} -pi -e \
		's,%%LOCALBASE%%,${LOCALBASE},g; \
		s,%%PREFIX%%,${PREFIX},g;' \
		${DOCSDIR}/Sophos.install.freebsd
.if exists(${PREFIX}/etc/MailScanner/MailScanner.conf)
	# Upgrading MailScanner.conf file... Please wait
	@${PERL} ${WRKSRC}/bin/upgrade_MailScanner_conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf.sample > \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} \
		2> /dev/null
	# Diff the files. If the files do not differ, delete the new file
	@if diff -b -B -q ${PREFIX}/etc/MailScanner/MailScanner.conf \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	   then ${ECHO} "No changes in MailScanner.conf options found" ; \
		${RM} ${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION} ; \
	else \
	   ${ECHO} "Changes in MailScanner.conf found. Please look at \
		${PREFIX}/etc/MailScanner/MailScanner.conf.new.${PORTVERSION}" ; \
	fi
.endif
	# Languages.conf update
	@for LANG_DIR in ${DATADIR}/reports/*; do \
		if [ -f $${LANG_DIR}/languages.conf ]; then \
			${ECHO} -n Upgrading $${LANG_DIR}/languages.conf... Please wait...; \
			${PERL} ${WRKSRC}/bin/upgrade_languages_conf \
				$${LANG_DIR}/languages.conf \
				$${LANG_DIR}/languages.conf.sample > \
				$${LANG_DIR}/languages.conf.new.${PORTVERSION} \
				2> /dev/null ; \
			if diff -b -B -q $${LANG_DIR}/languages.conf \
				$${LANG_DIR}/languages.conf.new.${PORTVERSION} ; \
			  then	${ECHO} " no changes"; \
				${RM} $${LANG_DIR}/languages.conf.new.${PORTVERSION} ; \
			  else	${ECHO} " done"; \
				${CP} $${LANG_DIR}/languages.conf.new.${PORTVERSION} $${LANG_DIR}/languages.conf ; \
			fi; \
		fi; \
	done
	@${CAT} ${PKGMESSAGE}

post-install:
.if defined(WITH_SPAMASSASSIN) && !defined(WITHOUT_SPAMASSASSIN_SYMLINK)
	@if [ ! -r ${PREFIX}/etc/mail/spamassassin/mailscanner.cf ]; then \
		${ECHO} ${LN} -s ${PREFIX}/etc/MailScanner/spam.assassin.prefs.conf ${PREFIX}/etc/mail/spamassassin/mailscanner.cf; \
		${LN} -s ${PREFIX}/etc/MailScanner/spam.assassin.prefs.conf ${PREFIX}/etc/mail/spamassassin/mailscanner.cf; \
	else \
		${ECHO} "File ${PREFIX}/etc/mail/spamassassin/mailscanner.cf already exists!"; \
	fi;
.endif
	# Display warning about new start/stop scripts
	@${CAT} ${FILESDIR}/rcwarning.txt
.if !defined(BATCH)
	@${ECHO} Press ENTER to continue...
	@read a
.endif

renew-wrapper: configure
	# Renew virus wrapper scripts
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*-wrapper ${PREFIX}/libexec/MailScanner

renew-autoupdate: configure
	# Renew autoupdate scripts
	${INSTALL_SCRIPT} ${WRKSRC}/lib/*-autoupdate ${PREFIX}/libexec/MailScanner

renew-reports: configure
	# Renew reports
	cd ${WRKSRC}/etc/reports/en && ${FIND} * -type f ! -name "*.orig" \
		-exec ${INSTALL_DATA} {} ${DATADIR}/reports/en/{}  \;

initial-config: renew-wrapper renew-autoupdate renew-reports
	cd ${WRKSRC}/etc && ${INSTALL_DATA} ${ETC_FILES} \
		${PREFIX}/etc/MailScanner
	${INSTALL_DATA} ${WRKSRC}/etc/rules/spam.whitelist.rules \
		${PREFIX}/etc/MailScanner/rules/spam.whitelist.rules
	${INSTALL_DATA} ${WRKSRC}/etc/rules/bounce.rules \
		${PREFIX}/etc/MailScanner/rules/bounce.rules
	${INSTALL_DATA} ${WRKSRC}/etc/rules/max.message.size.rules \
		${PREFIX}/etc/MailScanner/rules/max.message.size.rules
.for FILE in ${MCP_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/mcp/${FILE} \
		${PREFIX}/etc/MailScanner/mcp/${FILE}
.endfor
	@${ECHO} "******************************************************************************"
	@${ECHO} "The provided default configuration requires several directories to be created:"
	@${ECHO} "/var/spool/MailScanner/incoming"
	@${ECHO} "/var/spool/MailScanner/incoming/Locks"
	@${ECHO} "/var/spool/MailScanner/quarantine"
	@${ECHO} "/var/spool/mqueue"
	@${ECHO} "/var/spool/mqueue.in"
	@${ECHO} "Either create those directories or change the configuration."
	@${ECHO} "******************************************************************************"

.include <bsd.port.post.mk>
