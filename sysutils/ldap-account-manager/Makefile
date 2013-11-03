# $FreeBSD$

PORTNAME=	ldap-account-manager
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${SHORTNAME}/LAM/${PORTVERSION}

USE_BZIP2=	yes

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Quota>=0:${PORTSDIR}/sysutils/p5-Quota \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap

NO_BUILD=	yes
USES=		gettext perl5
USE_PHP=	gettext hash iconv ldap mcrypt pcre session simplexml spl xml json zip openssl
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=	5

SHORTNAME=	lam
PORTDOCS=	docs HISTORY README copyright
LAMDATA=	config graphics help lib locale sess style templates tmp VERSION index.html
WWWDIR?=	${PREFIX}/www/${SHORTNAME}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	-@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	-@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif

post-install:
	@${MKDIR} ${WWWDIR}/config/pdf
	@${MKDIR} ${WWWDIR}/config/profiles
	@if [ ! -f ${WWWDIR}/config/config.cfg ]; then \
	    ${CP} -p ${WWWDIR}/config/config.cfg_sample ${WWWDIR}/config/config.cfg ; \
	fi
	@if [ ! -f ${WWWDIR}/config/lam.conf ]; then \
	    ${CP} -p ${WWWDIR}/config/lam.conf_sample ${WWWDIR}/config/lam.conf ; \
	fi
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} 755 {} \;
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/config ${WWWDIR}/sess ${WWWDIR}/tmp
	@${CHMOD} 755 ${WWWDIR}/lib/lamdaemon.pl
	@${LN} -sf /etc/shells ${WWWDIR}/config/shells
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
