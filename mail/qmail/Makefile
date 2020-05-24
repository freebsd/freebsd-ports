# Created by: Mario S F Ferreira <lioux@linf.unb.br>
# $FreeBSD$

PORTNAME=	${QMAIL_PORTNAME}
PORTVERSION?=	${QMAIL_VERSION}
PORTREVISION?=	5
CATEGORIES=	mail
MASTER_SITES+=	QMAIL
DISTNAME=	${PORTNAME}-${QMAIL_VERSION}
DISTFILES?=	${DISTNAME}${EXTRACT_SUFX}
EXTRACT_ONLY?=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER?=	erdgeist@erdgeist.org
COMMENT?=	Secure, reliable, efficient, simple, and fast MTA

DIST_SUBDIR=	qmail

CONFLICTS?=	qmail-ldap-[0-9]* *qmail-mysql-[0-9]* qmail-spamcontrol-[0-9]* *qmail-tls-[0-9]*
CONFLICTS+=	qmail-vida-[0-9]*

USES+=		qmail:vars fakeroot
PREFIX?=	${QMAIL_PREFIX}
PLIST_SUB+=	QMAIL_PREFIX="${PREFIX}"

MAKE_JOBS_UNSAFE=	yes

PORTSCOUT=	skipv:1.04

USERS=		alias
.for usersuffix in d l p q r s
USERS+=		qmail${usersuffix}
.endfor
GROUPS=		qmail qnofiles

# Options description for qmail and all slave ports
ALTQUEUE_DESC=			Run a QMAILQUEUE external queue
AUTOHOMEDIRMAKE_DESC=		auto-homedir-make feature
AUTOMAILDIRMAKE_DESC=		The auto-maildir-make feature
BIGBROTHER_DESC=		Use the control/bigbrother program
BIGTODO_DESC=			Bruce Guenter's BigToDo patch
BIG_CONCURRENCY_PATCH_DESC=	Use a concurrency greater than 240
BIG_TODO_PATCH_DESC=		Enable big_todo qmail patch
BIND_8_COMPAT_DESC=		Needed if compile fails building dns.c
BLOCKEXEC_PATCH_DESC=		Block many windows viruses/worms
CLEARTEXTPASSWD_DESC=		Use cleartext passwords (Dangerous!)
DASH_EXT_DESC=			Dash_ext extended mail addresses add
DATA_COMPRESS_DESC=		Smtp on the fly DATA compression
DISCBOUNCES_PATCH_DESC=		Discard double-bounces
DNS_CNAME_DESC=			Request CNAME (vs ANY for BIND 4 bug)
ENHACELOGS_DESC=		Enhace qmail-smtpd logs (spamcontrol-like)
EXTERNAL_TODO_DESC=		External high-performance todo processing
EXTTODO_PATCH_DESC=		Extern high-perform. todo processing
GRTDELAY_DESC=			Add jms1's Greet Delay feature
IGNOREVERISIGN_DESC=		Disallow dns wildchar matches on gtlds
LDAP_DEBUG_DESC=		Possibility to log and debug imap/pop
LOCALTIME_PATCH_DESC=		Emit dates in the local timezone
MAILDIRQUOTA_PATCH_DESC=	Maildir++ support
OUTGOINGIP_PATCH_DESC=		Set the IP address to send messages
PAM111421_DESC=			Smtpd allow email in case PAM failure
QEXTRA_DESC=			Enable QUEUE_EXTRA copy feature
QLDAP_CLUSTER_DESC=		Cluster support
QMAILQUEUE_PATCH_DESC=		Run a QMAILQUEUE program
QMQP_COMPRESS_DESC=		QMQP on the fly compression
QMTPC_PATCH_DESC=		Send email using qmtp protocol
QUOTATRASH_DESC=		Include the Trash in the quota
RCDLINK_DESC=			Create rc.d/qmail symlink
SENDERCHECK4_DESC=		LOOSE checks exclusively for RELAY clients
SMTPEXECCHECK_DESC=		Smtp DOS/Windows executable detection
SMTPEXTFORK_DESC=		Allow qmail-smtpd fork external progs
SMTP_AUTH_PATCH_DESC=		Provide SMTP Authentication
SPF_PATCH_DESC=			Implement SPF checker
TARPIT_PATCH_DESC=		Implement TARPIT functions
TLS_DESC=			SMTP TLS support
TLS_DEBUG_DESC=			Enable additional debug information
XF_QUITASAP_DESC=		Close SMTP session ASAP (SMTPEXTFORK)

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL)
_USE_NETQMAIL=			no
.else
_USE_NETQMAIL=			yes
.endif

.if ${_USE_NETQMAIL} == yes
QMAIL_PORTNAME=			netqmail
QMAIL_VERSION=			1.06
BARRIER_SENDMAIL_F_PATCH=	yes
BARRIER_QMAILQUEUE_PATCH=	yes
.else
# This is only used for slave ports.
QMAIL_PORTNAME=			qmail
QMAIL_VERSION=			1.03
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_MYSQL)
BARRIER_MAILDIRQUOTA_PATCH=	yes
BARRIER_SPF_PATCH=		yes
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL) || \
    defined(SLAVE_MYSQL)
BARRIER_BLOCKEXEC_PATCH=	yes
BARRIER_QMAILQUEUE_PATCH=	yes
BARRIER_SMTP_AUTH_PATCH=	yes
.endif

.if defined(SLAVE_LDAP)
BARRIER_BIG_CONCURRENCY_PATCH=	yes
BARRIER_EXTTODO_PATCH=		yes
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL)
BARRIER_QMTPC_PATCH=		yes
BARRIER_DISCBOUNCES_PATCH=	yes
BARRIER_SENDMAIL_F_PATCH=	yes
BARRIER_BIG_TODO_PATCH=		yes
BARRIER_DNS_PATCH=		yes
BARRIER_OUTGOINGIP_PATCH=	yes
.endif

.if defined(SLAVE_LDAP) || \
    defined(SLAVE_SPAMCONTROL) || \
    defined(SLAVE_TLS)
BARRIER_RFC2821_PATCH=		yes
BARRIER_TARPIT_PATCH=		yes
.endif

