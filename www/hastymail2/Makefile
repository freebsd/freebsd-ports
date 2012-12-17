# New ports collection makefile for:	hastymail
# Date created:		2006-11-04
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	hastymail2
PORTVERSION=	1.1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www mail
MASTER_SITES=	SF/hastymail/Hastymail2%20Stable%20Releases/Hastymail2%201.1/
DISTNAME=	hastymail2_${WIKEDVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast and secure yet powerful IMAP webmail

LICENSE=	GPLv2

NO_BUILD=	yes
SUB_FILES=	pkg-message

CONFLICTS=      hastymail-* hastymail2-devel-*

PLIST=		${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	ctype pcre session xml

WIKEDVERSION=	1_1
WRKSRC=		${WRKDIR}/${PORTNAME}_${WIKEDVERSION}
NO_BUILD=	yes
FIND_SKIP_OPTS=	-not -name hastymail2.conf.example -not -name '*.orig'

OPTIONS=	PGSQL	"Use PostgreSQL" off \
		MYSQL	"Use MySQL" off \
		DB	"Use older pear DB (instead of MDB2)" off \
		ICONV	"Support character set conversion" off \
		MBSTRING "Support multi-byte character sets" off

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

.if defined(WITH_ICONV)
USE_PHP+=	iconv
.endif

.if defined(WITH_MBSTRING)
USE_PHP+=	mbstring
.endif

post-patch:
	@${SED} -I.orig -e "s#'/etc/hastymail2/hastymail2.rc'#'${PREFIX}/etc/hastymail2/hastymail2.rc'#" \
		${WRKSRC}/index.php
	@${SED} -I.orig -e "s# /etc/hastymail/hastyamil2.rc# ${PREFIX}/etc/hastymail2/hastyamil2.rc#" \
		${WRKSRC}/hastymail2.conf.example

pre-install:
	@${FIND} -s -d ${WRKSRC}/ -type f ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#${WWWDIR_REL}#g" > ${PLIST}
	@${ECHO_CMD} etc/hastymail2/hastymail2.conf.sample >> ${PLIST}
	@${FIND} -s -d ${WRKSRC}/ -type d ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#@dirrm ${WWWDIR_REL}#g" >> ${PLIST}
	@${ECHO_CMD} @dirrmtry etc/hastymail2 >> ${PLIST}

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} \
		| ${PAX} -rwd ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${MKDIR} ${PREFIX}/etc/hastymail2
	@${INSTALL_DATA} ${WRKSRC}/hastymail2.conf.example \
		${PREFIX}/etc/hastymail2/hastymail2.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
