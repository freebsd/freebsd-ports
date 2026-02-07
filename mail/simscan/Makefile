PORTNAME=	simscan
DISTVERSIONPREFIX=	v
DISTVERSION=	1.4.6.2
CATEGORIES=	mail security

MAINTAINER=	bedreddinsahbaz@gmail.com
COMMENT=	Fast Content/Anti-virus Scanner for qmail Written in C
WWW=		https://notes.sagredo.eu/en/qmail-notes-185/installing-and-configuring-simscan-38.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		qmail:build
USE_GITHUB=	yes
GH_ACCOUNT=	sagredo-dev

GNU_CONFIGURE=	yes
WORKDIR?=	${QMAIL_PREFIX}/${PORTNAME}
QMAIL_QUEUE=	${QMAIL_PREFIX}/bin/qmail-queue
CONFIGURE_ARGS=	--enable-clamavdb-path=/var/db/clamav \
		--enable-qmaildir=${QMAIL_PREFIX} \
		--enable-qmail-queue=${QMAIL_QUEUE} \
		--enable-spamc-user=n \
		--enable-workdir=${WORKDIR} \
		--enable-user=nobody
.if defined(QUARANTINE_DIR)
CONFIGURE_ARGS+=--enable-quarantinedir=${QUARANTINE_DIR}
.endif
.if defined(SPAMC_ARGS)
CONFIGURE_ARGS+=--enable-spamc-args=${SPAMC_ARGS}
.endif
.if defined(SPAM_HITS)
CONFIGURE_ARGS+=--enable-spam-hits=${SPAM_HITS}
.endif

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX} \
		SIMSCAN_DIR=${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${USERS:[1]} qmail

PLIST_SUB=	QMAIL_PREFIX=${QMAIL_PREFIX} \
		SIMSCAN_DIR=${PORTNAME} \
		USER=${USERS:[1]} \
		GROUP=${GROUPS:[1]} \
		QMAIL_GROUP=${GROUPS:[2]}
PORTDOCS=	AUTHORS ChangeLog README.md TODO

OPTIONS_DEFINE=		ATTACH CLAMAV DOCS DOMAIN DROPMSG DSPAM HEADERS \
			PASSTHRU RIPMIME SPAMD USER
OPTIONS_DEFAULT=	ATTACH  RIPMIME
ATTACH_DESC=		Turn On Attachment Scanning (required CLAMAV)
CLAMAV_DESC=		Support for ClamAV Virus Scanning
DOMAIN_DESC=		Turn On Per Domain Based Checking
DROPMSG_DESC=		Drop Message in Case of Virus Found
DSPAM_DESC=		Turn on DSPAM scanning
HEADERS_DESC=		Add a Received Line With Versions of Scanners
PASSTHRU_DESC=		Pass Spam Thru, Do Not Reject (required SPAMD)
RIPMIME_DESC=		Ripmime Processing (if Clamav ScanMail disabled)
SPAMD_DESC=		Support for SpamAssassin Spam Filtering
USER_DESC=		Turn On Per User SpamAssassin (required SPAMD)

ATTACH_CONFIGURE_ON=	--enable-attach=y

CLAMAV_IMPLIES=		ATTACH
CLAMAV_BUILD_DEPENDS=	clamdscan:security/clamav
CLAMAV_CONFIGURE_OFF=	--enable-clamav=n

DOMAIN_CONFIGURE_ON=	--enable-per-domain=y

DROPMSG_CONFIGURE_ON=	--enable-dropmsg=y

DSPAM_BUILD_DEPENDS=	dspam:mail/dspam
DSPAM_CONFIGURE_ON=	--enable-dspam=y

HEADERS_CONFIGURE_ON=	--enable-received=y \
			--enable-sigtool-path=${LOCALBASE}/bin/sigtool

PASSTHRU_CONFIGURE_ON=	--enable-spam-passthru=y

RIPMIME_BUILD_DEPENDS=	ripmime:mail/ripmime
RIPMIME_RUN_DEPENDS=	ripmime:mail/ripmime
RIPMIME_CONFIGURE_OFF=	--disable-ripmime

SPAMD_BUILD_DEPENDS=	spamassassin:mail/spamassassin
SPAMD_CONFIGURE_ON=	--enable-spam=y \
			--enable-spamassassin-path=${LOCALBASE}/bin/spamassassin

USER_CONFIGURE_ON=	--enable-spamc-user=y

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