.if defined(SLAVE_SPAMCONTROL)
BARRIER_DNS_CNAME=		yes
.endif

PATCH_DIST_STRIP+=	-p1

.if !defined(BARRIER_DNS_PATCH)
# Patch necessary to cope with non-RFC >512 dns entries
# Since AOL has been using those, the problem has skyrocketed from minor to
# groundzero. qmail being RFC compliant need to be "fixed" to work with those
PATCH_SITES+=	http://www.ckdhr.com/ckd/:dns
PATCHFILES+=	qmail-103.patch:dns
.endif

.if !defined(BARRIER_SENDMAIL_F_PATCH)
# David Phillips noticed that sendmail's -f option sets a default
# From: header, and so should qmail's emulation.
PATCH_SITES+=	http://david.acz.org/software/:sendmail_flagf
PATCHFILES+=	sendmail-flagf.patch:sendmail_flagf
.endif

.if !defined(BARRIER_RFC2821_PATCH)
# This patch changes qmail-remote to skip over MX servers that greet with
# codes 400 to 499 and to bounce mail when any MX server that qmail tries
# greets with a code 500 to 599.
# Created by Matthias Andree
PATCH_SITES+=	http://www-dt.e-technik.uni-dortmund.de/~ma/qmail/:rfc2821
PATCHFILES+=	patch-qmail-1.03-rfc2821.diff:rfc2821
.endif

.if defined(SLAVE_LDAP)
PATCH_SITES+=	http://www.nrg4u.com/qmail/:ldap
PATCHFILES+=	qmail-ldap-1.03-${LDAP_PATCH_DATE}.patch.gz:ldap
.elif defined(SLAVE_MYSQL)
PATCH_SITES+=	http://iain.cx/unix/qmail/download/:mysql
PATCHFILES+=	netqmail-mysql-${MYSQL_PATCH_VERSION}.patch:mysql
.elif defined(SLAVE_TLS)
PATCH_SITES+=	http://inoa.net/qmail-tls/:tls
TLS_PATCH_NAME=	${QMAIL_PORTNAME}-${QMAIL_VERSION}-tls-${TLS_PATCH_DATE}.patch
PATCHFILES+=	${TLS_PATCH_NAME}:tls
.endif

PATCH_SITES+=	LOCAL/bdrewery/qmail/:dns,sendmail_flagf,rfc2821,ldap,mysql,tls,quota,blockexec,doublebounce,spf,spf_tls,localtime,qmtpc_outgoingip
PATCH_SITES+=	http://mirror.shatow.net/freebsd/qmail/:DEFAULT,dns,sendmail_flagf,rfc2821,ldap,mysql,tls,quota,blockexec,doublebounce,spf,spf_tls,localtime,qmtpc_outgoingip

OPTIONS_DEFINE+=DOCS

.if !defined(BARRIER_SMTP_AUTH_PATCH)
SMTP_AUTH_VERSION=	0.31
SMTP_AUTH_DIR=		${WRKDIR}/qmail-smtpd-auth-${SMTP_AUTH_VERSION}

OPTIONS_DEFINE+=SMTP_AUTH_PATCH
.endif
.if !defined(BARRIER_QMAILQUEUE_PATCH)
OPTIONS_DEFINE+=QMAILQUEUE_PATCH
.endif
.if !defined(BARRIER_BIG_TODO_PATCH)
OPTIONS_DEFINE+=BIG_TODO_PATCH
.endif
.if !defined(BARRIER_BIG_CONCURRENCY_PATCH)
OPTIONS_DEFINE+=BIG_CONCURRENCY_PATCH
.endif
.if !defined(BARRIER_OUTGOINGIP_PATCH)
OPTIONS_DEFINE+=OUTGOINGIP_PATCH
.endif
.if !defined(BARRIER_LOCALTIME_PATCH)
OPTIONS_DEFINE+=LOCALTIME_PATCH
.endif
.if !defined(BARRIER_QMTPC_PATCH)
OPTIONS_DEFINE+=QMTPC_PATCH
.endif
.if !defined(BARRIER_MAILDIRQUOTA_PATCH)
OPTIONS_DEFINE+=MAILDIRQUOTA_PATCH
.endif
.if !defined(BARRIER_BLOCKEXEC_PATCH)
OPTIONS_DEFINE+=BLOCKEXEC_PATCH
.endif
.if !defined(BARRIER_DISCBOUNCES_PATCH)
OPTIONS_DEFINE+=DISCBOUNCES_PATCH
.endif
.if !defined(BARRIER_SPF_PATCH)
OPTIONS_DEFINE+=SPF_PATCH
.endif
.if !defined(BARRIER_TARPIT_PATCH)
OPTIONS_DEFINE+=TARPIT_PATCH
.endif
.if !defined(BARRIER_EXTTODO_PATCH)
OPTIONS_DEFINE+=EXTTODO_PATCH
.endif

.if defined(SLAVE_TLS)
OPTIONS_DEFINE+=TLS_DEBUG
.elif defined(SLAVE_LDAP)
OPTIONS_DEFINE+=TLS ALTQUEUE BIGBROTHER BIGTODO BIND_8_COMPAT CLEARTEXTPASSWD \
		DASH_EXT DATA_COMPRESS EXTERNAL_TODO IGNOREVERISIGN \
		QLDAP_CLUSTER QMQP_COMPRESS QUOTATRASH SMTPEXECCHECK \
		AUTOMAILDIRMAKE AUTOHOMEDIRMAKE LDAP_DEBUG SMTPEXTFORK \
		XF_QUITASAP SENDERCHECK4 ENHACELOGS GRTDELAY

OPTIONS_DEFAULT+=	TLS DASH_EXT DATA_COMPRESS EXTERNAL_TODO QLDAP_CLUSTER \
			QLDAP_CLUSTER QMQP_COMPRESS SMTPEXECCHECK \
			AUTOMAILDIRMAKE AUTOHOMEDIRMAKE

