# New ports collection makefile for:	simscan
# Date created:        1 Apr 2005
# Whom:                Anton Karpov <toxa@toxahost.ru>
#
# $FreeBSD$
#

PORTNAME=	simscan
PORTVERSION=	1.1
CATEGORIES=	mail security
MASTER_SITES=	http://www.inter7.com/simscan/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	toxa@toxahost.ru
COMMENT=	Fast Content/Anti-virus Scanner for qmail Written in C

BUILD_DEPENDS=	${QMAIL_QUEUE}:${PORTSDIR}/mail/qmail

GNU_CONFIGURE=	yes

# A normal qmail installation puts everything into /var/qmail/.
# Must match your qmail installation
QMAIL_DIR?=	/var/qmail
WORKDIR?=	${QMAIL_DIR}/${PORTNAME}
QMAIL_QUEUE=	${QMAIL_DIR}/bin/qmail-queue
PLIST_SUB=	QMAIL_DIR=${QMAIL_DIR} \
		SIMSCAN_DIR=${PORTNAME}

OPTIONS=	CLAMAV "Support for ClamAV Virus Scanning" on \
		RIPMIME "Ripmime Processing (if Clamav ScanMail disabled)" on \
		SPAMD "Support for SpamAssassin Spam Filtering" off \
		USER "Turn On Per User SpamAssassin (required SPAMD)" off \
		DOMAIN "Turn On Per Domain Based Checking" off \
		ATTACH "Turn On Attachment Scanning (required CLAMAV)" off \
		DROPMSG "Drop Message in Case of Virus Found" off \
		PASSTHRU "Pass Spam Thru, Do Not Reject (required SPAMD)" off \
		HEADERS "Add a Received Line With Versions of Scanners" off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=--enable-clamavdb-path=/var/db/clamav \
		--enable-qmaildir=${QMAIL_DIR} \
	  	--enable-spamc-user=n \
		--enable-workdir=${WORKDIR}

.if defined(WITHOUT_CLAMAV)
CONFIGURE_ARGS+=-enable-clamav=n
.else
BUILD_DEPENDS+=	clamdscan:${PORTSDIR}/security/clamav
.endif

.if defined(WITHOUT_RIPMIME)
CONFIGURE_ARGS+=--disable-ripmime
.else
BUILD_DEPENDS+=	ripmime:${PORTSDIR}/mail/ripmime
.endif

.if defined(WITH_SPAMD)
BUILD_DEPENDS+=	spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin
CONFIGURE_ARGS+=--enable-spam=y
CONFIGURE_ARGS+=--enable-spamassassin-path=${LOCALBASE}/bin/spamassassin
.endif

.if defined(WITH_USER)
CONFIGURE_ARGS+=--enable-spamc-user=y
.endif

.if defined(WITH_DOMAIN)
CONFIGURE_ARGS+=--enable-per-domain=y
.endif

.if defined(WITH_ATTACH)
CONFIGURE_ARGS+=--enable-attach=y
.endif

.if defined(WITH_DROPMSG)
CONFIGURE_ARGS+=--enable-dropmsg=y
.endif

.if defined(WITH_PASSTHRU)
CONFIGURE_ARGS+=--enable-spam-passthru=y
.endif

.if defined(WITH_HEADERS)
CONFIGURE_ARGS+=--enable-received=y
CONFIGURE_ARGS+=--enable-sigtool-path=${LOCALBASE}/bin/sigtool
.endif

.if defined(SPAM_HITS)
CONFIGURE_ARGS+=--enable-spam-hits=${SPAM_HITS}
.endif

.if defined(QUARANTINE_DIR)
CONFIGURE_ARGS+=--enable-quarantinedir=${QUARANTINE_DIR}
.endif

.if defined(SPAMC_ARGS)
CONFIGURE_ARGS+=--enable-spamc-args=${SPAMC_ARGS}
.endif

.if defined(QMAIL_QUEUE)
CONFIGURE_ARGS+=--enable-qmail-queue=${QMAIL_QUEUE}
.endif

PORTDOCS=	AUTHORS ChangeLog README TODO

if ! ${TEST} -f ${QMAIL_QUEUE}; then \
	${ECHO_MSG} "Unable to found qmail-queue binary trying '${QMAIL_QUEUE}'.";  \
	${ECHO_MSG} "Please set QMAIL_DIR to your qmail installation directory !"; \
	exit 1; \
fi

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~="
	@${ECHO_MSG} "You may also use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "QMAIL_DIR		Base qmail directory. Default is /var/qmail"
	@${ECHO_MSG} "WORKDIR		Directory to unpack emails. Default is /var/qmail/simscan"
	@${ECHO_MSG} "QMAIL_QUEUE		Define full path and name of the qmail-queue program"
	@${ECHO_MSG} "			Incoming mail is passed to this program after being"
	@${ECHO_MSG} "			scanned by SimScan. Default is /var/qmail/bin/qmail-queue"
	@${ECHO_MSG} "SPAMC_ARGS		Define the arguments to pass to spamc."
	@${ECHO_MSG} "			Be sure to place quotes around the options you define"
	@${ECHO_MSG} "SPAM_HITS		Reject spam only above this hit level"
	@${ECHO_MSG} "			Default is 10.0. Useful without PASSTHRU option"
	@${ECHO_MSG} "QUARANTINE_DIR		Directory to keep spam and/or infected emails"
	@${ECHO_MSG} "			Default is disabled"
	@${ECHO_MSG} "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~="
	@${ECHO_MSG} ""

post-install:
	@${CHMOD} 04711 ${QMAIL_DIR}/bin/simscan
	@${CHOWN} simscan:simscan ${QMAIL_DIR}/bin/simscan ${QMAIL_DIR}/bin/simscanmk
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
