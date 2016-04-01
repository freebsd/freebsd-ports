# Created by: Anton Karpov <toxa@toxahost.ru>
# $FreeBSD$

PORTNAME=	simscan
PORTVERSION=	1.4.0
PORTREVISION=	7
CATEGORIES=	mail security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Content/Anti-virus Scanner for qmail Written in C

USES=		qmail:build

GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

WORKDIR?=	${QMAIL_PREFIX}/${PORTNAME}
QMAIL_QUEUE=	${QMAIL_PREFIX}/bin/qmail-queue

SUB_FILES=	pkg-message

SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX} \
		SIMSCAN_DIR=${PORTNAME}
PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX} \
		SIMSCAN_DIR=${PORTNAME}

OPTIONS_DEFINE=	CLAMAV RIPMIME SPAMD USER DOMAIN ATTACH DROPMSG PASSTHRU HEADERS DSPAM DOCS
OPTIONS_DEFAULT=	CLAMAV RIPMIME
CLAMAV_DESC=	Support for ClamAV Virus Scanning
RIPMIME_DESC=	Ripmime Processing (if Clamav ScanMail disabled)
SPAMD_DESC=	Support for SpamAssassin Spam Filtering
USER_DESC=	Turn On Per User SpamAssassin (required SPAMD)
DOMAIN_DESC=	Turn On Per Domain Based Checking
ATTACH_DESC=	Turn On Attachment Scanning (required CLAMAV)
DROPMSG_DESC=	Drop Message in Case of Virus Found
PASSTHRU_DESC=	Pass Spam Thru, Do Not Reject (required SPAMD)
HEADERS_DESC=	Add a Received Line With Versions of Scanners
DSPAM_DESC=	Turn on DSPAM scanning

CONFIGURE_ARGS=--enable-clamavdb-path=/var/db/clamav \
		--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-spamc-user=n \
		--enable-workdir=${WORKDIR} \
		--enable-user=nobody

CLAMAV_CONFIGURE_OFF=	--enable-clamav=n
CLAMAV_BUILD_DEPENDS=	clamdscan:security/clamav

RIPMIME_CONFIGURE_OFF=	--disable-ripmime
RIPMIME_BUILD_DEPENDS=	ripmime:mail/ripmime

SPAMD_BUILD_DEPENDS=	spamassassin:mail/spamassassin
SPAMD_CONFIGURE_ON=	--enable-spam=y \
			--enable-spamassassin-path=${LOCALBASE}/bin/spamassassin

USER_CONFIGURE_ON=	--enable-spamc-user=y

DOMAIN_CONFIGURE_ON=	--enable-per-domain=y

ATTACH_CONFIGURE_ON=	--enable-attach=y

DROPMSG_CONFIGURE_ON=	--enable-dropmsg=y

PASSTHRU_CONFIGURE_ON=	--enable-spam-passthru=y

HEADERS_CONFIGURE_ON=	--enable-received=y \
			--enable-sigtool-path=${LOCALBASE}/bin/sigtool

DSPAM_CONFIGURE_ON=	--enable-dspam=y
DSPAM_BUILD_DEPENDS=	dspam:mail/dspam

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
	${ECHO_MSG} "Unable to find qmail-queue binary trying '${QMAIL_QUEUE}'.";  \
	${ECHO_MSG} "Please set QMAIL_PREFIX to your qmail installation directory !"; \
	exit 1; \
fi

post-patch:
	@${REINPLACE_CMD} -E 's,($f/daily.cvd"),\1 || test -d "$$f/daily.inc",' \
		${WRKSRC}/configure
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/cdb/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP} ${LDFLAGS}" > ${WRKSRC}/cdb/conf-ld
	@${ECHO_CMD} ${STAGEDIR}${PREFIX} > ${WRKSRC}/cdb/conf-home
	@${REINPLACE_CMD} -E -e 's|@qmaildir@|$$(DESTDIR)@qmaildir@|' \
	    -e 's|@workdir@|$$(DESTDIR)@workdir@|' \
	    -e '/ch(mod|own)/d' \
	    ${WRKSRC}/Makefile.in

pre-configure:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~="
	@${ECHO_MSG} "You may also use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "QMAIL_PREFIX	Base qmail directory. Default is ${QMAIL_PREFIX}"
	@${ECHO_MSG} "WORKDIR		Directory to unpack emails. Default is ${QMAIL_PREFIX}/${PORTNAME}"
	@${ECHO_MSG} "QMAIL_QUEUE	Define full path and name of the qmail-queue program"
	@${ECHO_MSG} "		Incoming mail is passed to this program after being"
	@${ECHO_MSG} "		scanned by SimScan. Default is ${QMAIL_PREFIX}/bin/qmail-queue"
	@${ECHO_MSG} "SPAMC_ARGS	Define the arguments to pass to spamc."
	@${ECHO_MSG} "		Be sure to place quotes around the options you define"
	@${ECHO_MSG} "SPAM_HITS	Reject spam only above this hit level"
	@${ECHO_MSG} "		Default is 10.0. Useful without PASSTHRU option"
	@${ECHO_MSG} "QUARANTINE_DIR	Directory to keep spam and/or infected emails"
	@${ECHO_MSG} "		Default is disabled"
	@${ECHO_MSG} "=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~="
	@${ECHO_MSG} ""

pre-install:
	${MKDIR} ${STAGEDIR}${QMAIL_PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