LDAP_PARAMS=	ALTQUEUE BIGBROTHER BIGTODO BIND_8_COMPAT CLEARTEXTPASSWD \
		DASH_EXT DATA_COMPRESS EXTERNAL_TODO IGNOREVERISIGN \
		QLDAP_CLUSTER QMQP_COMPRESS QUOTATRASH SMTPEXECCHECK

.elif defined(SLAVE_SPAMCONTROL)
OPTIONS_DEFINE+=PAM111421 SMTPEXTFORK \
		XF_QUITASAP

OPTIONS_DEFAULT+=	PAM111421
.endif

OPTIONS_DEFINE+=QEXTRA

.if !defined(BARRIER_DNS_CNAME)
OPTIONS_DEFINE+=	DNS_CNAME
OPTIONS_DEFAULT+=	DNS_CNAME
.endif

.if !defined(SLAVE_LDAP)
OPTIONS_DEFINE+=RCDLINK
OPTIONS_DEFAULT+=	RCDLINK
.endif

OPTIONS_SUB=	yes

ALL_TARGET+=	default dot-qmail.5 qmail-control.5 qmail-getpw.8 \
		qmail-limits.7 qmail-newmrh.8 qmail-newu.8 qmail-pw2u.8 \
		qmail-send.8 qmail-start.8 qmail-users.5

MMAN1+=	forward.1 condredirect.1 bouncesaying.1 except.1 maildirmake.1 \
	maildir2mbox.1 maildirwatch.1 mailsubj.1 qreceipt.1 qbiff.1 preline.1 \
	tcp-env.1
MMAN5+=	addresses.5 envelopes.5 maildir.5 mbox.5 dot-qmail.5 qmail-control.5 \
	qmail-header.5 qmail-log.5 qmail-users.5 tcp-environ.5
MMAN7+=	forgeries.7 qmail-limits.7 qmail.7
MMAN8+=	qmail-local.8 qmail-lspawn.8 qmail-getpw.8 qmail-remote.8 \
	qmail-rspawn.8 qmail-clean.8 qmail-send.8 qmail-start.8 splogger.8 \
	qmail-queue.8 qmail-inject.8 qmail-showctl.8 qmail-newmrh.8 \
	qmail-newu.8 qmail-pw2u.8 qmail-qread.8 qmail-qstat.8 qmail-tcpok.8 \
	qmail-tcpto.8 qmail-pop3d.8 qmail-popup.8 qmail-qmqpc.8 qmail-qmqpd.8 \
	qmail-qmtpd.8 qmail-smtpd.8 qmail-command.8

.if defined(SLAVE_MYSQL)
PKGMESSAGE_SUFFIX=	mysql
.endif

.if defined(SLAVE_SPAMCONTROL)
EXTRA_MAN8=	qmail-badloadertypes.8 qmail-badmimetypes.8 qmail-mfrules.8 \
		qmail-recipients.8 qmail-smtpam.8
ALL_TARGET+=	${EXTRA_MAN8}
MMAN8+=		${EXTRA_MAN8}
USES+=		perl5 ssl
USE_PERL5=	patch build
CFLAGS+=	-include /usr/include/errno.h
CFLAGS+=	-I${OPENSSLINC} -L${OPENSSLLIB}
# Required for the insane pre-patch compiling done by this slave port
PATCH_DEPENDS+=	${BUILD_DEPENDS:M*ssl*}
.endif

.if defined(SLAVE_LDAP)
PKGMESSAGE_SUFFIX=	ldap
PLIST_SUB+=	LDAP="" NO_LDAP="@comment "
.else
PLIST_SUB+=	LDAP="@comment " NO_LDAP=""
.endif

.if defined(SLAVE_SPAMCONTROL)
PLIST_SUB+=	SPAMCONTROL=""
.else
PLIST_SUB+=	SPAMCONTROL="@comment "
.endif

.if defined(SLAVE_TLS)
PKGMESSAGE_SUFFIX=	tls
PLIST_SUB+=	TLS="" NO_TLS="@comment "
.else
PLIST_SUB+=	TLS="@comment " NO_TLS=""
.endif

.if defined(PKGMESSAGE_SUFFIX)
SLAVEPORT_LINE=	${PKGMESSAGE_SUFFIX}
.elif defined(SLAVE_SPAMCONTROL)
SLAVEPORT_LINE=	spamcontrol
.endif

SUB_FILES+=	mailer.conf.sample bootfiles.sed enable-qmail
SUB_LIST+=	ECHO_CMD=${ECHO_CMD} RCDLINK=${RCDLINK}

.if defined(PKGMESSAGE_SUFFIX)
SUB_FILES+=	pkg-message-${PKGMESSAGE_SUFFIX}
PKGMESSAGE?=	${WRKDIR}/pkg-message-${PKGMESSAGE_SUFFIX}
.else
SUB_FILES+=	pkg-message
.endif

.if !defined(SLAVE_LDAP)
SUB_FILES+=	qmailsmtpd qmailsend
.endif

WRKDIR_doc=	${WRKDIR}/doc

PORTDOCS=	*

DOCFILES_WRKSRC+=	BLURB BLURB2 BLURB3 BLURB4 INTERNALS SECURITY \
			THOUGHTS FAQ UPGRADE SENDMAIL INSTALL INSTALL.alias \
			INSTALL.ctl INSTALL.ids INSTALL.maildir INSTALL.mbox \
			INSTALL.vsm TEST.deliver TEST.receive REMOVE.sendmail \
			REMOVE.binmail PIC.local2alias PIC.local2ext \
			PIC.local2local PIC.local2rem PIC.local2virt \
			PIC.nullclient PIC.relaybad PIC.relaygood PIC.rem2local
DOCFILES_WRKDIR+=	mailer.conf.sample

.if defined(SLAVE_LDAP)
DOCFILES_WRKSRC+=	QLDAPINSTALL QLDAPNEWS POPBEFORESMTP QLDAPTODO \
			QLDAPPICTURE QLDAPGROUP EXTTODO qmail.schema
