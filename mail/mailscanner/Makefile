# Created by: Jan-Peter Koopmann <j.koopmann@seceidos.de>
# $FreeBSD$

PORTNAME=	MailScanner
PORTVERSION=	4.85.2
#PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	https://s3.amazonaws.com/mailscanner/release/v4/tar/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PATCHLEVEL}

MAINTAINER=	kkobb@skylinecorp.com
COMMENT=	Powerful virus/spam scanning framework for mail gateways

LICENSE=	GPLv2

BUILD_DEPENDS=	\
	p5-IO-stringy>=0:devel/p5-IO-stringy \
	p5-DBI>=0:databases/p5-DBI \
	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
	p5-HTML-Tagset>=0:www/p5-HTML-Tagset \
	p5-HTML-Parser>=0:www/p5-HTML-Parser \
	p5-MIME-Tools>=0:mail/p5-MIME-Tools \
	p5-Convert-TNEF>=0:converters/p5-Convert-TNEF \
	p5-Convert-BinHex>=0:converters/p5-Convert-BinHex \
	p5-Net-CIDR>=0:net-mgmt/p5-Net-CIDR \
	p5-Net-Ident>=0:net/p5-Net-Ident \
	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
	p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
	p5-DBI>=0:databases/p5-DBI \
	p5-TimeDate>=0:devel/p5-TimeDate \
	p5-Filesys-Df>=0:sysutils/p5-Filesys-Df \
	p5-Sys-Hostname-Long>=0:sysutils/p5-Sys-Hostname-Long \
	p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite \
	p5-Sys-SigAction>=0:devel/p5-Sys-SigAction

RUN_DEPENDS:=	${BUILD_DEPENDS} \
		bash:shells/bash \
		tnef:converters/tnef \
		wget:ftp/wget

CONFLICTS=	MailScanner-devel-[0-9]*

