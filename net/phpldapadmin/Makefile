# New ports collection makefile for: phpLDAPadmin
# Date created:		30 Apr 2004
# Whom:			Matthew Seaman
#
# $FreeBSD$
#

PORTNAME=	phpldapadmin
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	net www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php5/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to administer LDAP over the web

NO_BUILD=	yes
USE_PHP=	gettext ldap openssl pcre session xml iconv hash
DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)

PKGNAMESUFFIX+=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes

.else

WANT_PHP_WEB=	yes

.endif

# PLA_USR is only used WITH_SUPHP
PLA_GRP?=	${WWWGRP}
PLA_GID?=	${_PLA_GID}
CFGDIR=		config
CFGFILE=	config.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PLA_GRP=${PLA_GRP}

.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)

PLA_USR?=	_pla
PLA_UID?=	636
PLA_GCOS?=	"phpLDAPAdmin Owner"
PLA_HOME?=	/nonexistent
PLA_SHELL?=	/usr/sbin/nologin

SUB_LIST+=	PLA_USR=${PLA_USR}    \
		PLA_UID=${PLA_UID}    \
		PLA_GRP=${PLA_GRP}    \
		PLA_GID=${PLA_GID}    \
		PLA_GCOS=${PLA_GCOS}  \
		PLA_HOME=${PLA_HOME}  \
		PLA_SHELL=${PLA_SHELL}
SUB_FILES+=	pkg-install pkg-deinstall

.endif

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

.include <bsd.port.pre.mk>
_PLA_GID!=	${PW} group show -n ${PLA_GRP} | ${CUT} -d : -f 3
.if empty(_PLA_GID)
_PLA_GID=	80
.endif

.SILENT:

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "You may use the following build options:"
	${ECHO_MSG} ""
	${ECHO_MSG} "    WITH_SUPHP=yes   Install appropriately for use with"
	${ECHO_MSG} "                     the www/suphp port [default: no]"
	${ECHO_MSG} ""
	${ECHO_MSG} "This port is PHP5 specific. If you need PHP4 support,"
	${ECHO_MSG} "please use the net/phpldapadmin098 port instead."
	${ECHO_MSG} ""
.if defined(WITH_SUPHP) && !defined(WITHOUT_SUPHP)
	@if ${PW} show -n pldapadm >/dev/null 2>&1 ; then	              \
	    ${ECHO_MSG} "===> WARNING ******************************" ;	      \
	    ${ECHO_MSG} "The default username used by ${PKNAME} has changed"; \
	    ${ECHO_MSG} "to ${PLA_USR} -- you should delete the old user:" ;  \
	    ${ECHO_MSG} "  # ${PW} user del -n pldapadm" ;	              \
	    ${ECHO_MSG} "" ;						      \
	fi
.endif

post-patch:
	cd ${WRKSRC} ;							    \
	${FIND} . ! -type d ! -name ${CFGFILE}.example ! -name .cvsignore | \
	    ${SORT} | ${SED} -e "s!^\.!%%WWWDIR%%!"		>${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk		       >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED}				    \
	    -e 's!^\./${CFGDIR}$$!@dirrmtry %%WWWDIR%%/${CFGDIR}!'	    \
	    -e 's!^\.$$!@dirrmtry %%WWWDIR%%!'				    \
	    -e 's!^\.!@dirrm %%WWWDIR%%!'		       >>${PLIST}

pre-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore  ) ; do \
	    dst=${WWWDIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
		${MKDIR} $$dst ; \
	    else \
		${INSTALL_DATA} $$src $$dst ; \
	    fi \
	done

install-conf:
	cd ${WWWDIR}/${CFGDIR} ; \
	${CHMOD} 0640 ${CFGFILE}.example ; \
	${CHGRP} ${PLA_GRP} ${CFGFILE}.example ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
	    ${CP} -p ${CFGFILE}.example ${CFGFILE} ; \
	fi

post-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