.elif defined(SLAVE_TLS)
DOCFILES_WRKDIR+=	TLS.readme
.elif defined(SLAVE_SPAMCONTROL)
DOCFILES_WRKDIR_doc+=	FILES.spamcontrol HISTORY.spamcontrol \
			INSTALL.spamcontrol LICENSE.spamcontrol \
			LOGGING.spamcontrol PROPOSAL.mav README.bigtodo \
			README.bouncemaxbytes README.clamav README.djbdns \
			README.mav \
			README.qmailqueue README.recipients \
			README.wildmat README_spamcontrol.html \
			RELEASE_22.spamcontrol RELEASE_23.spamcontrol \
			RELEASE_24.spamcontrol RELEASE_25.spamcontrol \
			RELEASE_26.spamcontrol RELEASE_27.spamcontrol \
			SMTPREPLY.spamcontrol \
			TODO.spamcontrol badloadertypes badmailfrom \
			badmimetypes badrcptto smtpreplies
SCRIPTS+=	qmail-alias2recipients qmail-pwd2recipients \
		qmail-users2recipients qmail-vpopmail2recipients
.endif

.if !defined(SLAVE_LDAP)
BOOTFILES=	home home+df proc proc+df binm1 binm1+df \
		binm2 binm2+df binm3 binm3+df maildir
.endif

CONFIGUREPROGRAMS=	dnsfq hostname dnsip ipmeprint dnsptr
CONFIGURESCRIPTS=	config config-fast

.if defined(SLAVE_LDAP)
TLS_USES=		ssl
.endif

# Port will control all PREFIX handling.
NO_MTREE=	yes
NO_PREFIX_RMDIR=yes

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" && !defined(SLAVE_LDAP) \
    && !defined(SLAVE_SPAMCONTROL)
EXTRA_PATCHES+=			${FILESDIR}/extra-patch-amd64
.endif

.include <bsd.port.pre.mk>

.if ${PREFIX} != ${LOCALBASE}
DOCSDIR=	${PREFIX}/doc
.endif

.if defined(SLAVE_LDAP)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-utmpx-ldap
.elif !defined(SLAVE_SPAMCONTROL)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-utmpx
.endif

.if defined(SLAVE_TLS)
CFLAGS+=	-I${OPENSSLBASE}/include -L${OPENSSLBASE}/lib -DTLS=${TLS_PATCH_DATE}
. if ${PORT_OPTIONS:MTLS_DEBUG}
CFLAGS+=	-DDEBUG
. endif
.endif

.if defined(SLAVE_LDAP)

. for param in ${LDAP_PARAMS}
.  if ${PORT_OPTIONS:M${param}}
LDAPFLAGS+=	-D${param}
.  endif
. endfor

.endif

.if ${PORT_OPTIONS:MSMTP_AUTH_PATCH}
MASTER_SITES+=	http://tomclegg.net/qmail/:smtp_auth \
		LOCAL/bdrewery/qmail/:smtp_auth
DISTFILES+=	qmail-smtpd-auth-${SMTP_AUTH_VERSION}.tar.gz:smtp_auth
EXTRACT_ONLY+=	qmail-smtpd-auth-${SMTP_AUTH_VERSION}.tar.gz
MASTER_SITES+=	http://tomclegg.net/qmail/:close3
DISTFILES+=	qmail-smtpd-auth-close3.patch:close3
. if defined(SLAVE_TLS)
AUTH_PATCH=	auth.patch.diff-tls-20110119
. elif ${PORT_OPTIONS:MSPF_PATCH}
AUTH_PATCH=	auth.patch.diff
. endif

. if defined(AUTH_PATCH)
DISTFILES+=	${AUTH_PATCH}:smtp_auth
. endif
.endif

.if ${PORT_OPTIONS:MMAILDIRQUOTA_PATCH}
PATCH_SITES+=	http://www.alexdupre.com/qmail/:quota
PATCHFILES+=	${PORTNAME}-maildir++.patch:quota
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-maildir++
.endif

.if ${PORT_OPTIONS:MBLOCKEXEC_PATCH}
PATCH_SITES+=	http://www.alexdupre.com/qmail/:blockexec
PATCHFILES+=	qmail-block-executables.patch:blockexec
.endif

.if ${PORT_OPTIONS:MDISCBOUNCES_PATCH}
PATCH_SITES+=	http://www.alexdupre.com/qmail/:doublebounce
PATCHFILES+=	qmail-discard-double-bounces.patch:doublebounce
.endif

.if ${PORT_OPTIONS:MSPF_PATCH}
. if defined(SLAVE_TLS) || defined(SLAVE_SPAMCONTROL)
.  if defined(SLAVE_SPAMCONTROL)
SPF_SPAMCONTROL_PATCH=	qmail-spf-rc5.patch-spamcontrol-27_2
PATCH_SITES+=		LOCAL/bdrewery/qmail/:spf_spamcontrol
PATCHFILES+=		${SPF_SPAMCONTROL_PATCH}:spf_spamcontrol
.  else
# XXX - Move change out of conflicting Makefile hunk
.    if ${PORT_OPTIONS:MSMTP_AUTH_PATCH}
SPF_TLS_PATCH=	qmail-spf-rc5.patch-auth-tls-20110119
.    else
SPF_TLS_PATCH=	qmail-spf-rc5.patch-tls-20110119
.    endif
#MASTER_SITES+=	http://manuel.mausz.at/programming/patches/qmail/:spf_tls
MASTER_SITES+=		LOCAL/bdrewery/qmail/:spf_tls
DISTFILES+=	${SPF_TLS_PATCH}:spf_tls
.  endif
. else
PATCH_SITES+=	http://www.saout.de/misc/spf/:spf
PATCHFILES+=	qmail-spf-rc5.patch:spf
. endif
.endif

.if ${PORT_OPTIONS:MEXTTODO_PATCH}
PLIST_SUB+=		EXTTODO=""
DOCFILES_WRKSRC+=	EXTTODO

. if !empty(PORT_OPTIONS:MBIG_TODO_PATCH) || !empty(PORT_OPTIONS:MBIGTODO)
MASTER_SITES+=	LOCAL/bdrewery/qmail/:ext_big_todo
EXT_BIG_TODO_PATCH=	ext_todo-20030105+big-todo.103.patch
DISTFILES+=	${EXT_BIG_TODO_PATCH}:ext_big_todo
. endif

