# New ports collection makefile for: phpAdsNew
# Date created:                2005-05-08
# Whom:                        Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	phpAdsNew
DISTVERSION=	2.0.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	phpadsnew

MAINTAINER=	meno.abels@adviser.com
COMMENT=	The phpAdsNew is an open-source ad server

USE_GZIP=	yes
NO_BUILD=	yes
USE_PHP=	mysql pcre zlib

SUB_LIST+=	"MYADSDIR=${MYADSDIR}" \
		"PKGNAME=${PKGNAME}"

# Unfortunately can't make WITH_SUPHP part of the OPTIONS selection,
# since it has to be processed before just about anything else.

WANT_PHP_WEB=	yes

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

# MYADSUSR is only used WITH_SUPHP
MYADSDIR?=	www/phpadsnew
MYADSGRP?=	${WWWGRP}
CFGFILE=	config.inc.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	MYADSDIR=${MYADSDIR} MYADSGRP=${MYADSGRP}

.SILENT:

do-build:
	@${DO_NADA}

pre-everything::
	${ECHO_MSG} ""
	${ECHO_MSG} "You may use the following additional build option:"
	${ECHO_MSG} ""
	${ECHO_MSG} "    WITH_SUPHP=yes   Install appropriately for use with"
	${ECHO_MSG} "                     the www/suphp port [default: no]"
	${ECHO_MSG} ""

post-patch:
	${MV} ${WRKSRC}/${CFGFILE} ${WRKSRC}/${CFGFILE}.sample
	cd ${WRKSRC} && \
	if ${TEST} -d "misc/backwards compatibility" ; then \
		${MV} "misc/backwards compatibility" "misc/backwards_compatibility" ; \
	fi ; \
	${FIND} . ! -type d ! -name ${CFGFILE}.sample | ${SORT} | \
	    ${SED} -e "s,^\.,%%MYADSDIR%%,"           >${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk             >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	     -e "s,^\.$$,@unexec ${RMDIR} %D/%%MYADSDIR%% 2>/dev/null || true," \
	     -e "s,^\.,@dirrm %%MYADSDIR%%,"         >>${PLIST}

pre-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

do-install: install-app install-conf

install-app:
	cd ${WRKSRC} && \
	for src in $$( ${FIND} . ! -name .cvsignore ) ; do \
	    dst=${PREFIX}/${MYADSDIR}$${src#.} ; \
	    if ${TEST} -d "$$src" ; then \
	        ${MKDIR} "$$dst" ; \
	    else \
	        ${INSTALL_DATA} "$$src" "$$dst" ; \
	    fi \
	done

install-conf: install-app
	cd ${PREFIX}/${MYADSDIR} ; \
	${CHMOD} 0640 ${CFGFILE}.sample ; \
	${CHGRP} ${MYADSGRP} ${CFGFILE}.sample ; \
	if ${TEST} ! -f ${CFGFILE} ; then \
	    ${CP} -p ${CFGFILE}.sample ${CFGFILE} ; \
	fi

post-install:
.if defined(WITH_SUPHP)
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
