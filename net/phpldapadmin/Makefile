# Created by: Matthew Seaman
# $FreeBSD$

PORTNAME=	phpldapadmin
PORTVERSION=	1.2.3
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-php5/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	PHP application to administer LDAP over the web

LICENSE=	GPLv2

NO_ARCH=	yes
NO_BUILD=	yes
USE_PHP=	gettext ldap openssl pcre session xml iconv hash
DEFAULT_PHP_VER=	5

WANT_PHP_WEB=	yes

GROUPS?=	${WWWGRP}
CFGDIR=		config
CFGFILE=	config.php

PLIST=		${WRKDIR}/plist
PLIST_SUB+=	PLA_GRP=${GROUPS}

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

.SILENT:

post-patch:
	cd ${WRKSRC} ;							    \
	${FIND} . ! -type d ! -name ${CFGFILE}.example ! -name .cvsignore   \
	    ! -name .gitignore ! -name *.orig | ${SORT} |		    \
	    ${SED} -e "s!^\.!%%WWWDIR%%!"			>${PLIST} ; \
	${CAT} ${PKGDIR}/pkg-plist-chunk		       >>${PLIST} ; \
	${FIND} . -type d | ${SORT} -r | ${SED}				    \
	    -e 's!^\./${CFGDIR}$$!@dirrmtry %%WWWDIR%%/${CFGDIR}!'	    \
	    -e 's!^\.$$!@dirrmtry %%WWWDIR%%!'				    \
	    -e 's!^\.!@dirrm %%WWWDIR%%!'		       >>${PLIST}

do-install:
	cd ${WRKSRC} ;				    	 \
	for src in $$( ${FIND} . ! -name .cvsignore	 \
		! -name .gitignore ! -name *.orig ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ;	    	 \
	    if ${TEST} -d $$src ; then		    	 \
		${MKDIR} $$dst ;		    	 \
	    else				    	 \
		${INSTALL_DATA} $$src $$dst ;	    	 \
	    fi					    	 \
	done

.include <bsd.port.mk>
