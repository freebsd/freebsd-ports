# Created by: Milan Obuch
# $FreeBSD$

PORTNAME=	courier-pythonfilter
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	http://phantom.dragonsdawn.net/~gordon/courier-patches/courier-pythonfilter/

MAINTAINER=	bsd@dino.sk
COMMENT=	Framework for courier filter development in python

BUILD_DEPENDS=	courier-config:mail/courier

USES=		python:2.7
USE_PYTHON=	distutils concurrent optsuffix
NO_ARCH=	yes

MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465

LOCALSTATEDIR=	/var/spool/courier
PYSCRIPTSDIR=	${PREFIX}/libexec/filters

PLIST_SUB+=	MAILOWN="${MAILOWN}" MAILGRP="${MAILGRP}" \
		MAILUID="${MAILUID}" MAILGID="${MAILGID}" \
		LOCALSTATEDIR="${LOCALSTATEDIR}"
SUB_LIST+=	${PLIST_SUB}

OPTIONS_DEFINE=	DEBUG NODUPLICATES LOCALSENDERS SPAMASSASSIN AUTO_WHITELIST WHITELIST_RELAY WHITELIST_AUTH \
		WHITELIST_BLOCK WHITELIST_DNSWL WHITELIST_DNSWL DELIVEREDTO PRIVATEADDR SPFCHECK NOSUCCESSDSN \
		COMEAGAIN GREYLIST DIALBACK RATELIMIT ATTACHMENTS QUOTA WHITELIST_SPF CLAMAV_CLAMD

DEBUG_DESC=	debug module
NODUPLICATES_DESC=	noduplicates module
LOCALSENDERS_DESC=	localsenders module
CLAMAV_CLAMD_DESC=	clamav filter with py-pyclamd
SPAMASSASSIN_DESC=	spamassassin module
AUTO_WHITELIST_DESC=	auto_whitelist module
WHITELIST_RELAY_DESC=	whitelist_relayclients module
WHITELIST_AUTH_DESC=	whitelist_auth module
WHITELIST_BLOCK_DESC=	whitelist_block module
WHITELIST_DNSWL_DESC=	whitelist_dnswl module
WHITELIST_SPF_DESC=	whitelist_spf module
DELIVEREDTO_DESC=	deliveredto module
PRIVATEADDR_DESC=	privateaddr module
SPFCHECK_DESC=	spfcheck module
NOSUCCESSDSN_DESC=	nosuccessdsn module
COMEAGAIN_DESC=	comeagain module
GREYLIST_DESC=	greylist module
DIALBACK_DESC=	dialback module
RATELIMIT_DESC=	ratelimit module
ATTACHMENTS_DESC=	attachments module
QUOTA_DESC=	quota module

OPTIONS_DEFAULT=	DEBUG WHITELIST_RELAY WHITELIST_AUTH

CLAMAV_CLAMD_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyClamd>=0:security/py-pyclamd@${PY_FLAVOR}

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=${PYDISTUTILS_INSTALLARGS} --install-scripts=${PYSCRIPTSDIR}

post-extract:
	${MV} ${WRKSRC}/pythonfilter.conf ${WRKSRC}/pythonfilter.conf.sample
	${MV} ${WRKSRC}/pythonfilter-modules.conf ${WRKSRC}/pythonfilter-modules.conf.sample

post-configure:
	@${ECHO_MSG} Adding your OPTIONS to sample config file...
	@${ECHO_MSG} >> ${WRKSRC}/pythonfilter.conf.sample
.if ${PORT_OPTIONS:MDEBUG}
	@${ECHO_MSG} debug >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MNODUPLICATES}
	@${ECHO_MSG} noduplicate >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MLOCALSENDERS}
	@${ECHO_MSG} localsenders >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MCLAMAV_CLAMD}
	@${ECHO_MSG} clamav >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MSPAMASSASSIN}
	@${ECHO_MSG} spamassassin >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MAUTO_WHITELIST}
	@${ECHO_MSG} auto_whitelist >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MWHITELIST_RELAY}
	@${ECHO_MSG} whitelist_relayclients >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MWHITELIST_AUTH}
	@${ECHO_MSG} whitelist_auth >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MWHITELIST_BLOCK}
	@${ECHO_MSG} whitelist_block >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MWHITELIST_DNSWL}
	@${ECHO_MSG} whitelist_dnswl >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MWHITELIST_SPF}
	@${ECHO_MSG} whitelist_spf >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MDELIVEREDTO}
	@${ECHO_MSG} deliveredto >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MPRIVATEADDR}
	@${ECHO_MSG} privateaddr >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MSPFCHECK}
	@${ECHO_MSG} spfcheck >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MNOSUCCESSDSN}
	@${ECHO_MSG} nosuccessdsn >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MCOMEAGAIN}
	@${ECHO_MSG} comeagain >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MGREYLIST}
	@${ECHO_MSG} greylist >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MDIALBACK}
	@${ECHO_MSG} dialback >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MRATELIMIT}
	@${ECHO_MSG} ratelimit >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MATTACHMENTS}
	@${ECHO_MSG} attachments >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if ${PORT_OPTIONS:MQUOTA}
	@${ECHO_MSG} quota >> ${WRKSRC}/pythonfilter.conf.sample
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pythonfilter

post-install:
	@${MKDIR} ${STAGEDIR}${LOCALSTATEDIR}/pythonfilter

.include <bsd.port.post.mk>
