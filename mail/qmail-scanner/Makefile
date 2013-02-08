# Created by: moeti <freebsd@simplerezo.com>
# $FreeBSD$

PORTNAME=	qmail-scanner
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Content/Anti-virus Scanner for qmail

RUN_DEPENDS+=	reformime:${PORTSDIR}/mail/maildrop \
		unzip:${PORTSDIR}/archivers/unzip \
		setuidgid:${PORTSDIR}/sysutils/daemontools
BUILD_DEPENDS+=	reformime:${PORTSDIR}/mail/maildrop \
		unzip:${PORTSDIR}/archivers/unzip \
		setuidgid:${PORTSDIR}/sysutils/daemontools \
		bash:${PORTSDIR}/shells/bash

CONFLICTS=	qmail-scanner-1.*

USE_PERL5=	yes
USE_QMAIL=	yes

SPOOLDIR?=	/var/spool/qscand
PLIST_SUB=	SPOOLDIR=${SPOOLDIR}

QMAIL_QUEUE=	${QMAIL_PREFIX}/bin/qmail-queue

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	\
		--qmaildir "${QMAIL_PREFIX}" \
		--spooldir "${SPOOLDIR}" \
		--etcdir "${SPOOLDIR}" \
		--logdir "${SPOOLDIR}" \
		--bindir "${PREFIX}/bin" \
		--qmail-queue-binary "${QMAIL_QUEUE}" \
		--mime-unpacker "reformime" \
		--no-QQ-check \
		--batch

QS_USER?=	qscand
QS_ADMIN?=	postmaster
QS_ID?=		98

DOCS=		logging_first_80_chars.eml patch_for_nod32_single_user.eml \
		reformime-test.eml spamc-nasty.eml spamc-nice.eml vpopmail-issues.eml
CONTRIB=	mrtg-qmail-scanner.cfg check_AV_daemons logrotate.qmail-scanner \
		qs2mrtg.pl qs_config.sh qscan-spam-to-users.pl rbl_scanner.txt \
		sub-avpdaemon.pl sub-sender-cache.pl test-avgd.pl test-clamd.pl \
		test-sophie.pl test-trophie.pl test_installation.sh test_password.zip \
		qmail-scanner-queue.c

OPTIONS_DEFINE=	TNEF FIX_MIME REDUNDANT NORMALIZE CWRAPPER STPATCH
OPTIONS_DEFAULT=TNEF REDUNDANT CWRAPPER STPATCH

TNEF_DESC=	Mark Simpson\'s Patch (Recommended)
FIX_MIME_DESC=	Fix broken MIME messages
REDUNDANT_DESC=	Scan attachments and body mails
NORMALIZE_DESC=	Decode encoded headers per MIME Base64
CWRAPPER_DESC=	C wrapper (no suid perl script needed)
STPATCH_DESC=	st patch from toribio.apollinare.org

SUB_FILES=	pkg-deinstall pkg-install pkg-message
SUB_LIST+=	QS_USER=${QS_USER} \
		QS_ID=${QS_ID} \
		SPOOLDIR=${SPOOLDIR}

.include <bsd.port.pre.mk>

# Options
.if ${PORT_OPTIONS:MTNEF}
BUILD_DEPENDS+=	${LOCALBASE}/bin/tnef:${PORTSDIR}/converters/tnef
RUN_DEPENDS+=	${LOCALBASE}/bin/tnef:${PORTSDIR}/converters/tnef
.endif

.if ! ${PORT_OPTIONS:MFIX_MIME}
CONFIGURE_ARGS+=	--fix-mime no
.endif

.if ! ${PORT_OPTIONS:MREDUNDANT}
CONFIGURE_ARGS+=	--redundant no
.endif

.if ! ${PORT_OPTIONS:MNORMALIZE}
CONFIGURE_ARGS+=	--normalize no
.endif

