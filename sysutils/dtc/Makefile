# Ports collection makefile for:        dtc
# Date created:                 1 December 2003
# Whom:                         Frederic Cambus & Thomas Goirand
#
# $FreeBSD$
#

PORTNAME=	dtc
PORTVERSION=	0.12.0.6
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.gplhost.com/pub/dtc/bsd/

MAINTAINER=	thomas@goirand.fr
COMMENT=	A hosting web GUI for admin and accounting apache/named/proftpd/qmail

RUN_DEPENDS=	${LOCALBASE}/share/pear/Crypt/CBC.php:${PORTSDIR}/security/pear-Crypt_CBC \
		${LOCALBASE}/libexec/proftpd:${PORTSDIR}/ftp/proftpd-mysql \
		${LOCALBASE}/libexec/apache2/mod_log_sql.so:${PORTSDIR}/www/mod_log_sql2 \
		${LOCALBASE}/bin/webalizer:${PORTSDIR}/www/webalizer \
		${QMAIL_DIR}/bin/qmail-start:${PORTSDIR}/mail/qmail

USE_PHP=	session mysql sockets gd
QMAIL_DIR?=	/var/qmail

DTCROOT?=	www/dtc
DTCDIR=		${PREFIX}/${DTCROOT}
PLIST_SUB+=	DTCROOT="${DTCROOT}"

.if defined(WITH_APACHE2)
IGNORE=		Untested
.endif

NO_BUILD=	yes
USE_MYSQL=	yes

do-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},;\
		s,%%LOCALBASE%%,${LOCALBASE},;\
		s,%%QMAIL_DIR%%,${QMAIL_DIR},' \
		${FILESDIR}/dtc-install.in > ${WRKDIR}/dtc-install
	@${SED} -e 's,%%PREFIX%%,${PREFIX},;\
		s,%%LOCALBASE%%,${LOCALBASE},;\
		s,%%QMAIL_DIR%%,${QMAIL_DIR},' \
		${FILESDIR}/dtc-deinstall.in > ${WRKDIR}/dtc-deinstall

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-install ${PREFIX}/sbin/dtc-install
	@${INSTALL_SCRIPT} ${WRKDIR}/dtc-deinstall ${PREFIX}/sbin/dtc-deinstall
	@${MKDIR} ${DTCDIR}
	@cd ${WRKSRC}/dtc ; ${TAR} cfp - . | ${TAR} xfp - -C ${DTCDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
