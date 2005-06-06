# New ports collection makefile for: phpLDAPadmin
# Date created:		30 Apr 2004
# Whom:			Matthew Seaman
#
# $FreeBSD$
#

PORTNAME=	phpldapadmin
DISTVERSION=	0.9.6c
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpldapadmin

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	A set of PHP-scripts to administer LDAP servers over the web

NO_BUILD=	yes
USE_PHP=	ldap openssl pcre session

.if defined(WITH_SUPHP)

PKGNAMESUFFIX=	-suphp
RUN_DEPENDS+=	${LOCALBASE}/sbin/suphp:${PORTSDIR}/www/suphp
WANT_PHP_CGI=	yes
PKGINST_SKEL=	${PKGDIR}/pkg-install${PKGNAMESUFFIX}
PKGINSTALL=	${WRKDIR}/pkg-install${PKGNAMESUFFIX}
PKGDEINST_SKEL=	${PKGDIR}/pkg-deinstall${PKGNAMESUFFIX}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall${PKGNAMESUFFIX}

PLAUSR?=	pldapadm

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%PLADIR%%,${PLADIR},g' \
		-e 's,%%PLAUSR%%,${PLAUSR},g' \
		-e 's,%%PLAGRP%%,${PLAGRP},g'

.else

WANT_PHP_WEB=	yes

.endif

MSG_SKEL=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# PLAUSR is only used WITH_SUPHP
PLADIR?=	www/${PORTNAME}
PLAGRP?=	${WWWGRP}
CFGFILE=	config.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PLADIR=${PLADIR} PLAGRP=${PLAGRP}

.SILENT:

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "You may use the following build options:"
	${ECHO_MSG} ""
	${ECHO_MSG} "    WITH_SUPHP=yes   Install appropriately for use with"
	${ECHO_MSG} "                     the www/suphp port [default: no]"
	${ECHO_MSG} ""

post-patch:
	${RM} -f ${PLIST}
	cd ${WRKSRC} ; \
	${FIND} . ! -type d ! -name ${CFGFILE}.example ! -name .cvsignore | \
	    ${SORT} | ${SED} "s,^\.,%%PLADIR%%,"     >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk            >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	    -e "s,^\.$$,@unexec rmdir %D/%%PLADIR%% 2>/dev/null || true," \
	    -e "s,^\.,@dirrm %%PLADIR%%,"           >>${PLIST}
	${SED} -e 's,%%PKGNAME%%,${PKGNAME},g' \
	       -e 's,%%PREFIX%%,${PREFIX},g'   \
	       -e 's,%%PLADIR%%,${PLADIR},g'   ${MSG_SKEL} > ${PKGMESSAGE}
.if defined(WITH_SUPHP)
	${SED} ${SED_SCRIPT} ${PKGINST_SKEL}   > ${PKGINSTALL}
	${SED} ${SED_SCRIPT} ${PKGDEINST_SKEL} > ${PKGDEINSTALL}
.endif

pre-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} ; \
	for src in $$( ${FIND} . ! -name .cvsignore  ) ; do \
	    dst=${PREFIX}/${PLADIR}$${src#.} ; \
	    if ${TEST} -d $$src ; then \
	        ${MKDIR} $$dst ; \
	    else \
	        ${INSTALL_DATA} $$src $$dst ; \
	    fi \
	done

install-conf:
	cd ${PREFIX}/${PLADIR} ; \
	${CHMOD} 0640 ${CFGFILE}.example ; \
	${CHGRP} ${PLAGRP} ${CFGFILE}.example ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
	    ${CP} -p ${CFGFILE}.example ${CFGFILE} ; \
	fi

post-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
