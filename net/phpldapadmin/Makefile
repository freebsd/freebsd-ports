# Created by: Matthew Seaman

PORTNAME=	phpldapadmin
PORTVERSION=	1.2.6.3
CATEGORIES=	net www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	ports@bsdserwis.com
COMMENT=	PHP application to administer LDAP over the web

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe php:web,flavors tar:tgz
USE_PHP=	gettext ldap openssl pcre session xml iconv hash
USE_GITHUB=	yes
GH_ACCOUNT=	leenooks
GH_PROJECT=	phpLDAPadmin

NO_ARCH=	yes
NO_BUILD=	yes
CPE_VENDOR=	phpldapadmin_project

OPTIONS_DEFINE=	MCRYPT

MCRYPT_DESC=	Use pecl-mcrypt for password hashing
MCRYPT_USE=	PHP=mcrypt

.include <bsd.port.options.mk>

GROUPS?=	${WWWGRP}
CFGDIR=		config
CFGFILE=	config.php

PLIST=		${WRKDIR}/plist
PLIST_FILES=	'@sample(,${GROUPS},640) ${WWWDIR_REL}/config/config.php.example ${WWWDIR_REL}/config/config.php'

SUB_LIST+=	PKGNAME=${PKGNAME}
SUB_FILES+=	pkg-message

.SILENT:

.include <bsd.port.pre.mk>

post-patch:
	cd ${WRKSRC} ;							    \
	${FIND} . ! -type d ! -name ${CFGFILE}.example ! -name .cvsignore   \
	    ! -name .gitignore ! -name *.orig | ${SORT} |		    \
	    ${SED} -e "s!^\.!${WWWDIR_REL}!"			>${PLIST} ;

do-install:
	cd ${WRKSRC} ;					 \
	for src in $$( ${FIND} . ! -name .cvsignore	 \
		! -name .gitignore ! -name *.orig ) ; do \
	    dst=${STAGEDIR}${WWWDIR}$${src#.} ;		 \
	    if ${TEST} -d $$src ; then			 \
		${MKDIR} $$dst ;			 \
	    else					 \
		${INSTALL_DATA} $$src $$dst ;		 \
	    fi						 \
	done

.include <bsd.port.post.mk>
