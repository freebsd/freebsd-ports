# New ports collection makefile for:	qmail-spamcontrol
# Date created:		2005-02-01
# Whom:			Renato Botelho <renato@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SPAMCONTROL_VERSION}
CATEGORIES=	mail
MASTER_SITES+=	http://www.fehcom.de/qmail/spamcontrol/:spamcontrol
PKGNAMESUFFIX=	-spamcontrol
DISTFILES=	${QMAIL_DIST} ${SPAMCONTROL_DIST}:spamcontrol
EXTRACT_ONLY=	${QMAIL_DIST}

MAINTAINER=	renato@galle.com.br
COMMENT=	Qmail MTA with SpamControl patches

# Distfiles
QMAIL_DIST=		${PORTNAME}-${QMAIL_VERSION}${EXTRACT_SUFX}
SPAMCONTROL_DIST=	spamcontrol-${SPAMCONTROL_VERSION}_tgz.bin
SPAMCONTROL_VERSION=	2312
PREFIX?=		${QMAIL_PORT_PREFIX}

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

# Using default from master port, i.e., /var/qmail
QMAIL_PORT=	${PORTSDIR}/mail/qmail
QMAIL_PORT_PREFIX!=	cd ${QMAIL_PORT} && ${MAKE} -V PREFIX
MASTERDIR=	${QMAIL_PORT}

# Block some patches because SpamControl contain the same patches inside
MAIN_QMAIL_PORT_BUILD_WITH_OPTIONS_ADVERTISE_BARRIER=	yes
MAIN_QMAIL_PORT_DNS_PATCH_BARRIER=			yes
MAIN_QMAIL_PORT_SENDMAIL_F_PATCH_BARRIER=		yes
MAIN_QMAIL_PORT_WITH_BIG_CONCURRENCY_PATCH_BARRIER=	yes
MAIN_QMAIL_PORT_WITH_BIG_TODO_PATCH_BARRIER=		yes
MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER=		yes
MAIN_QMAIL_PORT_WITH_QMAILQUEUE_PATCH_BARRIER=		yes

ALL_TARGET+=	${EXTRA_MAN8}

# Local overrides
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
MD5_FILE=	${.CURDIR}/distinfo

EXTRA_MAN8=	qmail-badloadertypes.8 qmail-badmimetypes.8 qmail-recipients.8
MAN8+=		${EXTRA_MAN8}
DOCFILES+=	${WRKSRC}/FILES.spamcontrol ${WRKSRC}/HISTORY.spamcontrol \
		${WRKSRC}/INSTALL.spamcontrol ${WRKSRC}/LICENSE.spamcontrol \
		${WRKSRC}/LOGGING.spamcontrol ${WRKSRC}/Makefile.djbdns \
		${WRKSRC}/README.auth ${WRKSRC}/README.bigtodo \
		${WRKSRC}/README.bouncemaxbytes ${WRKSRC}/README.djbdns \
		${WRKSRC}/README.doublebouncetrim ${WRKSRC}/README.moreipme \
		${WRKSRC}/README.qmailqueue ${WRKSRC}/README.recipients \
		${WRKSRC}/README.spamcontrol ${WRKSRC}/README.wildmat \
		${WRKSRC}/README_spamcontrol.html \
		${WRKSRC}/RELEASE_22.spamcontrol \
		${WRKSRC}/RELEASE_23.spamcontrol \
		${WRKSRC}/SMTPREPLY.spamcontrol ${WRKSRC}/TESTING.spamcontrol \
		${WRKSRC}/TODO.spamcontrol ${WRKSRC}/badloadertypes \
		${WRKSRC}/badmailfrom ${WRKSRC}/badmimetypes \
		${WRKSRC}/badrcptto ${WRKSRC}/conf-spamcontrol \
		${WRKSRC}/install_spamcontrol.sh ${WRKSRC}/tarpitcount
SCRIPTS=	qmail-alias2recipients qmail-pwd2recipients \
		qmail-users2recipients qmail-vpopmail2recipients

