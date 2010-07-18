# New ports collection makefile for:	Prevantage NGMP
# Date created:		July 28 2008
# Whom:			Luke Jee <lukejee@gmail.com>
#
# $FreeBSD$

PORTNAME=	ngmp
PORTVERSION=	0.1.4
PORTREVISION=	6
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.prevantage.com/releases/ \
		ftp://ftp2.prevantage.com/releases/
DISTNAME=	ngmp-for-freebsd-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A full AJAX based web app for messaging and collaboration

RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache22 \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/pdo_pgsql.so:${PORTSDIR}/databases/php5-pdo_pgsql \
		${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim \
		${LOCALBASE}/bin/imapd:${PORTSDIR}/mail/courier-imap \
		${LOCALBASE}/lib/courier-authlib/libauthpgsql.so:${PORTSDIR}/databases/courier-authlib-pgsql \
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/fileinfo.so:${PORTSDIR}/sysutils/pecl-fileinfo\
		${LOCALBASE}/lib/php/${PHP_EXT_DIR}/ZendExtensionManager.so:${PORTSDIR}/devel/ZendOptimizer \
		${LOCALBASE}/sbin/clamd:${PORTSDIR}/security/clamav \
		${LOCALBASE}/bin/dspam:${PORTSDIR}/mail/dspam \
		${LOCALBASE}/share/pear/Mail/mimeDecode.php:${PORTSDIR}/mail/pear-Mail_mimeDecode \
		${LOCALBASE}/share/pear/Net/SMTP.php:${PORTSDIR}/net/pear-Net_SMTP \
		${LOCALBASE}/share/pear/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime \
		${LOCALBASE}/share/pear/Mail/RFC822.php:${PORTSDIR}/mail/pear-Mail \
		${LOCALBASE}/share/pear/Benchmark/Timer.php:${PORTSDIR}/benchmarks/pear-Benchmark \
		${LOCALBASE}/share/ZendFramework:${PORTSDIR}/www/zend-framework \
		${LOCALBASE}/share/smarty/Smarty.class.php:${PORTSDIR}/www/smarty \
		${LOCALBASE}/www/tinymce:${PORTSDIR}/www/tinymce

BROKEN=		does not compile
DEPRECATED=		${BROKEN} and no longer supported by upstream
EXPIRATION_DATE=	2010-08-18

NO_BUILD=	yes

WANT_PHP_WEB=	yes
PHP_VER=	5
USE_PHP=	session mbstring iconv pcre pdo pdo_sqlite imap json hash

USE_PGSQL=		yes

SUB_FILES=	pkg-message

do-install:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}
	@${CHMOD} -R 755 ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' \
		>> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${CHMOD} -R 755 ${WWWDIR}' \
		>> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