.if ${PORT_OPTIONS:MCWRAPPER}
SUB_LIST+=	CWRAPPER=yes
SUB_LIST+=	QSQ_TARGET=qmail-scanner-queue
CWRAPPER_FLG=	yes
PLIST_SUB+=	CWRAPPER=""
CONFIGURE_ARGS+=--skip-setuid-test
.else
SUB_LIST+=	CWRAPPER=no
SUB_LIST+=	QSQ_TARGET=qmail-scanner-queue.pl
CWRAPPER_FLG=	no
PLIST_SUB+=	CWRAPPER="@comment "
.endif

.if ${PORT_OPTIONS:MSTPATCH} || make (makesum)
PATCH_SITES=	http://freebsdrocks.net/files9/
PATCHFILES=	patch-configure-qms
.else
EXTRA_PATCHES=	${FILESDIR}/extra-patch-configure
.endif

.if defined(QS_USER)
CONFIGURE_ARGS+=	--qs-user "${QS_USER}"
.endif

.if defined(QS_ADMIN)
CONFIGURE_ARGS+=	--admin "${QS_ADMIN}"
.endif

.if defined(QS_DOMAIN)
CONFIGURE_ARGS+=	--domain "${QS_DOMAIN}"
.endif

.if defined(QS_ADMIN_DESC)
CONFIGURE_ARGS+=	--admin-description "${QS_ADMIN_DESC}"
.endif

.if defined(QS_SCANNERS)
CONFIGURE_ARGS+=	--scanners "${QS_SCANNERS}"
.endif

.if defined(QS_SKIP_MSGS)
CONFIGURE_ARGS+=	--skip-text-msgs "${QS_SKIP_MSGS}"
.endif

.if defined(QS_NOTIFY)
CONFIGURE_ARGS+=	--notify "${QS_NOTIFY}"
.else
CONFIGURE_ARGS+=	--notify psender,precips
.endif

.if defined(QS_LOCALDOMAINS) && !empty(QS_LOCALDOMAINS)
CONFIGURE_ARGS+=	--local-domains "${QS_LOCALDOMAINS}"
.endif

.if defined(QS_DLPMONITOR)
CONFIGURE_ARGS+=	--dlp-monitor "${QS_DLPMONITOR}"
.endif

.if defined(QS_SA_QUARANTINE)
CONFIGURE_ARGS+=	--sa-quarantine "${QS_SA_QUARANTINE}"
.endif

.if defined(QS_SA_TIMEOUT)
CONFIGURE_ARGS+=	--sa-timeout "${QS_SA_TIMEOUT}"
.endif

.if defined(QS_SA_FT)
CONFIGURE_ARGS+=	--sa-faulttolerant "${QS_SA_FT}"
.endif

.if defined(QS_SA_MAXSIZE)
CONFIGURE_ARGS+=	--sa-maxsize "${QS_SA_MAXSIZE}"
.endif

.if defined(QS_LANG)
CONFIGURE_ARGS+=	--lang "${QS_LANG}"
.endif

.if defined(QS_ARCHIVE)
CONFIGURE_ARGS+=	--archive "${QS_ARCHIVE}"
.endif

.if defined(QS_MAX_SCAN_SIZE)
CONFIGURE_ARGS+=	--max-scan-size "${QS_MAX_SCAN_SIZE}"
.endif

.if defined(QS_LOGDETAILS)
CONFIGURE_ARGS+=	--log-details "${QS_LOGDETAILS}"
.endif

.if defined(QS_LOGCRYPTO)
CONFIGURE_ARGS+=	--log-crypto "${QS_LOGCRYPTO}"
.endif

.if defined(QS_EOLCHECK)
CONFIGURE_ARGS+=	--ignore-eol-check "${QS_EOLCHECK}"
.endif

.if defined(QS_HEADERS)
CONFIGURE_ARGS+=	--add-dscr-hdrs "${QS_HEADERS}"
.endif

.if defined(QS_DEBUG)
CONFIGURE_ARGS+=	--debug "${QS_DEBUG}"
.endif