# Fill SELECTED_OPTIONS with options to write conf-spamcontrol
.if defined(WITH_RELAYMAILFROM)
SELECTED_OPTIONS+=	relaymailfrom=yes
.else
SELECTED_OPTIONS+=	relaymailfrom=no
.endif

.if defined(WITH_QUITASAP)
SELECTED_OPTIONS+=	quitasap=yes
.else
SELECTED_OPTIONS+=	quitasap=no
.endif

.if !defined(WITHOUT_REQBRACKETS)
SELECTED_OPTIONS+=	reqbrackets=yes
.else
SELECTED_OPTIONS+=	reqbrackets=no
.endif

.if !defined(WITHOUT_VERP)
SELECTED_OPTIONS+=	verp=yes
.else
SELECTED_OPTIONS+=	verp=no
.endif

.if defined(WITH_RECIPIENTS550)
SELECTED_OPTIONS+=	recipients550=yes
.else
SELECTED_OPTIONS+=	recipients550=no
.endif

.if defined(WITH_LOCALMFREQAUTH)
SELECTED_OPTIONS+=	localmfreqauth=yes
.else
SELECTED_OPTIONS+=	localmfreqauth=no
.endif

.if defined(WITH_AUTHCRAM)
SELECTED_OPTIONS+=	authcram=yes
.else
SELECTED_OPTIONS+=	authcram=no
.endif

.if defined(WITH_MOREIPME)
SELECTED_OPTIONS+=	moreipme=yes
.else
SELECTED_OPTIONS+=	moreipme=no
.endif

.if defined(WITH_BIGTODO)
SELECTED_OPTIONS+=	bigtodo=yes
.else
SELECTED_OPTIONS+=	bigtodo=no
.endif

slaveport-pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_RELAYMAILFROM	Permit to open relay based"
	@${ECHO_MSG} "			on mailfrom (may be dangerous)"
	@${ECHO_MSG} "WITH_QUITASAP		Close SMTP session in case of a"
	@${ECHO_MSG} "			filter condition (violates SMTP RFC)"
	@${ECHO_MSG} "WITHOUT_REQBRACKETS	Disable function that requires"
	@${ECHO_MSG} "			brackets in <addresses>"
	@${ECHO_MSG} "WITHOUT_VERP		Disable VERP addresses for recipients"
	@${ECHO_MSG} "WITH_RECIPIENTS550	In case of non existing"
	@${ECHO_MSG} "			recipients get a direct 550 reply"
	@${ECHO_MSG} "			instead of a deferred bounce (via 450)"
	@${ECHO_MSG} "WITH_LOCALMFREQAUTH	Require authentication when"
	@${ECHO_MSG} "			mailfrom is @ your local-domains"
	@${ECHO_MSG} "WITH_AUTHCRAM		Aditional CRAM-MD5 support; needs"
	@${ECHO_MSG} "			a CRAM-MD5 supporting PAM (ie. cmd5chkpw)"
	@${ECHO_MSG} "WITH_MOREIPME		Scott Gifford's additional control"
	@${ECHO_MSG} "			files moreipme and notipme"
	@${ECHO_MSG} "WITH_BIGTODO		Bruce Guenter's BigToDo patch	consider"
	@${ECHO_MSG} "			raising conf-split in the first place"
	@${ECHO_MSG} ""

post-extract:
	@cd ${WRKSRC} && ${TAR} -xzf ${DISTDIR}/${SPAMCONTROL_DIST}

slaveport-post-patch:
	cd ${WRKSRC} && ${PATCH} < ${.CURDIR}/files/patch-qmail-smtpd.c.patch

post-configure:
	@${ECHO_CMD} "# Generated by qmail-spamcontrol FreeBSD port" \
		> ${WRKSRC}/conf-spamcontrol
.for option in ${SELECTED_OPTIONS}
	@${ECHO_CMD} ${option} >> ${WRKSRC}/conf-spamcontrol
.endfor
	@${MKDIR} ${PREFIX}/scripts
	@cd ${WRKSRC} && ./install_spamcontrol.sh

post-install:
.for script in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${script} ${PREFIX}/scripts
.endfor

.include "${MASTERDIR}/Makefile"
