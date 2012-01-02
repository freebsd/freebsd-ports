# New ports collection makefile for:	MailScanner
# Date created:				17 March 2003
# Whom:					Jan-Peter Koopmann <j.koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	MailScanner
PORTVERSION=	4.83.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.mailscanner.info/files/4/tar/
DISTNAME=	${PORTNAME}-install-${PORTVERSION}-${PATCHLEVEL}

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Powerful virus/spam scanning framework for mail gateways

BUILD_DEPENDS=	\
	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
	${SITE_PERL}/${PERL_ARCH}/Bundle/DBI.pm:${PORTSDIR}/databases/p5-DBI \
	${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools \
	${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
	${SITE_PERL}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser \
	${SITE_PERL}/MIME/Parser.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/Convert/TNEF.pm:${PORTSDIR}/converters/p5-Convert-TNEF \
	${SITE_PERL}/Convert/BinHex.pm:${PORTSDIR}/converters/p5-Convert-BinHex \
	${SITE_PERL}/Net/CIDR.pm:${PORTSDIR}/net-mgmt/p5-Net-CIDR \
	${SITE_PERL}/Net/Ident.pm:${PORTSDIR}/net/p5-Net-Ident \
	${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
	${SITE_PERL}/Time/Zone.pm:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/${PERL_ARCH}/Filesys/Df.pm:${PORTSDIR}/sysutils/p5-Filesys-Df \
	${SITE_PERL}/Sys/Hostname/Long.pm:${PORTSDIR}/sysutils/p5-Sys-Hostname-Long \
	${SITE_PERL}/OLE/Storage_Lite.pm:${PORTSDIR}/devel/p5-OLE-Storage_Lite \
	${SITE_PERL}/Sys/SigAction.pm:${PORTSDIR}/devel/p5-Sys-SigAction

RUN_DEPENDS:=	${BUILD_DEPENDS} \
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
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	DATADIR=${DATADIR} \
		PERL=${PERL} \
		PKGVERSION=${PKGVERSION} \
		ETC_FILES="${ETC_FILES}" \
		MCP_FILES="${MCP_FILES}"

MAN8=		MailScanner.8
MLINKS=		MailScanner.8 mailscanner.8

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
BUILD_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

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

DOC_FILES=	INSTALL.FreeBSD README
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

post-extract:
	@cd ${WRKSRC} \
		&& ${TAR} xzf \
		   perl-tar/MailScanner-${PORTVERSION}-${PATCHLEVEL}.tar.gz \
		&& ${MV} MailScanner-${PORTVERSION}-${PATCHLEVEL}/* .

do-build:
	@${REINPLACE_CMD} \
		-e 's,/bin/bash,${LOCALBASE}/bin/bash,g' \
		-e 's,/bin/sed,/usr/bin/sed,g' \
		-e 's,/etc/MailScanner/MailScanner.conf,${PREFIX}/etc/MailScanner/MailScanner.conf,g' \
		-e 's,/etc/init.d/MailScanner,${LOCALBASE}/etc/rc.d/mailscanner,g' \
		-e 's,/etc/mail/,${LOCALBASE}/etc/mail/,g'		\
		-e 's,/opt/MailScanner/bin,${PREFIX}/libexec/MailScanner,g' \
		-e 's,/opt/MailScanner/etc/reports,${DATADIR}/reports,g' \
		-e 's,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g'	\
		-e 's,/opt/MailScanner/lib,${PREFIX}/lib/MailScanner,g'	\
		-e 's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g' \
		-e 's,/usr/bin/clamscan,${LOCALBASE}/bin/clamscan,g'	\
		-e 's,/usr/bin/sa-compile,${LOCALBASE}/bin/sa-compile,g' \
		-e 's,/usr/bin/sa-update,${LOCALBASE}/bin/sa-update,g'	\
		-e 's,/usr/bin/unzip,${LOCALBASE}/bin/unzip,g'		\
		-e 's,/usr/bin/wget,${LOCALBASE}/bin/wget,g'		\
		-e 's,/usr/lib/sendmail,/usr/sbin/sendmail,g'		\
		${WRKSRC}/bin/MailScanner				\
		${WRKSRC}/bin/mailscanner_create_locks			\
		${WRKSRC}/bin/processing_messages_alert			\
		${WRKSRC}/bin/update_virus_scanners			\
		${WRKSRC}/bin/cron/update_virus_scanners.cron		\
		${WRKSRC}/bin/update_bad_phishing_emails		\
		${WRKSRC}/bin/update_phishing_sites			\
		${WRKSRC}/bin/update_bad_phishing_sites			\
		${WRKSRC}/bin/cron/update_phishing_sites.cron		\
		${WRKSRC}/bin/cron/update_bad_phishing_sites.cron	\
		${WRKSRC}/bin/cron/update_spamassassin.cron		\
		${WRKSRC}/bin/update_spamassassin			\
		${WRKSRC}/bin/clean.SA.cache				\
		${WRKSRC}/lib/MailScanner/ConfigDefs.pl			\
		${WRKSRC}/lib/MailScanner/SystemDefs.pm			\
		${WRKSRC}/lib/clamav-wrapper				\
		${WRKSRC}/lib/sophos-autoupdate

	@${REINPLACE_CMD} \
		-e 's,/opt/MailScanner/var/MailScanner.pid,/var/run/MailScanner.pid,g' \
		-e 's,/usr/lib/sendmail,/usr/sbin/sendmail,g' \
		-e 's,/opt/MailScanner/bin,${PREFIX}/bin,g' \
		-e 's,/opt/MailScanner/etc/reports,${DATADIR}/reports,g' \
		-e 's,/opt/MailScanner/etc,${PREFIX}/etc/MailScanner,g' \
		-e 's,/opt/MailScanner/lib,${PREFIX}/lib/MailScanner,g' \
		-e 's,/usr/bin/unrar,${LOCALBASE}/bin/unrar,g' \
		-e 's,/bin/gunzip,/usr/bin/gunzip,g' \
		-e 's,/etc/mail/spamassassin,${LOCALBASE}/etc/mail/spamassassin,g' \
		-e 's,/tmp/clamd.socket,/var/run/clamav/clamd.sock,g' \
		-e 's,/usr/local/share/clamav,/var/db/clamav,g' \
		${WRKSRC}/etc/MailScanner.conf

	@${REINPLACE_CMD} \
		-e 's,/opt/MailScanner/lib,${PREFIX}/libexec/MailScanner,g' \
		-e 's,/bin/false,/usr/bin/false,' \
		${WRKSRC}/etc/virus.scanners.conf

.for FILE in ${USRLOCAL_FILES_LIB}
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/lib/${FILE}
.endfor
	@${FIND} ${WRKSRC} \( -name "*.bak" -or -name "*.orig" \) -delete

do-install:
	@${ECHO_MSG} -n ">> Installing files in ${PREFIX}/sbin..."
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/MailScanner ${PREFIX}/sbin/mailscanner
	@${LN} -s ${PREFIX}/sbin/mailscanner ${PREFIX}/sbin/MailScanner
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n \
		">> Installing files in ${PREFIX}/libexec/MailScanner..."
	@${MKDIR} -m ${BINMODE} ${PREFIX}/libexec/MailScanner
	@cd ${WRKSRC}/lib && ${FIND} * -name "*-wrapper" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/libexec/MailScanner/{}.sample \;
	@cd ${WRKSRC}/lib && ${FIND} * -name "*-autoupdate" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/libexec/MailScanner/{}.sample \;
.for FILE in analyse_SpamAssassin_cache clean.SA.cache clean.quarantine \
		mailscanner_create_locks processing_messages_alert Quick.Peek \
		update_bad_phishing_emails update_phishing_sites \
		update_bad_phishing_sites cron/update_phishing_sites.cron \
		cron/update_bad_phishing_sites.cron update_virus_scanners \
		cron/update_virus_scanners.cron update_spamassassin \
		cron/update_spamassassin.cron
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} \
		${PREFIX}/libexec/MailScanner/
.endfor
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${PREFIX}/etc/MailScanner..."
	@${MKDIR} -m ${BINMODE} ${PREFIX}/etc/MailScanner
.for FILE in ${ETC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${PREFIX}/etc/MailScanner/${FILE}.sample
.endfor
	@${MKDIR} ${PREFIX}/etc/MailScanner/rules
	@cd ${WRKSRC}/etc/rules \
		&& ${INSTALL_DATA} EXAMPLES README \
			${PREFIX}/etc/MailScanner/rules
.for RULES in spam.whitelist.rules bounce.rules max.message.size.rules
	@${INSTALL_DATA} ${WRKSRC}/etc/rules/${RULES} \
		${PREFIX}/etc/MailScanner/rules/${RULES}.sample
.endfor
	@${MKDIR} -m ${BINMODE} ${PREFIX}/etc/MailScanner/mcp
.for FILE in ${MCP_FILES}
	@${INSTALL_DATA} ${WRKSRC}/etc/mcp/${FILE} \
		${PREFIX}/etc/MailScanner/mcp/${FILE}.sample
.endfor
	@${MKDIR} ${PREFIX}/etc/MailScanner/conf.d
	@${INSTALL_DATA} ${WRKSRC}/etc/conf.d/README \
		${PREFIX}/etc/MailScanner/conf.d/README
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${DATADIR}..."
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/etc && ${FIND} reports -type d ! -name "*.old" -exec \
		${MKDIR} -m ${BINMODE} ${DATADIR}/{} \;
	@cd ${WRKSRC}/etc \
	    && ${FIND} reports \( -type d -name "*.old" -prune \) \
	    -o \( -type f ! \( -name "*.orig" -o -name "*.bak" \) \
		-exec ${INSTALL_DATA} {} ${DATADIR}/{}.sample \; \)
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/upgrade_MailScanner_conf ${DATADIR}
	@${LN} -s ${DATADIR}/upgrade_MailScanner_conf \
		${DATADIR}/upgrade_languages_conf
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${PREFIX}/lib..."
	@${MKDIR} ${PREFIX}/lib/MailScanner/MailScanner/CustomFunctions
	@${INSTALL_SCRIPT} ${WRKSRC}/lib/MailScanner.pm \
		${PREFIX}/lib/MailScanner/MailScanner.pm
	@cd ${WRKSRC}/lib/MailScanner \
		&& ${FIND} * -type f ! -name "*.orig" -exec \
		${INSTALL_SCRIPT} {} ${PREFIX}/lib/MailScanner/MailScanner/{} \;
	@${ECHO_MSG} " [DONE]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing docs and manpage..."
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${FILESDIR}/README.FreeBSD.port ${DOCSDIR}
	@${INSTALL_SCRIPT} ${FILESDIR}/Sophos.install.freebsd ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${DOCSDIR}
	@${REINPLACE_CMD} \
		-e 's,%%LOCALBASE%%,${LOCALBASE},'	\
		-e 's,%%PREFIX%%,${PREFIX},'		\
		${DOCSDIR}/Sophos.install.freebsd
	@${RM} -f ${DOCSDIR}/Sophos.install.freebsd.bak
.else
	@${ECHO_MSG} -n ">> Installing manpage..."
.endif
	@cd ${FILESDIR} && \
		${INSTALL_MAN} ${MAN8} ${MAN5PREFIX}/man/man8
	@${ECHO_MSG} " [DONE]"

post-install:
.if defined(WITH_SPAMASSASSIN) && !defined(WITHOUT_SPAMASSASSIN_SYMLINK)
	@${SETENV} PKG_PREFIX=${PREFIX} \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.else
	@${SETENV} PKG_PREFIX=${PREFIX} WITHOUT_SPAMASSASSIN_SYMLINK=yes \
	    ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
