# Created by: Jan-Peter Koopmann <j.koopmann@seceidos.de>
# $FreeBSD$

PORTNAME=	MailScanner
PORTVERSION=	5.0.3
CATEGORIES=	mail
MASTER_SITES=	https://s3.amazonaws.com/msv5/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PATCHLEVEL}.nix

MAINTAINER=	kkobb@skylinecorp.com
COMMENT=	Powerful virus/spam scanning framework for mail gateways

LICENSE=	GPLv2

IGNORE=		wipes out configuration on deinstall-- do not uninstall if you have it without backing up your ${ETCDIR}

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
	p5-Sys-SigAction>=0:devel/p5-Sys-SigAction \
	p5-Inline>=0:devel/p5-Inline \
	p5-Inline-C>=0:devel/p5-Inline-C \
	p5-Mail-IMAPClient>=0:mail/p5-Mail-IMAPClient \
	p5-Mail-SPF>=0:mail/p5-Mail-SPF \
	p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite \
	p5-Net-DNS-Resolver-Programmable>=0:dns/p5-Net-DNS-Resolver-Programmable \
	p5-Net-IP>=0:net-mgmt/p5-Net-IP \
	p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent \
	p5-Test-Manifest>=0:devel/p5-Test-Manifest \
	p5-URI>=0:net/p5-URI \
	p5-IO-String>=0:devel/p5-IO-String \
	p5-Business-ISBN>=0:misc/p5-Business-ISBN \
	p5-Business-ISBN-Data>=0:misc/p5-Business-ISBN-Data \
	p5-Data-Dump>=0:devel/p5-Data-Dump \
	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
	p5-File-ShareDir>=0:devel/p5-File-ShareDir \
	p5-IP-Country>=0:net/p5-IP-Country \
	curl:ftp/curl

RUN_DEPENDS:=	${BUILD_DEPENDS} \
		bash:shells/bash \
		tnef:converters/tnef \
		wget:ftp/wget

CONFLICTS=	${PORTNAME}-devel-[0-9]*

PATCHLEVEL=	7

USES=		perl5 shebangfix
SHEBANG_FILES=	usr/sbin/${PORTNAME} usr/sbin/ms-create-locks \
		usr/sbin/ms-peek usr/sbin/ms-perl-check \
		usr/sbin/ms-sa-cache usr/sbin/ms-update-bad-emails \
		usr/sbin/ms-upgrade-conf \
		usr/lib/${PORTNAME}/wrapper/bitdefender-autoupdate \
		usr/lib/${PORTNAME}/wrapper/clamav-autoupdate \
		usr/lib/${PORTNAME}/wrapper/generic-autoupdate \
		usr/lib/${PORTNAME}/wrapper/sophos-autoupdate

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	${PORTNAME}.8 pkg-message pkg-install
SUB_LIST=	DATADIR=${DATADIR} \
		PERL=${PERL} \
		PKGVERSION=${PKGVERSION} \
		PORTVERSION=${PORTVERSION} \
		ETC_FILES="${ETC_FILES}" \
		MCP_FILES="${MCP_FILES}"

OPTIONS_DEFINE=		SPAMASSASSIN CLAMAV CLAMAVMODULE BDC
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
ETC_FILES=	${PORTNAME}.conf filename.rules.conf \
		archives.filename.rules.conf archives.filetype.rules.conf \
		filetype.rules.conf spam.assassin.prefs.conf \
		spam.lists.conf virus.scanners.conf \
		phishing.safe.sites.conf \
		phishing.bad.sites.conf \
		country.domains.conf
MCP_FILES=	mcp.spam.assassin.prefs.conf \
		10_example.cf v320.pre
USRLOCAL_FILES_LIB=	\
		bitdefender-autoupdate f-secure-autoupdate \
		f-secure-wrapper sophos-autoupdate

USE_RC_SUBR=	mailscanner mta

post-patch:
	${REINPLACE_CMD} -e 's,\$$(mktemp),$$(mktemp -t tmp),' \
		${WRKSRC}/usr/lib/${PORTNAME}/wrapper/clamav-wrapper \
		${WRKSRC}/usr/lib/${PORTNAME}/wrapper/bitdefender-wrapper

