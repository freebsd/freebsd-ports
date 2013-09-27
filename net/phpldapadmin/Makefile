# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	phpldapadmin
PORTVERSION=	1.2.3
PORTEPOCH=	1
CATEGORIES=	net www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php5/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	A set of PHP-scripts to administer LDAP over the web

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	gettext ldap openssl pcre session xml iconv hash
DEFAULT_PHP_VER=	5

OPTIONS_DEFINE=	SUPHP
SUPHP_DESCR=	suPHP support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSUPHP}

PKGNAMESUFFIX+=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes

.else

WANT_PHP_WEB=	yes

.endif

# USERS is only used when SUPHP option selected
GROUPS?=	${WWWGRP}
CFGDIR=		config
CFGFILE=	config.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PLA_GRP=${GROUPS}

.if ${PORT_OPTIONS:MSUPHP}

USERS?=		_pla

SUB_LIST+=	PLA_USR=${USERS}  \
		PLA_GRP=${GROUPS}
SUB_FILES+=	pkg-install pkg-deinstall

.endif

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

.SILENT:

post-patch:
	cd ${WRKSRC} ;							    \
	${FIND} . ! -type d ! -name ${CFGFILE}.example ! -name .cvsignore   \
	    ! -name .gitignore | ${SORT} | ${SED} -e "s!^\.!%%WWWDIR%%!"    \
								>${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk		       >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED}				    \
	    -e 's!^\./${CFGDIR}$$!@dirrmtry %%WWWDIR%%/${CFGDIR}!'	    \
	    -e 's!^\.$$!@dirrmtry %%WWWDIR%%!'				    \
	    -e 's!^\.!@dirrm %%WWWDIR%%!'		       >>${PLIST}

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ;				    \
	for src in $$( ${FIND} . ! -name .cvsignore \
			 ! -name .gitignore  ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ;	    \
	    if ${TEST} -d $$src ; then		    \
		${MKDIR} $$dst ;		    \
	    else				    \
		${INSTALL_DATA} $$src $$dst ;	    \
	    fi					    \
	done

install-conf:
	cd ${STAGEDIR}${WWWDIR}/${CFGDIR} ;	     \
	${CHMOD} 0640 ${CFGFILE}.example ;	     \
	${CHGRP} ${GROUPS} ${CFGFILE}.example ;	     \
	if ${TEST} ! -f ${CFGFILE} ; then	     \
	    ${CP} -p ${CFGFILE}.example ${CFGFILE} ; \
	fi

.include <bsd.port.mk>
