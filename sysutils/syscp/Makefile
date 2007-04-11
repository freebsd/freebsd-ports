# New ports collection makefile for:	syscp
# Date created:				4 April 2007
# Whom:					Janky Jay <ek@purplehat.org>
#
# $FreeBSD$
#

PORTNAME=	syscp
PORTVERSION=	1.2.16
CATEGORIES=	sysutils www
MASTER_SITES=	http://canada.syscp.org/releases/tgz/ \
		http://france.syscp.org/releases/tgz/ \
		http://nuernburg.files.syscp.org/releases/tgz/
DISTNAME=	${PORTNAME}-${PORTVERSION}

PATCH_DIST_STRIP=	-p0

MAINTAINER=	ek@purplehat.org
COMMENT=	PHP-based ISP System Control Panel

WRKSRC=		${WRKDIR}

NO_BUILD=	yes

SUB_FILES+=	pkg-message

USE_PHP=	gettext mysql pcre session xml

USE_APACHE=	22

RUN_DEPENDS+=	mysql:${PORTSDIR}/databases/mysql50-server \
		httpd:${PORTSDIR}/www/apache22 \
		dovecot:${PORTSDIR}/mail/dovecot \
		postfix:${PORTSDIR}/mail/postfix \
		proftpd:${PORTSDIR}/ftp/proftpd-mysql

post-patch:
		${FIND} ${WRKSRC}/${PORTNAME} -name '*.orig' -delete

do-install:
		cd ${WRKDIR}/${PORTNAME} && \
		${FIND} . | ${CPIO} --quiet -pdm -L ${PREFIX}/www/${PORTNAME}

post-install:
		@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/www/${PORTNAME}
		${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