. if ${PORT_OPTIONS:MSPF_PATCH}
.  if defined(SLAVE_TLS)
# XXX - Move qmail-todo out of conflicting Makefile hunk
EXTTODO_PATCH=	ext_todo-20030105_spf_tls.patch
MASTER_SITES+=	LOCAL/bdrewery/qmail/:exttodo
DISTFILES+=	${EXTTODO_PATCH}:exttodo
.  else
PATCH_SITES+=	LOCAL/bdrewery/qmail/:exttodo
PATCHFILES+=	ext_todo-20030105_spf.patch:exttodo
.  endif
. elif defined(SLAVE_MYSQL)
PATCH_SITES+=	LOCAL/bdrewery/qmail/:exttodo
PATCHFILES+=	ext_todo-20030105_mysql.patch:exttodo
. elif defined(SLAVE_TLS)
PATCH_SITES+=	LOCAL/bdrewery/qmail/:exttodo
PATCHFILES+=	ext_todo-20030105_tls.patch:exttodo
. else
PATCH_SITES+=	http://www.nrg4u.com/qmail/:exttodo
PATCHFILES+=	ext_todo-20030105.patch:exttodo
. endif
.else
PLIST_SUB+=	EXTTODO="@comment "
.endif

.if ${PORT_OPTIONS:MDNS_CNAME}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-dns-cname
.endif

.if !defined(BARRIER_DNS_PATCH) \
	|| !empty(PORT_OPTIONS:MQMAILQUEUE_PATCH) \
	|| !empty(PORT_OPTIONS:MBIG_TODO_PATCH) \
	|| !empty(PORT_OPTIONS:MBIG_CONCURRENCY_PATCH) \
	|| !empty(PORT_OPTIONS:MOUTGOINGIP_PATCH) \
	|| !empty(PORT_OPTIONS:MQMTPC_PATCH)
PATCH_SITES+=	QMAIL
.endif

.if ${PORT_OPTIONS:MQMAILQUEUE_PATCH}
PATCHFILES+=	qmailqueue-patch
.endif
.if ${PORT_OPTIONS:MBIG_TODO_PATCH}
PATCHFILES+=	big-todo.103.patch
.endif
.if ${PORT_OPTIONS:MBIG_CONCURRENCY_PATCH}
.  if defined(SLAVE_SPAMCONTROL)
PATCHFILES+=	big-concurrency-spamcontrol-2731.patch
.  else
PATCHFILES+=	big-concurrency.patch
.  endif
.endif
.if !empty(PORT_OPTIONS:MOUTGOINGIP_PATCH) && !empty(PORT_OPTIONS:MQMTPC_PATCH)
PATCHFILES+=	qmail-1.03-qmtpc_outgoingip_20090630.patch:qmtpc_outgoingip
.elif ${PORT_OPTIONS:MOUTGOINGIP_PATCH}
PATCHFILES+=	outgoingip.patch
.elif ${PORT_OPTIONS:MQMTPC_PATCH}
PATCHFILES+=	qmail-1.03-qmtpc.patch
.endif

.if ${PORT_OPTIONS:MLOCALTIME_PATCH}
PATCH_SITES+=	http://www.alib.jp/files/:localtime
PATCHFILES+=	qmail-date-localtime.patch:localtime
.endif

.if ${PORT_OPTIONS:MTARPIT_PATCH}
PATCH_SITES+=	http://www.palomine.net/qmail/:tarpit
PATCHFILES+=	tarpit.patch:tarpit
.endif

.if ${PORT_OPTIONS:MSMTPEXTFORK} && \
    ( defined(SLAVE_SPAMCONTROL) || defined(SLAVE_LDAP) )
. if defined(SLAVE_SPAMCONTROL)
SMTPEXTFORK_PATCH=	smtpextfork-spamcontrol-2731.patch
. else
SMTPEXTFORK_PATCH=	smtpextfork-ldap-20060201_4.patch
. endif

MASTER_SITES+=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail-smtpextfork/patches/:extfork \
		LOCAL/bdrewery/qmail/:extfork
DISTFILES+=	${SMTPEXTFORK_PATCH:S/$/:extfork/} \
		README.smtpextfork:extfork
.endif

.if defined(SLAVE_LDAP) && ${PORT_OPTIONS:MSENDERCHECK4}
PATCH_SITES+=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail/:sendercheck4 \
		LOCAL/bdrewery/qmail/:sendercheck4
PATCHFILES+=	qmail-ldap-1.03_qmail-smtpd_SENDERCHECK4.patch:sendercheck4
.endif

.if defined(SLAVE_LDAP) && ${PORT_OPTIONS:MGRTDELAY}
PATCH_SITES+=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail/:grtdelay \
		LOCAL/bdrewery/qmail/:grtdelay
PATCHFILES+=	qmail-ldap-20060201-grtdelay.patch:grtdelay
DOCFILES_WRKSRC+=	README.GREETDELAY
.endif

.if defined(SLAVE_LDAP) && ${PORT_OPTIONS:MENHACELOGS}
PATCH_SITES+=	http://www6.freebsdbrasil.com.br/~eksffa/l/dev/qmail/:ldapenhacelog \
		LOCAL/bdrewery/qmail/:ldapenhacelog
PATCHFILES+=	enhacelogging-ldap-20120221.patch:ldapenhacelog
.endif

.if defined(SLAVE_SPAMCONTROL)
MASTER_SITES+=	LOCAL/bdrewery/ucspi-ssl/:ucspi_ssl \
		http://www.fehcom.de/ipnet/ucspi-ssl/:ucspi_ssl
UCSPI_SSL_VER=	0.94
UCSPI_SSL_DIST=	ucspi-ssl-${UCSPI_SSL_VER}.tgz
DISTFILES+=	${UCSPI_SSL_DIST}:ucspi_ssl

UCSPISRC=	${WRKDIR}/host/superscript.com/net/ucspi-ssl-${UCSPI_SSL_VER}
# XXX not yet, needs more cleanup
#UCSPISRC!=	${MAKE} -C ${PORTSDIR}/sysutils/ucspi-ssl-tls -V WRKSRC
#PATCH_DEPENDS+=	${UCSPISRC}/compile/ucspissl.a:sysutils/ucspi-ssl-tls:build
.endif

