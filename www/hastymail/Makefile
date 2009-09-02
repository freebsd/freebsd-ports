# New ports collection makefile for:	hastymail
# Date created:		2006-11-04
# Whom:			Bartlomiej Rutkowski <r@robakdesign.com>
#
# $FreeBSD$
#

PORTNAME=		hastymail
PORTVERSION=		1.5
PORTREVISION=		3
CATEGORIES=		www
MASTER_SITES=		SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast and secure yet powerful IMAP webmail

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
SUB_FILES=	pkg-message

INSTALL_DIR?=	www/${PORTNAME}
PLIST=		${WRKDIR}/pkg-plist

WANT_PHP_WEB=	yes
USE_PHP=	session imap pcre

.include <bsd.port.pre.mk>

# Don't install automatically CVS directories, patched files and the default config file.
FIND_SKIP_OPTS=	-not -name hastymail.conf-example -not -name '*.orig' \
		-not -name '*.bak' -not -path '*/CVS/*' -not -name CVS

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," \
		${WRKSRC}/lib/constant.php

pre-install:
	@${FIND} -s -d ${WRKSRC}/ -type f ${FIND_SKIP_OPTS} | \
		${SED} "s?${WRKSRC}?${INSTALL_DIR}?g" >${PLIST}
	@${FIND} -s -d ${WRKSRC}/ -type d ${FIND_SKIP_OPTS} | \
		${SED} "s?${WRKSRC}?@dirrm ${INSTALL_DIR}?g" >> ${PLIST}
	@${ECHO_CMD} etc/hastymail.conf.sample >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${INSTALL_DIR}
	@cd ${WRKSRC} && ${FIND} . ${FIND_SKIP_OPTS} | \
		${PAX} -rwd ${PREFIX}/${INSTALL_DIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${INSTALL_DIR}
	@${INSTALL_DATA} ${WRKSRC}/hastymail.conf-example \
		${PREFIX}/etc/hastymail.conf.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
