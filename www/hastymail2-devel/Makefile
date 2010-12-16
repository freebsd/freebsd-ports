# New ports collection makefile for:	hastymail
# Date created:		2006-11-04
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=	hastymail2
PORTVERSION=	1.1
PORTEPOCH=	1
CATEGORIES=	www mail
MASTER_SITES=	SF/hastymail/Hastymail2%20Stable%20Releases/Hastymail2%201.01/
DISTNAME=	hastymail2_1_01

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Small, fast and secure yet powerful IMAP webmail

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
SUB_FILES=	pkg-message

LICSENSE=	GPLv2

INSTALL_DIR?=	www/${PORTNAME}
PLIST=          ${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	session imap pcre

WIKEDVERSION=	1_01
WRKSRC=		${WRKDIR}/${PORTNAME}_${WIKEDVERSION}
NO_BUILD=	yes
FIND_SKIP_OPTS=	-not -name hastymail2.conf.example -not -name '*.orig'

.include <bsd.port.pre.mk>

post-patch:
	@${SED} -I.orig -e "s#'/etc/hastymail2/hastymail2.rc'#'${PREFIX}/etc/hastymail2/hastymail2.rc'#" \
		${WRKSRC}/index.php
	@${SED} -I.orig -e "s# /etc/hastymail/hastyamil2.rc# ${PREFIX}/etc/hastymail2/hastyamil2.rc#" \
		${WRKSRC}/hastymail2.conf.example

pre-install:
	@${FIND} -s -d ${WRKSRC}/ -type f ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#${INSTALL_DIR}#g" > ${PLIST}
	@${ECHO_CMD} etc/hastymail2/hastymail2.conf.sample >> ${PLIST}
	@${FIND} -s -d ${WRKSRC}/ -type d ${FIND_SKIP_OPTS} \
		| ${SED} "s#${WRKSRC}#@dirrm ${INSTALL_DIR}#g" >> ${PLIST}
	@${ECHO_CMD} @dirrmtry etc/hastymail2 >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALL_DIR}
	@cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} \
		| ${PAX} -rwd ${PREFIX}/${INSTALL_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${INSTALL_DIR}
	@${MKDIR} ${PREFIX}/etc/hastymail2
	@${INSTALL_DATA} ${WRKSRC}/hastymail2.conf.example \
		${PREFIX}/etc/hastymail2/hastymail2.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