PATCHLEVEL=	3

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/[^c]* bin/clean* \
		lib/[^M]* lib/${PORTNAME}/[^C]* lib/${PORTNAME}/*.p[ml] \
		lib/${PORTNAME}.pm lib/${PORTNAME}/CustomFunctions/*

WRKSRC=		${WRKDIR}/${PORTNAME}-install-${PORTVERSION}
SUB_FILES=	MailScanner.8 pkg-message pkg-install pkg-deinstall
SUB_LIST=	DATADIR=${DATADIR} \
		PERL=${PERL} \
		PKGVERSION=${PKGVERSION} \
		PORTVERSION=${PORTVERSION} \
		ETC_FILES="${ETC_FILES}" \
		MCP_FILES="${MCP_FILES}"

OPTIONS_DEFINE=		SPAMASSASSIN CLAMAV CLAMAVMODULE BDC DOCS
SPAMASSASSIN_DESC=	Install SpamAssassin
CLAMAV_DESC=		Install ClamAV
CLAMAVMODULE_DESC=	Install ClamAV Module
BDC_DESC=		Install BitDefender

OPTIONS_DEFAULT=	SPAMASSASSIN CLAMAV

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSPAMASSASSIN}
RUN_DEPENDS+=	spamassassin:mail/spamassassin
PLIST_SUB+=	SPAMASSASSIN=""
.else
PLIST_SUB+=	SPAMASSASSIN="@comment "
.endif

.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	clamscan:security/clamav
.endif

.if ${PORT_OPTIONS:MCLAMAVMODULE}
RUN_DEPENDS+=	p5-Mail-ClamAV>=0:mail/p5-Mail-ClamAV
.endif

.if ${PORT_OPTIONS:MCLAMAV} || ${PORT_OPTIONS:MCLAMAVMODULE}
RUN_DEPENDS+=	unrar:archivers/unrar \
		zoo:archivers/zoo \
		unarj:archivers/unarj \
		unace:archivers/unace \
		lha:archivers/lha
.endif

.if ${PORT_OPTIONS:MBDC}
RUN_DEPENDS+=	bdc:security/bdc
.endif

# backwards compatibility
.if defined(NO_SPAMASSASSIN_SYMLINK)
WITHOUT_SPAMASSASSIN_SYMLINK=${NO_SPAMASSASSIN_SYMLINK}
.endif

.if defined(WITHOUT_SPAMASSASSIN_SYMLINK) || ! ${PORT_OPTIONS:MSPAMASSASSIN}
PLIST_SUB+=	SPAMASSASSIN_SYMLINK="@comment "
SUB_LIST+=	WITHOUT_SPAMASSASSIN_SYMLINK=yes
.else
PLIST_SUB+=	SPAMASSASSIN_SYMLINK=""
SUB_LIST+=	WITHOUT_SPAMASSASSIN_SYMLINK=no
.endif

DOC_FILES=	README
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

post-patch:
	${REINPLACE_CMD} -e 's,\$$(mktemp),$$(mktemp -t tmp),' \
		${WRKSRC}/lib/clamav-wrapper \
		${WRKSRC}/lib/trend-autoupdate \
		${WRKSRC}/lib/bitdefender-wrapper \
		${WRKSRC}/lib/kaspersky-wrapper \
		${WRKSRC}/bin/Sophos.install

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
		-e 's,/usr/bin/unzip,${UNZIP_CMD},g'				\
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
	${INSTALL_SCRIPT} ${WRKSRC}/bin/MailScanner ${STAGEDIR}${PREFIX}/sbin/mailscanner
	${LN} -sf ${PREFIX}/sbin/mailscanner ${STAGEDIR}${PREFIX}/sbin/MailScanner
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n \
		">> Installing files in ${PREFIX}/libexec/MailScanner..."
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/MailScanner
	cd ${WRKSRC}/lib && ${FIND} * -name "*-wrapper" -exec \
		${INSTALL_SCRIPT} {} ${STAGEDIR}${PREFIX}/libexec/MailScanner/{}.sample \;
	cd ${WRKSRC}/lib && ${FIND} * -name "*-autoupdate" -exec \
		${INSTALL_SCRIPT} {} ${STAGEDIR}${PREFIX}/libexec/MailScanner/{}.sample \;
.for FILE in analyse_SpamAssassin_cache clean.SA.cache clean.quarantine \
		mailscanner_create_locks processing_messages_alert Quick.Peek \
		update_bad_phishing_emails update_phishing_sites \
		update_bad_phishing_sites cron/update_phishing_sites.cron \
		cron/update_bad_phishing_sites.cron update_virus_scanners \
		cron/update_virus_scanners.cron update_spamassassin \
		cron/update_spamassassin.cron
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${FILE} \
		${STAGEDIR}${PREFIX}/libexec/MailScanner/
.endfor
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${PREFIX}/etc/MailScanner..."
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/MailScanner
.for FILE in ${ETC_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/${FILE} \
		${STAGEDIR}${PREFIX}/etc/MailScanner/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/MailScanner/rules
	cd ${WRKSRC}/etc/rules \
		&& ${INSTALL_DATA} EXAMPLES README \
			${STAGEDIR}${PREFIX}/etc/MailScanner/rules
.for RULES in spam.whitelist.rules bounce.rules max.message.size.rules
	${INSTALL_DATA} ${WRKSRC}/etc/rules/${RULES} \
		${STAGEDIR}${PREFIX}/etc/MailScanner/rules/${RULES}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/MailScanner/mcp
.for FILE in ${MCP_FILES}
	${INSTALL_DATA} ${WRKSRC}/etc/mcp/${FILE} \
		${STAGEDIR}${PREFIX}/etc/MailScanner/mcp/${FILE}.sample
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/MailScanner/conf.d
	${INSTALL_DATA} ${WRKSRC}/etc/conf.d/README \
		${STAGEDIR}${PREFIX}/etc/MailScanner/conf.d/README
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${DATADIR}..."
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/etc && ${FIND} reports -type d ! -name "*.old" -exec \
		${MKDIR} ${STAGEDIR}${DATADIR}/{} \;
	cd ${WRKSRC}/etc \
	    && ${FIND} reports \( -type d -name "*.old" -prune \) \
	    -o \( -type f ! \( -name "*.orig" -o -name "*.bak" \) \
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{}.sample \; \)
	${INSTALL_SCRIPT} ${WRKSRC}/bin/upgrade_MailScanner_conf \
		${STAGEDIR}${DATADIR}
	${LN} -sf ${DATADIR}/upgrade_MailScanner_conf \
		${STAGEDIR}${DATADIR}/upgrade_languages_conf
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Installing files in ${PREFIX}/lib..."
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/MailScanner/MailScanner/CustomFunctions
	${INSTALL_SCRIPT} ${WRKSRC}/lib/MailScanner.pm \
		${STAGEDIR}${PREFIX}/lib/MailScanner/MailScanner.pm
	cd ${WRKSRC}/lib/MailScanner \
		&& ${FIND} * -type f ! -name "*.orig" -exec \
		${INSTALL_SCRIPT} {} ${STAGEDIR}${PREFIX}/lib/MailScanner/MailScanner/{} \;
	@${ECHO_MSG} " [DONE]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing docs and manpage..."
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.FreeBSD.port ${STAGEDIR}${DOCSDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/Sophos.install.freebsd ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOC_FILES} ${STAGEDIR}${DOCSDIR}
	@${REINPLACE_CMD} \
		-e 's,%%LOCALBASE%%,${LOCALBASE},'	\
		-e 's,%%PREFIX%%,${PREFIX},'		\
		${STAGEDIR}${DOCSDIR}/Sophos.install.freebsd
	@${RM} ${STAGEDIR}${DOCSDIR}/Sophos.install.freebsd.bak
.else
	@${ECHO_MSG} -n ">> Installing manpage..."
.endif
	cd ${WRKDIR} && \
		${INSTALL_MAN} ${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${LN} -sf ${PREFIX}/man/man8/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/man/man8/${PORTNAME:tl}.8
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