# Some default values, these can be modified by make command line
.if ${PORT_OPTIONS:MBIG_CONCURRENCY_PATCH}
WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT?=	509
CFLAGS+=	-DFD_SETSIZE=`expr 2 \* ${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT} + 6`
.endif

.if ${PORT_OPTIONS:MRCDLINK} && !defined(SLAVE_LDAP)
PLIST_SUB+=	RCDLINK=""
RCDLINK=
.else
PLIST_SUB+=	RCDLINK="@comment "
RCDLINK=	\#
.endif

# Fill SEL_OPTIONS with options to write conf-spamcontrol
.if defined(SLAVE_SPAMCONTROL)

. if ${PORT_OPTIONS:MPAM111421}
SEL_OPTIONS+=	pam111421=yes
. else
SEL_OPTIONS+=	pam111421=no
. endif

.endif

pre-everything::
.if !defined(BARRIER_BIG_CONCURRENCY_PATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT=NUMBER"
	@${ECHO_MSG} "				(default NUMBER=${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT})"
	@${ECHO_MSG} "				set this to a value reasonable for"
	@${ECHO_MSG} "				your system if you use the patch"
	@${ECHO_MSG} ""
.endif

.if !defined(QMAIL_PREFIX)
	@${ECHO_MSG} "QMAIL_PREFIX=PREFIX_PATH"
	@${ECHO_MSG} "		(default PREFIX_PATH=${PREFIX})"
	@${ECHO_MSG} "		A normal qmail installation puts"
	@${ECHO_MSG} "		everything into /var/qmail/."
	@${ECHO_MSG} "		If you want to install to ${LOCALBASE},"
	@${ECHO_MSG} "		then \"${LOCALBASE}/qmail\" is suggested"
	@${ECHO_MSG} "		instead of \"${LOCALBASE}\", but both will"
	@${ECHO_MSG} "		work."
	@${ECHO_MSG} ""
.endif

post-extract:
.if defined(SLAVE_SPAMCONTROL)
	@cd ${WRKSRC} && ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${SPAMCONTROL_DIST}
	@cd ${WRKDIR} && ${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${UCSPI_SSL_DIST}
	${REINPLACE_CMD} -e "s@-lssl@-L${OPENSSLLIB} -lssl@g" \
		${UCSPISRC}/src/ssl.lib
.endif

# XXX - Move all the major patch applications to post-extract
#
# Apply main distro patch (which requires building a dependency and
# running a script) before PATCHFILES get applied.
.if defined(SLAVE_SPAMCONTROL)
pre-patch:
	@${ECHO_CMD} ${WRKDIR} > ${WRKSRC}/conf-qmail
	@${ECHO_CMD} "# Generated by qmail-spamcontrol FreeBSD port" \
		> ${WRKSRC}/conf-spamcontrol
. for option in ${SEL_OPTIONS}
	@${ECHO_CMD} ${option} >> ${WRKSRC}/conf-spamcontrol
. endfor
	@${ECHO_CMD} "${UCSPISRC}/compile" > ${WRKSRC}/conf-ucspissl
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${UCSPISRC}/src/conf-cc
	${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${UCSPISRC}/src/conf-ld
	${ECHO_CMD} "${PREFIX}" > ${UCSPISRC}/src/conf-home
	${ECHO_CMD} "${PREFIX}/bin" > ${UCSPISRC}/src/conf-tcpbin
	${ECHO_CMD} "/etc/ssl" > ${UCSPISRC}/src/conf-cadir
	${ECHO_CMD} "/etc/ssl/cert.pem" > ${UCSPISRC}/src/conf-cafile
	${ECHO_CMD} "/etc/ssl/dh1024.pem" > ${UCSPISRC}/src/conf-dhfile
	@cd ${UCSPISRC} && ${SETENV} ${MAKE_ENV} package/compile
	@cd ${WRKSRC} && ${SH} ./install_spamcontrol.sh
# Any rejected patches are a failure
	@if [ "`find ${WRKSRC} -name '*.rej' | wc -l`" -ne 0 ]; then \
		${ECHO_MSG} "===> Failed to apply spamcontrol patch"; \
		${FALSE}; \
	fi
# Fix trailing whitespace which breaks some patches
	${SED} -i '' -e 's,^\(binm3 binm3+df\) $$,\1,' ${WRKSRC}/Makefile
.endif

post-patch:
.if ${PORT_OPTIONS:MSMTP_AUTH_PATCH}
	@${CP} ${SMTP_AUTH_DIR}/base64.[ch] ${WRKSRC}
. if defined(AUTH_PATCH)
	@${PATCH} -d ${SMTP_AUTH_DIR} < ${DISTDIR}/${DIST_SUBDIR}/${AUTH_PATCH}
. endif
	@${PATCH} -d ${WRKSRC} < ${SMTP_AUTH_DIR}/auth.patch
. if defined(SLAVE_TLS) && ${PORT_OPTIONS:MSPF_PATCH} && defined(SPF_TLS_PATCH)
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${SPF_TLS_PATCH}
.  if ${PORT_OPTIONS:MEXTTODO_PATCH} && defined(EXTTODO_PATCH)
	@${PATCH} -p1 -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${EXTTODO_PATCH}
.  endif
. endif
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/qmail-smtpd-auth-close3.patch
.elif defined(SLAVE_TLS) && ${PORT_OPTIONS:MSPF_PATCH} && defined(SPF_TLS_PATCH)
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${SPF_TLS_PATCH}
. if ${PORT_OPTIONS:MEXTTODO_PATCH} && defined(EXTTODO_PATCH)
	@${PATCH} -p1 -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${EXTTODO_PATCH}
. endif
.endif
.if defined(SLAVE_MYSQL)
	@${REINPLACE_CMD} \
	  -e 's|/opt/mysql|${LOCALBASE}|' \
	  -e "s,MYSQL_LIBS=.*,MYSQL_LIBS=\`${LOCALBASE}/bin/mysql_config --libs\`," \
		${WRKSRC}/Makefile
.elif defined(SLAVE_SPAMCONTROL)
. if ${PORT_OPTIONS:MSMTPEXTFORK}
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${SMTPEXTFORK_PATCH}
.  if ${PORT_OPTIONS:MXF_QUITASAP}
	@${REINPLACE_CMD} 's!//#define XF_QUITASAP!#define XF_QUITASAP!g' \
		${WRKSRC}/qmail-smtpd.c
.  endif
. endif
	@${REINPLACE_CMD} -E "/qhpsi *= *\"unknown\"/d; s/(\*qqx *== *'D')/qhpsi \&\& \1/g" \
		${WRKSRC}/qmail-smtpd.c
.elif defined(SLAVE_TLS)
	@${HEAD} -105 ${DISTDIR}/${DIST_SUBDIR}/${TLS_PATCH_NAME} > \
		${WRKDIR}/TLS.readme
	@${REINPLACE_CMD} "s|/usr/local/ssl|${OPENSSLBASE}|" \
		${WRKSRC}/Makefile
.elif defined(SLAVE_LDAP)
	@${REINPLACE_CMD} "s|^LDAPLIBS=-L/usr/local/lib|LDAPLIBS=-L${LOCALBASE}/lib|; \
			   s|^LDAPINCLUDES=-I/usr/local/include|LDAPINCLUDES=-I${LOCALBASE}/include|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} "s|^#SHADOWLIBS=-lcrypt$$|SHADOWLIBS=-lcrypt|" \
		${WRKSRC}/Makefile
. if ${PORT_OPTIONS:MSMTPEXTFORK}
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${SMTPEXTFORK_PATCH}
#	@${PATCH} -d ${WRKSRC} < ${FILESDIR}/extra-patch-smtpextfork-qmail-smtpd.c
.  if ${PORT_OPTIONS:MXF_QUITASAP}
	@${REINPLACE_CMD} 's!//#define XF_QUITASAP!#define XF_QUITASAP!g' \
		${WRKSRC}/qmail-smtpd.c
.  endif
. endif
. if ${PORT_OPTIONS:MTLS}
	@${REINPLACE_CMD} "s|^#TLS=|TLS=|; \
			   s|^#TLSINCLUDES=-I/usr/local/include|TLSINCLUDES=-I${OPENSSLBASE}/include|; \
			   s|^#TLSLIBS=-L/usr/local/lib|TLSLIBS=-L${OPENSSLBASE}/lib|; \
			   s|^#OPENSSLBIN=/usr/local/bin/openssl|OPENSSLBIN=${OPENSSLBASE}/bin/openssl|" \
		${WRKSRC}/Makefile
. endif
. if ${PORT_OPTIONS:MDATA_COMPRESS} || ${PORT_OPTIONS:MQMQP_COMPRESS}
	@${REINPLACE_CMD} "s|^#ZLIB=-lz$$|ZLIB=-lz|" \
		${WRKSRC}/Makefile
. endif
. if ${PORT_OPTIONS:MAUTOMAILDIRMAKE}
	@${REINPLACE_CMD} "s|^#MDIRMAKE=|MDIRMAKE=|" ${WRKSRC}/Makefile
. endif
. if ${PORT_OPTIONS:MAUTOHOMEDIRMAKE}
	@${REINPLACE_CMD} "s|^#HDIRMAKE=|HDIRMAKE=|" ${WRKSRC}/Makefile
. endif
. if ${PORT_OPTIONS:MLDAP_DEBUG}
	@${REINPLACE_CMD} "s|^#DEBUG=|DEBUG=|" ${WRKSRC}/Makefile
. endif
. if defined(LDAPFLAGS)
	@${REINPLACE_CMD} "s|^#LDAPFLAGS=.*$$|LDAPFLAGS=${LDAPFLAGS}|" \
		${WRKSRC}/Makefile
. endif
.endif
.if defined(EXT_BIG_TODO_PATCH)
	@${PATCH} -d ${WRKSRC} < ${DISTDIR}/${DIST_SUBDIR}/${EXT_BIG_TODO_PATCH}
.endif
	@${REINPLACE_CMD} 's!/var/qmail!${PREFIX}!; \
			   s!/usr/local/!${LOCALBASE}/!' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's!nofiles!qnofiles!g' \
		${WRKSRC}/conf-groups
	@${REINPLACE_CMD} '/"man"/d; /man\/man/d; /man\/cat/d; \
			   /"doc"/d; /"boot","/d' \
		${WRKSRC}/hier.c
.if ${PORT_OPTIONS:MQEXTRA}
	@${REINPLACE_CMD} 's!QUEUE_EXTRA ""!QUEUE_EXTRA "Tlog\\0"!g; \
			   s!QUEUE_EXTRALEN 0!QUEUE_EXTRALEN 5!g' \
			   ${WRKSRC}/extra.h
.endif
	@${REINPLACE_CMD} -e "s/void *main/int main/g" ${WRKSRC}/*.c
	@${REINPLACE_CMD} -e "/int main/ s/argc, *argv/int argc, char **argv/" ${WRKSRC}/install.c
	@${ECHO_CMD} "MANPATH ${MANPREFIX}/man" > ${WRKDIR}/qmail.conf

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} ${PREFIX} > ${WRKSRC}/conf-qmail
.if !empty(PORT_OPTIONS:MBIG_CONCURRENCY_PATCH) \
	&& defined(WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT)
	@if [ ${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT} -gt 0 ]; then \
		${ECHO_CMD} "${WITH_BIG_CONCURRENCY_PATCH_CONCURRENCY_LIMIT}" \
			> ${WRKSRC}/conf-spawn ; \
	fi
.endif

post-build:
	@${ECHO_MSG} "===> Rebuilding DJB installer to respect STAGEDIR"
	@${MV} -f ${WRKSRC}/conf-qmail ${WRKSRC}/conf-qmail.sav
	@${ECHO_CMD} "${STAGEDIR}${PREFIX}" > ${WRKSRC}/conf-qmail
	@${MV} -f ${WRKSRC}/install ${WRKSRC}/install.nostage
	@cd ${WRKSRC} ; ${RM} install instcheck install.o instcheck.o hier.o auto_qmail.o auto_qmail.c
	@cd ${WRKSRC} ; ${DO_MAKE_BUILD} install instcheck
	@${MV} -f ${WRKSRC}/conf-qmail.sav ${WRKSRC}/conf-qmail

do-install:
.for i in ${BOOTFILES}
	@if  [ -f ${WRKSRC}/${i}.sh ] ; then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${WRKSRC}/$i.sh > ${WRKDIR}/${i} ; \
	elif [ -f ${FILESDIR}/${i} ] ; then \
		${SED} -f ${WRKDIR}/bootfiles.sed ${FILESDIR}/$i > ${WRKDIR}/${i} ; \
	fi
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/configure
	@cd ${WRKSRC} ; ${FAKEROOT} ./install
.for f in ${CONFIGUREPROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/configure
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/install.nostage ${STAGEDIR}${PREFIX}/configure/install
.for f in ${CONFIGURESCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/configure
.endfor
.for i in ${BOOTFILES}
	${INSTALL_SCRIPT} ${WRKDIR}/${i:T} ${STAGEDIR}${PREFIX}/boot
.endfor
.if !defined(SLAVE_LDAP)
	${INSTALL_SCRIPT} ${WRKDIR}/qmailsmtpd ${STAGEDIR}${PREFIX}/boot
	${INSTALL_SCRIPT} ${WRKDIR}/qmailsend ${STAGEDIR}${PREFIX}/boot
.endif
.for i in 1 5 7 8
	@${MKDIR} ${STAGEDIR}${PREFIX}/man/man$i
. for j in ${MMAN${i}}
	${INSTALL_MAN} ${WRKSRC}/$j ${STAGEDIR}${PREFIX}/man/man${i}
. endfor
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for sub in WRKSRC WRKDIR WRKDIR_doc
.  for doc in ${DOCFILES_${sub}}
	${INSTALL_DATA} ${${sub}}/${doc} ${STAGEDIR}${DOCSDIR}
.  endfor
. endfor
. if ${PORT_OPTIONS:MSMTPEXTFORK} && ( defined(SLAVE_SPAMCONTROL) || defined(SLAVE_LDAP) )
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/README.smtpextfork ${STAGEDIR}${DOCSDIR}
. endif
. if defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "FreeBSD Binary package qmail installation" \
		> ${STAGEDIR}${DOCSDIR}/SYSDEPS
. else
	@cd ${WRKSRC} && ${CAT} `${CAT} SYSDEPS` \
		> ${STAGEDIR}${DOCSDIR}/SYSDEPS
. endif
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/scripts
	${INSTALL_SCRIPT} ${FILESDIR}/mkaliasdir ${STAGEDIR}${PREFIX}/scripts
	${INSTALL_SCRIPT} ${WRKDIR}/enable-qmail ${STAGEDIR}${PREFIX}/scripts
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKDIR}/scripts/${script} ${STAGEDIR}${PREFIX}/scripts
.endfor
#	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if defined(SLAVEPORT_LINE)
	@${ECHO_CMD} "============================================="
	@${ECHO_CMD}
	@${ECHO_CMD} "ATTENTION"
	@${ECHO_CMD}
	@${ECHO_CMD} "Add the following line to your /etc/make.conf"
	@${ECHO_CMD} "QMAIL_SLAVEPORT=${SLAVEPORT_LINE}"
	@${ECHO_CMD}
	@${ECHO_CMD} "============================================="
	@${ECHO_CMD}
.endif

post-install:
.if defined(SLAVE_LDAP)
.for file in qmail-imapd qmail-pop3d qmail-qmqpd qmail-smtpd
	@${MV} ${STAGEDIR}${PREFIX}/control/${file}.rules \
	    ${STAGEDIR}${PREFIX}/control/${file}.rules.sample
.endfor
	@${MV} ${STAGEDIR}${PREFIX}/control/signatures \
	    ${STAGEDIR}${PREFIX}/control/signatures.sample
	@${FIND} ${WRKDIR} -type f -name run -exec ${SED} -i "" \
	    -e 's|${STAGEDIR}|${PREFIX}|' {} +
.else
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/rc.d
.endif
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/man.d
	${INSTALL_DATA} ${WRKDIR}/qmail.conf ${STAGEDIR}${LOCALBASE}/etc/man.d/qmail.conf
	@${ECHO_CMD} "===> Fixing plist for ${PREFIX} ownership"
	@{ \
	  ${ECHO_CMD} "@owner root"; \
	  ${ECHO_CMD} "@group qmail"; \
	  ${ECHO_CMD} "@exec install -d -o root -g qmail ${PREFIX}"; \
	  ${ECHO_CMD} "@unexec rmdir ${QMAIL_PREFIX} 2>/dev/null || :"; \
	} >> ${TMPPLIST}
# Stop check-orphans finding the queue dir
	${RM} -r ${STAGEDIR}${PREFIX}/queue/

certificate:
.if defined(SLAVE_TLS) || defined(SLAVE_LDAP)
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		if [ ! -d ${WRKDIR} ]; then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -x509 -nodes \
			-out ${WRKDIR}/servercert.pem -days 366 \
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
		${OPENSSLBASE}/bin/openssl ciphers > ${QMAIL_PREFIX}/control/tlsclientciphers ; \
		${OPENSSLBASE}/bin/openssl ciphers > ${QMAIL_PREFIX}/control/tlsserverciphers ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi
.endif

certificate-req:
.if defined(SLAVE_TLS) || defined(SLAVE_LDAP)
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; then \
		if [ ! -d ${WRKDIR} ]; then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -nodes \
			-out ${WRKDIR}/req.pem \
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
		${ECHO_MSG} ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
		${ECHO_MSG} "===> Send ${WRKDIR}/req.pem to your CA to obtain signed_req.pem, and do:" ; \
		${ECHO_MSG} "===> cat signed_req.pem >> ${PREFIX}/control/servercert.pem" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi
.endif

.include <bsd.port.post.mk>
