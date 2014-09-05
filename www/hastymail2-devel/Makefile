# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	hastymail2
PORTVERSION=	1.1.${HASTYMAIL_REV:S/.//g}
CATEGORIES=	www mail
MASTER_SITES=	http://files.bsdroot.lv/my/FreeBSD/distfiles/hastymail2-devel/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-devel-${HASTYMAIL_REV}

MAINTAINER=	graudeejs@gmail.com
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

OPTIONS_DEFINE=	PGSQL MYSQL DB
DB_DESC=	Use older pear DB (instead of MDB2)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
.endif
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=	pgsql
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.endif
.endif

.if ${PORT_OPTIONS:MDB} && (${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL}}
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
	@${MKDIR} ${STAGEDIR}${PREFIX}/${INSTALL_DIR}
	@cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} \
		| ${PAX} -rwd ${STAGEDIR}${PREFIX}/${INSTALL_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}${PREFIX}/${INSTALL_DIR}
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${INSTALL_DATA} ${WRKSRC}/hastymail2.conf.example \
		${STAGEDIR}${ETCDIR}/hastymail2.conf.sample

.include <bsd.port.mk>
