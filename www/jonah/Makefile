# Ports collection makefile for:  Jonah
# Date created:			  Mon Dec 17, 2001
# Whom:				  Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	jonah
PORTVERSION=	0.0.3.020629
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://pompo.net/horde/jonah/

MAINTAINER=	thierry@pompo.net
COMMENT=	Jonah is a portal and content collection system

WRKSRC=		${WRKDIR}/${PORTNAME}

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2 \
		${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

IS_INTERACTIVE=	'need to build php4 with XML support.'
NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeJonah

DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/HELP \
		docs/INSTALL
CONFFILE=	channels.php conf.php html.php
SUB_DIRS=	config graphics lib scripts templates

LHORDEDIR?=	www/horde
LJONAHDIR?=	${LHORDEDIR}/jonah
RSS_HTML?=	/var/jonah
PHPSADIR?=	${LOCALBASE}/etc/php.standalone

PLIST_SUB=	HORDEDIR=${LHORDEDIR} JONAHDIR=${LJONAHDIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
JONAHDIR=	${PREFIX}/${LJONAHDIR}
CONFDIR=	${JONAHDIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde
HORDE_CNF=	${HORDEDIR}/config/horde.php
PHPSA_INI=	${PHPSADIR}/php.ini

pre-install:
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "expat.2"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with XML support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi

do-install:
	@${MKDIR}  ${JONAHDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${JONAHDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${JONAHDIR}
	@${MV} ${JONAHDIR}/scripts/cli-backend.php ${PREFIX}/bin
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${REINPLACE_CMD} -e "s:/var/jonah:${RSS_HTML}:" ${CONFDIR}/conf.php
	@${RM} ${CONFDIR}/conf.php.beforeJonah
	@${REINPLACE_CMD} -e "s:%%JONAHDIR%%:'${JONAHDIR}':" \
		${PREFIX}/bin/cli-backend.php
	@${RM} ${PREFIX}/bin/cli-backend.php.beforeJonah
	@${CHOWN} -R www:www ${JONAHDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.jonah ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/jonah:${JONAHDIR}:g" \
		${HORDE_INC}/httpd.conf.jonah
	@${RM} ${HORDE_INC}/httpd.conf.jonah.beforeJonah
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTJONAH::" \
		${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php \
		${HORDEDIR}/config/registry.php.afterJonah
	@${MKDIR}  ${RSS_HTML}/html ${RSS_HTML}/rss
	@${CHOWN} -R root:www ${RSS_HTML}
	@if ${GREP} -q -e "conf\['auth'\]\['admins'\] = array()" ${HORDE_CNF} ; then \
		${ECHO_MSG} "===> Defining admin in ${HORDE_CNF}" ; \
		${REINPLACE_CMD} -e "s:admins'] = array():admins'] = array('admin'):" ${HORDE_CNF} ; \
		${CP} -p ${HORDE_CNF} ${HORDE_CNF}.afterJonah ; \
	fi
	@if [ ! -f ${PHPSA_INI} ]; then \
	  ${ECHO_MSG} "===> Creating ${PHPSA_INI} for PHP standalone" ; \
	  ${CP} ${PHPSA_INI}-dist ${PHPSA_INI} ; \
	fi
	@if ! ${GREP} -q -e '^include_path' ${PHPSA_INI} ; then \
	  ${ECHO_MSG} "===> Configuring ${PHPSA_INI} for PHP standalone" ; \
	  ${REINPLACE_CMD} -e 's!;include_path = ".:/php/includes"!include_path = "${LOCALBASE}/include/php:.:${LOCALBASE}/lib/php"!' ${PHPSA_INI} ; \
	  ${CP} -p ${PHPSA_INI} ${PHPSA_INI}.afterJonah ; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%JONAHDIR%%:${JONAHDIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;s:%%PREFIX%%:${PREFIX}:"
	@${ECHO_MSG}

.include <bsd.port.mk>
