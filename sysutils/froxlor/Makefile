# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	froxlor
DISTVERSION=	0.9.27
CATEGORIES=	sysutils www
MASTER_SITES=	http://files.froxlor.org/releases/

MAINTAINER=	coco@executive-computing.de
COMMENT=	PHP-based ISP Server Management Panel

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}

NO_BUILD=	YES

SUB_FILES+=	pkg-message pkg-deinstall

USE_PHP=	xml bcmath posix filter session ftp mysql mysqli gettext

USE_GETTEXT=	RUN

OPTIONS_DEFINE=	POWERDNS LIBNSS LOGROTATE MYSQLS DKIM

OPTIONS_SINGLE=	WEB SMTP IMAPPOP3 FTP
OPTIONS_SINGLE_WEB=	APACHE LIGHTTPD NGINX
OPTIONS_SINGLE_SMTP=	POSTFIX EXIM
OPTIONS_SINGLE_IMAPPOP3=	DOVECOT COURIER
OPTIONS_SINGLE_FTP=	PROFTPD PUREFTPD
OPTIONS_MULTI=	WWWST
OPTIONS_MULTI_WWWST=	WEBALIZER AWSTATS

APACHE_DESC=	Apache (2.2) as HTTP server
LIGHTTPD_DESC=	Lighttpd as HTTP server
NGINX_DESC=	Nginx as HTTP server
MYSQLC_DESC=	MySQL database client only
MYSQLS_DESC=	MySQL database server and client
POSTFIX_DESC=	Postfix as SMTP server
EXIM_DESC=	Exim as SMTP server
DKIM_DESC=	OpenDKIM for DomainKeys Identified Mail
DOVECOT_DESC=	Dovecot as IMAP/POP3 server
COURIER_DESC=	Courier as IMAP/POP3 server
PROFTPD_DESC=	ProFTPd as FTP server
PUREFTPD_DESC=	Pure-FTPd as FTP server
POWERDNS_DESC=	Powerdns as DNS server
LIBNSS_DESC=	Libnss-mysql for authentication
WEBALIZER_DESC=	Webalizer for web statistics
AWSTATS_DESC=	Awstats for web statistics
LOGROTATE_DESC=	Logrotate for log rotation
MYSQLS_DESC=	Install/depend on MySQL server

OPTIONS_DEFAULT=	APACHE MYSQLS POSTFIX DOVECOT PROFTPD WEBALIZER MYSQLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if ${PORT_OPTIONS:MNGINX}
RUN_DEPENDS+=	nginx:${PORTSDIR}/www/nginx
.endif

.if ${PORT_OPTIONS:MMYSQLS}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MPOSTFIX}
RUN_DEPENDS+=	postfix:${PORTSDIR}/mail/postfix
.endif

.if ${PORT_OPTIONS:MEXIM}
RUN_DEPENDS+=	exim:${PORTSDIR}/mail/exim
.endif

.if ${PORT_OPTIONS:MDKIM}
RUN_DEPENDS+=	opendkim:${PORTSDIR}/mail/opendkim
.endif

.if ${PORT_OPTIONS:MDOVECOT}
RUN_DEPENDS+=	dovecot:${PORTSDIR}/mail/dovecot
.endif

.if ${PORT_OPTIONS:MCOURIER}
RUN_DEPENDS+=	courier:${PORTSDIR}/mail/courier
.endif

.if ${PORT_OPTIONS:MPROFTPD}
RUN_DEPENDS+=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:${PORTSDIR}/databases/proftpd-mod_sql_mysql
.endif

.if ${PORT_OPTIONS:MPUREFTPD}
RUN_DEPENDS+=	pure-ftpd:${PORTSDIR}/ftp/pure-ftpd
.endif

.if ${PORT_OPTIONS:MPOWERDNS}
RUN_DEPENDS+=	powerdns:${PORTSDIR}/dns/powerdns
.endif

.if ${PORT_OPTIONS:MLIBNSS}
RUN_DEPENDS+=	${LOCALBASE}/lib/nss_mysql.so:${PORTSDIR}/net/libnss-mysql
.endif

.if ${PORT_OPTIONS:MWEBALIZER}
RUN_DEPENDS+=	webalizer:${PORTSDIR}/www/webalizer
.endif

.if ${PORT_OPTIONS:MAWSTATS}
RUN_DEPENDS+=	awstats>=6.8:${PORTSDIR}/www/awstats
.endif

.if ${PORT_OPTIONS:MLOGROTATE}
RUN_DEPENDS+=	logrotate:${PORTSDIR}/sysutils/logrotate
.endif

do-install:
	cd ${WRKDIR}/${PORTNAME} && \
	${FIND} . ! -name .gitignore | \
	${CPIO} --quiet -pdm -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
