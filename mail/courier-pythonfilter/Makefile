# New ports collection makefile for:	courier-pythonfilter
# Date created:				Jun 19, 2006
# Whom:					Milan Obuch
#
# $FreeBSD$
#

PORTNAME=	courier-pythonfilter
PORTVERSION=	1.6
CATEGORIES=	mail python
MASTER_SITES=	http://phantom.dragonsdawn.net/~gordon/courier-patches/courier-pythonfilter/

MAINTAINER=	bsd@dino.sk
COMMENT=	Framework for courier filter development in python

BUILD_DEPENDS=	courier-config:${PORTSDIR}/mail/courier

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAILOWN=	courier
MAILGRP=	courier
MAILUID=	465
MAILGID=	465

LOCALSTATEDIR=	/var/spool/courier
SCRIPTSDIR=	${PREFIX}/libexec/filters

OPTIONS=	DEBUG		"debug module"					on \
		NODUPLICATES	"noduplicates module"				off \
		LOCALSENDERS	"localsenders module"				off \
		CLAMAV_CLAMD	"clamav filter with py-pyclamd \ mutually"	off \
		CLAMAV_LIB	"clamav filter with py-clamav  / exclusive"	off \
		SPAMASSASSIN	"spamassassin module"				off \
		AUTO_WHITELIST	"auto_whitelist module"				off \
		WHITELIST_RELAY	"whitelist_relayclients module"			on \
		WHITELIST_AUTH	"whitelist_auth module"				on \
		WHITELIST_BLOCK	"whitelist_block module"			off \
		WHITELIST_DNSWL	"whitelist_dnswl module"			off \
		WHITELIST_SPF	"whitelist_spf module"				off \
		DELIVEREDTO	"deliveredto module"				off \
		PRIVATEADDR	"privateaddr module"				off \
		SPFCHECK	"spfcheck module"				off \
		NOSUCCESSDSN	"nosuccessdsn module"				off \
		COMEAGAIN	"comeagain module"				off \
		GREYLIST	"greylist module"				off \
		DIALBACK	"dialback module"				off \
		RATELIMIT	"ratelimit module"				off \
		ATTACHMENTS	"attachments module"				off \
		QUOTA		"quota module"					off

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS:=${PYDISTUTILS_INSTALLARGS} --install-scripts=${SCRIPTSDIR}

.if defined(WITH_CLAMAV_CLAMD) && !defined(WITH_CLAMAV_LIB)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pyclamd.py:${PORTSDIR}/security/py-pyclamd
.endif

.if defined(WITH_CLAMAV_LIB) && !defined(WITH_CLAMAV_CLAMD)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pyclamav.so:${PORTSDIR}/security/py-clamav
.endif

.if defined(WITH_CLAMAV_CLAMD) && defined(WITH_CLAMAV_LIB)
BROKEN= py-pyclamd and py-clamav dependencies are mutually exclusive. Run 'make config' to (re)configure ${PKGNAME}
.endif

post-extract:
	${MV} ${WRKSRC}/pythonfilter.conf ${WRKSRC}/pythonfilter.conf.sample
	${MV} ${WRKSRC}/pythonfilter-modules.conf ${WRKSRC}/pythonfilter-modules.conf.sample

post-configure:
	@${ECHO_MSG} Adding your OPTIONS to sample config file...
	@${ECHO_MSG} >> ${WRKSRC}/pythonfilter.conf.sample
.if !defined(WITHOUT_DEBUG)
	@${ECHO_MSG} debug >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_NODUPLICATES)
	@${ECHO_MSG} noduplicate >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_LOCALSENDERS)
	@${ECHO_MSG} localsenders >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_CLAMAV_CLAMD) || defined(WITH_CLAMAV_LIB)
	@${ECHO_MSG} clamav >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_SPAMASSASSIN)
	@${ECHO_MSG} spamassassin >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_AUTO_WHITELIST)
	@${ECHO_MSG} auto_whitelist >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if !defined(WITHOUT_WHITELIST_RELAY)
	@${ECHO_MSG} whitelist_relayclients >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if !defined(WITHOUT_WHITELIST_AUTH)
	@${ECHO_MSG} whitelist_auth >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_WHITELIST_BLOCK)
	@${ECHO_MSG} whitelist_block >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_WHITELIST_DNSWL)
	@${ECHO_MSG} whitelist_dnswl >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_WHITELIST_SPF)
	@${ECHO_MSG} whitelist_spf >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_DELIVEREDTO)
	@${ECHO_MSG} deliveredto >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_PRIVATEADDR)
	@${ECHO_MSG} privateaddr >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_SPFCHECK)
	@${ECHO_MSG} spfcheck >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_NOSUCCESSDSN)
	@${ECHO_MSG} nosuccessdsn >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_COMEAGAIN)
	@${ECHO_MSG} comeagain >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_GREYLIST)
	@${ECHO_MSG} greylist >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_DIALBACK)
	@${ECHO_MSG} dialback >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_RATELIMIT)
	@${ECHO_MSG} ratelimit >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_ATTACHMENTS)
	@${ECHO_MSG} attachments >> ${WRKSRC}/pythonfilter.conf.sample
.endif
.if defined(WITH_QUOTA)
	@${ECHO_MSG} quota >> ${WRKSRC}/pythonfilter.conf.sample
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/pythonfilter

post-install:
	${MKDIR} ${LOCALSTATEDIR}/pythonfilter
	${CHOWN} ${MAILOWN}:${MAILGRP} ${LOCALSTATEDIR}/pythonfilter
	@if [ ! -f ${PREFIX}/etc/pythonfilter.conf ]; then cp -p ${PREFIX}/etc/pythonfilter.conf.sample ${PREFIX}/etc/pythonfilter.conf; fi
	@if [ ! -f ${PREFIX}/etc/pythonfilter-modules.conf ]; then cp -p ${PREFIX}/etc/pythonfilter-modules.conf.sample ${PREFIX}/etc/pythonfilter-modules.conf; fi

.include <bsd.port.post.mk>