.if defined(QS_MAX_ZIP_SIZE)
CONFIGURE_ARGS+=	--max-zip-size "${QS_MAX_ZIP_SIZE}"
.endif

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "----------------------------------------"
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "QS_USER			User to run Q-S"
	@${ECHO_MSG} "			(Default: qscand)"
	@${ECHO_MSG} "QS_ADMIN		Administrator Q-S Address (just username)"
	@${ECHO_MSG} "			(Default: postmaster)"
	@${ECHO_MSG} "QS_DOMAIN		Administrator Domain (QS_ADMIN@QS_DOMAIN)"
	@${ECHO_MSG} "			(Default: hostname)"
	@${ECHO_MSG} "QS_ADMIN_DESC		Real Name of Administrator Q-S"
	@${ECHO_MSG} "			(Default: System Anti-Virus Administrator)"
	@${ECHO_MSG} "QS_SCANNERS		List of scanners installed, e.g. bitdefender,nod32"
	@${ECHO_MSG} "			(Default: auto)"
	@${ECHO_MSG} "QS_SKIP_MSGS		Q-S will skip running any anti-virus scanners on"
	@${ECHO_MSG} "			any messages it works out are text-only."
	@${ECHO_MSG} "			(Default: yes|no)"
	@${ECHO_MSG} "QS_NOTIFY		Who has to be notify of viruses/spams"
	@${ECHO_MSG} "			(Default: 'psender|precips')"
	@${ECHO_MSG} "QS_LOCALDOMAINS		Domains classified as local domains preventing alerts"
	@${ECHO_MSG} "			of externals users (and mailing-lists...)"
	@${ECHO_MSG} "QS_DLPMONITOR		Using this will cause Q-S to *not* block events that match"
	@${ECHO_MSG} "			this regex."
	@${ECHO_MSG} "QS_SA_TIMEOUT		This is the max number of seconds you will allow spamc to"
	@${ECHO_MSG} "			take on processing a mail message."
	@${ECHO_MSG} "QS_SA_FT		This can be used in addition to sa-timeout as a way of"
	@${ECHO_MSG} "			telling Qmail-Scanner to let SA 'have another go'"
	@${ECHO_MSG} "			at processing a message if it was unable to get it right"
	@${ECHO_MSG} "			the first time."
	@${ECHO_MSG} "QS_SA_MAXSIZE		This size (in bytes) sets the max size email that will be"
	@${ECHO_MSG} "			processed by SpamAssassin."
	@${ECHO_MSG} "QS_SA_QUARANTINE	If SA tags a message as having a score higher than"
	@${ECHO_MSG} "			'required_hits', then that message will be quarantined"
	@${ECHO_MSG} "			into a new maildir '/.spam/' and not delivered to end-user"
	@${ECHO_MSG} "			(Default: disabled, Options: Any positive number)"
	@${ECHO_MSG} "QS_LANG			Specify languages for Q-S mails alerts"
	@${ECHO_MSG} "			Supported languages are: af_ZA, cs_CZ, da_DK, de_DE,"
	@${ECHO_MSG} "			en_GB, en_PL, enlt_LT, enlt_LT_short, es_ES, fr_FR,"
	@${ECHO_MSG} "			it_IT, ja_JP.EUC, nl_NL, no_NO, pl_PL, pt_BR, pt_PT,"
	@${ECHO_MSG} "			sk_SK, sv_SE, tr_TR, tr_TR_ascii and tw_BIG5"
	@${ECHO_MSG} "			Default depends on your LANG variable"
	@${ECHO_MSG} "			(Default: en_GB if LANG is not set)"
	@${ECHO_MSG} "QS_ARCHIVE		If "yes", all copies of processed mail will be moved into the"
	@${ECHO_MSG} "			maildir '$SPOOLDIR/$ARCHIVEDIR/'. Any other string besides 'yes'"
	@${ECHO_MSG} "			and 'no' will be treated as a REGEX. Only mail from or to an"
	@${ECHO_MSG} "			address that contains that regex will be archived."
	@${ECHO_MSG} "			e.g. 'jhaar|harry'"
	@${ECHO_MSG} "			(Default: no, Options: yes|no|regex)"
	@${ECHO_MSG} "QS_LOGDETAILS		Whether or not to log to mailstats.csv/via syslog the attachment"
	@${ECHO_MSG} "			structure of every Email message. Logs to "syslog"  by default."
	@${ECHO_MSG} "			(Default: syslog, Options: yes|syslog|no)"
	@${ECHO_MSG} "QS_LOGCRYPTO		Simply notes in the log record if the message"
	@${ECHO_MSG} "			contained any form of digital signing or encryption"
	@${ECHO_MSG} "			(S/MIME, PGP and password protected files)"
	@${ECHO_MSG} "			(Default: no, Options: yes|no)"
	@${ECHO_MSG} "QS_MAXSCANSIZE		Email messages (raw size) larger than this number (in bytes)"
	@${ECHO_MSG} "			will skip all AV and Spam scanning checks. It's to stop Q-S"
	@${ECHO_MSG} "			scanning 300Mbyte TIFF file messages and the like."
	@${ECHO_MSG} "			(Default: 100Mbytes)"
	@${ECHO_MSG} "QS_MAXZIPSIZE		Zip that would have unpacked into more diskspace"
	@${ECHO_MSG} "			than this value will be blocked (prevent DoS)"
	@${ECHO_MSG} "			(Default: 1Gbytes)"
	@${ECHO_MSG} "QS_EOLCHECK		Making this "yes" stops Qmail-Scanner from treating '\r' or '\0'"
	@${ECHO_MSG} "			chars in the headers of MIME mail messages as being suspicious"
	@${ECHO_MSG} "			enough to quarantine mail over."
	@${ECHO_MSG} "			(Default: no, Options: yes|no)"
	@${ECHO_MSG} "QS_HEADERS		This adds the now old-fashion X-Qmail-Scanner headers to the message."
	@${ECHO_MSG} "			"all" adds the "rcpt to" headers too - this is a privacy hole."
	@${ECHO_MSG} "			(Default: no, Options: yes|no|all)"
	@${ECHO_MSG} "QS_DEBUG		Whether or not debugging is turned on. Can be also set to a number."
	@${ECHO_MSG} "			NOTE: Numbers over 100 cause Q-S to not cleanup working files"
	@${ECHO_MSG} "			(Default: yes, Options: yes|no|number)"
	@${ECHO_MSG} ""
	@${SED} -e 's,%%SPOOLDIR%%,${SPOOLDIR},g; s,%%QS_USER%%,${QS_USER},g; \
		s,%%QS_ID%%,${QS_ID},g; s,%%CWRAPPER%%,${CWRAPPER_FLG},g' \
		${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-build:
	@${REINPLACE_CMD} -E 's,^#!.*perl(.*)$$,#!${PERL}\1,' ${WRKSRC}/qmail-scanner-queue.pl
.if defined(WITH_CWRAPPER)
	# remove the -T option in the perl script:
	@${REINPLACE_CMD} -E 's,^(#!${PERL}.*)-T(.*)$$,\1\2,' ${WRKSRC}/qmail-scanner-queue.pl
	# patch the correct paths into the c wrapper:
	@${REINPLACE_CMD} -E 's|^(#define REAL_PATH ")/var/qmail/bin/qmail-scanner-queue.pl(".*)$$|\1${PREFIX}/bin/qmail-scanner-queue.pl\2|' \
		${WRKSRC}/contrib/qmail-scanner-queue.c
	# compile the c wrapper:
	@${MAKE} -C ${WRKSRC}/contrib
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/contrib
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/contrib/,} ${DOCSDIR}/contrib
	@${INSTALL_SCRIPT} ${CONTRIB:S,^,${WRKSRC}/contrib/,} ${DOCSDIR}/contrib
.endif
	@${MKDIR} ${SPOOLDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/qmail-scanner-queue.pl ${PREFIX}/bin
.if defined(WITH_CWRAPPER)
	@${INSTALL_PROGRAM} ${WRKSRC}/contrib/qmail-scanner-queue ${PREFIX}/bin
.endif
	@${INSTALL_DATA} ${WRKSRC}/quarantine-events.txt ${SPOOLDIR}/quarantine-events.txt.sample
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

test:
	@${WRKSRC}/contrib/test_installation.sh -doit

.include <bsd.port.post.mk>
