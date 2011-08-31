# New ports collection makefile for:	hastymail
# Date created:		2006-11-04
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	hastymail2
PORTVERSION=	1.1.${HASTYMAIL_REV:S/.//g}
CATEGORIES=	www mail
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/hastymail2-devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-devel-${HASTYMAIL_REV}

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Small, fast and secure yet powerful IMAP webmail

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_FILES=	pkg-message

INSTALL_DIR?=	www/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	session imap pcre

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
FIND_SKIP_OPTS=	-not -name hastymail2.conf.example -not -name '*.orig'

CONFLICTS=	hastymail2-1.[0-9]*

HASTYMAIL_REV=	2011.08.22

OPTIONS=	PGSQL	"Use PostgreSQL" off \
		MYSQL	"Use MySQL" off \
		DB	"Use older pear DB (instead of MDB2)" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
.if !defined(WITH_DB)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
.endif
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.if !defined(WITH_DB)
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.endif
.endif

.if defined(WITH_DB) && (defined(WITH_MYSQL) || defined(WITH_PGSQL))
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

post-patch:
	@${SED} -I.orig -e "s#'/etc/hastymail2/hastymail2.rc'#'${ETCDIR}/hastymail2.rc'#" \
		${WRKSRC}/index.php
	@${SED} -I.orig -e "s# /etc/hastymail/hastyamil2.rc# ${ETCDIR}/hastyamil2.rc#" \
		${WRKSRC}/hastymail2.conf.example

pre-install:
	@${FIND} -s -d ${WRKSRC}/ -type f ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#${INSTALL_DIR}#g" > ${PLIST}
	@${ECHO_CMD} %%ETCDIR%%/hastymail2.conf.sample >> ${PLIST}
	@${FIND} -s -d ${WRKSRC}/ -type d ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#@dirrm ${INSTALL_DIR}#g" >> ${PLIST}
	@${ECHO_CMD} @dirrmtry %%ETCDIR%% >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALL_DIR}
	@cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} \
		| ${PAX} -rwd ${PREFIX}/${INSTALL_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${INSTALL_DIR}
	@${MKDIR} ${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/hastymail2.conf.example \
		${ETCDIR}/hastymail2.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
