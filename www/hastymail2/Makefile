# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

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

CONFLICTS=	hastymail-* hastymail2-devel-*

PLIST=		${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	ctype pcre session xml

WIKEDVERSION=	1_1
WRKSRC=		${WRKDIR}/${PORTNAME}_${WIKEDVERSION}
NO_BUILD=	yes
FIND_SKIP_OPTS=	-not -name hastymail2.conf.example -not -name '*.orig'

OPTIONS_DEFINE=	PGSQL MYSQL DB ICONV MBSTRING

DB_DESC=	Use older pear DB (instead of MDB2)
MBSTRING_DESC=	Support multi-byte character sets

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/mysql.php:${PORTSDIR}/databases/pear-MDB2_Driver_mysql
.endif
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.if ! ${PORT_OPTIONS:MDB}
RUN_DEPENDS+=	${LOCALBASE}/share/pear/MDB2/Driver/pgsql.php:${PORTSDIR}/databases/pear-MDB2_Driver_pgsql
.endif
.endif

.if ${PORT_OPTIONS:MDB} && (${PORT_OPTIONS:MMYSQL} || ${PORT_OPTIONS:MPGSQL})
RUN_DEPENDS+=	${LOCALBASE}/share/pear/DB.php:${PORTSDIR}/databases/pear-DB
.endif

.if ${PORT_OPTIONS:MICONV}
USE_PHP+=	iconv
.endif

.if ${PORT_OPTIONS:MMBSTRING}
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

.include <bsd.port.mk>
