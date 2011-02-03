# New ports collection makefile for:	froxlor
# Date created:		2010-10-13
# Whom:			Marco Steinbach <coco@executive-computing.de>
#
# $FreeBSD$
#

PORTNAME=	froxlor
PORTVERSION=	0.9.17
CATEGORIES=	sysutils www
MASTER_SITES=	http://files.froxlor.org/releases/

MAINTAINER=	coco@executive-computing.de
COMMENT=	PHP-based ISP Server Management Panel

WRKSRC=		${WRKDIR}

NO_BUILD=	YES

SUB_FILES+=	pkg-message pkg-deinstall

USE_PHP=	xml bcmath posix filter

OPTIONS=	APACHE "Use Apache (2.2) as http server" On \
		MYSQL "Use MySQL as database server" On \
		POSTFIX "Use Postfix as smtp server" On \
		DKIM "Use Dkim-milter" Off \
		DOVECOT "Use Dovecot as imap/pop3 server" On \
		PROFTPD "Use Proftpd-mysql as ftp server (implies MySQL)" On \
		POWERDNS "Use Powerdns as dns server" Off \
		LIBNSS "Use Libnss-mysql for authentication (impl. MySQL)" Off \
		WEBALIZER "Use webalizer" On \
		AWSTATS "Use awstats" Off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	22
.endif

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if !defined(WITHOUT_POSTFIX)
RUN_DEPENDS+=	postfix:${PORTSDIR}/mail/postfix
.endif

.if defined(WITH_DKIM)
RUN_DEPENDS+=	dkim-milter:${PORTSDIR}/mail/dkim-milter
.endif

.if !defined(WITHOUT_DOVECOT)
RUN_DEPENDS+=	dovecot:${PORTSDIR}/mail/dovecot
.endif

.if !defined(WITHOUT_PROFTPD)
RUN_DEPENDS+=	proftpd:${PORTSDIR}/ftp/proftpd-mysql
.endif

.if defined(WITH_POWERDNS)
RUN_DEPENDS+=	powerdns:${PORTSDIR}/dns/powerdns
.endif

.if defined(WITH_LIBNSS)
RUN_DEPENDS+=	libnss-mysql:${PORTSDIR}/net/libnss-mysql
.endif

.if !defined(WITHOUT_WEBALIZER)
RUN_DEPENDS+=	webalizer:${PORTSDIR}/www/webalizer
.endif

.if defined(WITH_AWSTATS)
RUN_DEPENDS+=	awstats:${PORTSDIR}/www/awstats
.endif

do-install:
	cd ${WRKDIR}/${PORTNAME} && \
	${FIND} . | ${CPIO} --quiet -pdm -L ${WWWDIR}

post-install:
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
