# New ports collection makefile for:	syscp
# Date created:				4 April 2007
# Whom:					Janky Jay <ek@purplehat.org>
#
# $FreeBSD$
#

PORTNAME=	syscp
PORTVERSION=	1.4.2.1
PORTREVISION=	2
CATEGORIES=	sysutils www
MASTER_SITES=	http://files.syscp.org/releases/tgz/
DISTNAME=	${PORTNAME}-${PORTVERSION}

PATCH_DIST_STRIP=	-p0

MAINTAINER=	ek@purplehat.org
COMMENT=	PHP-based ISP System Control Panel

WRKSRC=		${WRKDIR}

NO_BUILD=	yes

SUB_FILES+=	pkg-message pkg-deinstall

USE_PHP=	gettext mysql session xml bcmath posix filter spl

USE_APACHE=	22

RUN_DEPENDS+=	mysql:${PORTSDIR}/databases/mysql50-server \
		dovecot:${PORTSDIR}/mail/dovecot \
		postfix:${PORTSDIR}/mail/postfix \
		proftpd:${PORTSDIR}/ftp/proftpd-mysql \
		webalizer:${PORTSDIR}/www/webalizer

post-patch:
	${FIND} ${WRKSRC}/${PORTNAME} -name '*.orig' -delete
	@cd ${WRKSRC}/${PORTNAME}/lib && ${MV} userdata.inc.php userdata.inc.php.dist

do-install:
	cd ${WRKDIR}/${PORTNAME} && \
	${FIND} . | ${CPIO} --quiet -pdm -L ${WWWDIR}

post-install:
	@if [ ! -f ${WWWDIR}/lib/userdata.inc.php ]; then \
	${CP} -p ${WWWDIR}/lib/userdata.inc.php.dist ${WWWDIR}/lib/userdata.inc.php ; fi
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} 0640 ${WWWDIR}/lib/userdata.inc.php
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} 0640 ${WWWDIR}/lib/userdata.inc.php' >> ${TMPPLIST}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