do-build:
	@${REINPLACE_CMD} \
		-e 's,/bin/bash,${LOCALBASE}/bin/bash,g' \
		-e 's,/bin/sed,/usr/bin/sed,g' \
		-e 's,/etc/${PORTNAME}/${PORTNAME}.conf,${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf,g' \
		-e 's,/etc/init.d/${PORTNAME},${LOCALBASE}/etc/rc.d/mailscanner,g' \
		-e 's,/etc/mail/,${LOCALBASE}/etc/mail/,g'		\
		-e 's,/opt/${PORTNAME}/bin,${PREFIX}/libexec/${PORTNAME},g' \
		-e 's,/opt/${PORTNAME}/etc/reports,${DATADIR}/reports,g' \
		-e 's,/opt/${PORTNAME}/etc,${PREFIX}/etc/${PORTNAME},g'	\
		-e 's,/opt/${PORTNAME}/lib,${PREFIX}/lib/${PORTNAME},g'	\
		-e 's,/opt/${PORTNAME}/var/${PORTNAME}.pid,/var/run/${PORTNAME}.pid,g' \
		-e 's,/usr/bin/clamscan,${LOCALBASE}/bin/clamscan,g'	\
		-e 's,/usr/bin/sa-compile,${LOCALBASE}/bin/sa-compile,g' \
		-e 's,/usr/bin/sa-update,${LOCALBASE}/bin/sa-update,g'	\
		-e 's,/usr/bin/unzip,${UNZIP_CMD},g'				\
		-e 's,/usr/bin/wget,${LOCALBASE}/bin/wget,g'		\
		-e 's,/usr/lib/sendmail,/usr/sbin/sendmail,g'		\
		${WRKSRC}/usr/sbin/${PORTNAME}				\
		${WRKSRC}/usr/sbin/ms-create-locks			\
		${WRKSRC}/usr/lib/${PORTNAME}/init/ms-init		\

	@${REINPLACE_CMD} \
		-e 's,/opt/${PORTNAME}/var/${PORTNAME}.pid,/var/run/${PORTNAME}.pid,g' \
		-e 's,/usr/lib/sendmail,/usr/sbin/sendmail,g' \
		-e 's,/opt/${PORTNAME}/bin,${PREFIX}/bin,g' \
		-e 's,/opt/${PORTNAME}/etc/reports,${DATADIR}/reports,g' \
		-e 's,/opt/${PORTNAME}/etc,${PREFIX}/etc/${PORTNAME},g' \
		-e 's,/opt/${PORTNAME}/lib,${PREFIX}/lib/${PORTNAME},g' \
		-e 's,/usr/bin/unrar,${LOCALBASE}/bin/unrar,g' \
		-e 's,/bin/gunzip,/usr/bin/gunzip,g' \
		-e 's,/etc/mail/spamassassin,${LOCALBASE}/etc/mail/spamassassin,g' \
		-e 's,/tmp/clamd.socket,/var/run/clamav/clamd.sock,g' \
		-e 's,/usr/local/share/clamav,/var/db/clamav,g' \
		${WRKSRC}/etc/${PORTNAME}/${PORTNAME}.conf

	@${REINPLACE_CMD} \
		-e 's,/opt/${PORTNAME}/lib,${PREFIX}/libexec/${PORTNAME},g' \
		-e 's,/bin/false,/usr/bin/false,' \
		${WRKSRC}/etc/${PORTNAME}/virus.scanners.conf

.for FILE in ${USRLOCAL_FILES_LIB}
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/usr/lib/${PORTNAME}/wrapper/${FILE}
.endfor
	@${FIND} ${WRKSRC} \( -name "*.bak" -or -name "*.orig" \) -delete

do-install:
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/etc)
	(cd ${WRKSRC}/usr/sbin && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/sbin)
	(cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share)
	cd ${WRKDIR} && \
		${INSTALL_MAN} ${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${LN} -sf ${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/man/man8/${PORTNAME:tl}.8
	@${ECHO_MSG} " [DONE]"

.include <bsd.port.mk>
