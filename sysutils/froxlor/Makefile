# Created by: Marco Steinbach <coco@executive-computing.de>
# $FreeBSD$

PORTNAME=	froxlor
DISTVERSION=	0.9.29
CATEGORIES=	sysutils www
MASTER_SITES=	http://files.froxlor.org/releases/

MAINTAINER=	coco@executive-computing.de
COMMENT=	PHP-based ISP Server Management Panel

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}

NO_BUILD=	YES

SUB_FILES+=	pkg-message pkg-deinstall

USE_PHP=	xml bcmath posix filter session ftp mysql mysqli

OPTIONS_DEFINE=	POWERDNS LIBNSS LOGROTATE MYSQLS DKIM PCNTL NLS

OPTIONS_RADIO=	WEB SMTP IMAPPOP3 FTP
OPTIONS_RADIO_WEB=	APACHE LIGHTTPD NGINX
OPTIONS_RADIO_SMTP=	POSTFIX EXIM
OPTIONS_RADIO_IMAPPOP3=	DOVECOT COURIER
OPTIONS_RADIO_FTP=	PROFTPD PUREFTPD
OPTIONS_MULTI=	WWWST
OPTIONS_MULTI_WWWST=	WEBALIZER AWSTATS

WWWST_DESC=	Web access and traffic statistics dependency
WEB_DESC=	Web server dependency
SMTP_DESC=	SMTP server dependency
IMAPPOP3_DESC=	IMAP/POP3 server dependency
FTP_DESC=	FTP server dependency
APACHE_DESC=	Apache (2.2) as HTTP/HTTPS server
LIGHTTPD_DESC=	Lighttpd as HTTP/HTTPS server
NGINX_DESC=	Nginx as HTTP/HTTPS server
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
PCNTL_DESC=	Use php-pcntl (speeds up statistics creation)
LIBNSS_DESC=	Libnss-mysql for authentication
WEBALIZER_DESC=	Webalizer (small, fast, static result pages)
AWSTATS_DESC=	Awstats (more fancy, dynamic and static result pages)
LOGROTATE_DESC=	Logrotate for log rotation
MYSQLS_DESC=	Depend on MySQL server
NLS_DESC=	Enable NLS support (required for webFTP frontend)

OPTIONS_DEFAULT=	APACHE MYSQLS POSTFIX DOVECOT PROFTPD WEBALIZER MYSQLS PCNTL NLS

POSTFIX_RUN_DEPENDS=	postfix:${PORTSDIR}/mail/postfix

EXIM_RUN_DEPENDS=	exim:${PORTSDIR}/mail/exim

DKIM_RUN_DEPENDS=	opendkim:${PORTSDIR}/mail/opendkim

DOVECOT_RUN_DEPENDS=	dovecot:${PORTSDIR}/mail/dovecot

COURIER_RUN_DEPENDS=	courier:${PORTSDIR}/mail/courier

PROFTPD_RUN_DEPENDS=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:${PORTSDIR}/databases/proftpd-mod_sql_mysql

PUREFTPD_RUN_DEPENDS=	pure-ftpd:${PORTSDIR}/ftp/pure-ftpd

POWERDNS_RUN_DEPENDS=	powerdns:${PORTSDIR}/dns/powerdns

LIBNSS_RUN_DEPENDS=	${LOCALBASE}/lib/nss_mysql.so:${PORTSDIR}/net/libnss-mysql

WEBALIZER_RUN_DEPENDS=	webalizer:${PORTSDIR}/www/webalizer

AWSTATS_RUN_DEPENDS=	awstats>=6.8:${PORTSDIR}/www/awstats

LOGROTATE_RUN_DEPENDS=	logrotate:${PORTSDIR}/sysutils/logrotate

LIGHTTPD_RUN_DEPENDS=	lighttpd:${PORTSDIR}/www/lighttpd

NGINX_RUN_DEPENDS=	nginx:${PORTSDIR}/www/nginx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22
.endif

.if ${PORT_OPTIONS:MMYSQLS}
USE_MYSQL=	server
.endif

.if ${PORT_OPTIONS:MPCNTL}
USE_PHP+=	pcntl
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext:run
USE_PHP+=	gettext
.endif

do-install:
	cd ${WRKDIR}/${PORTNAME} && \
	${FIND} . ! -name .gitignore | \
	${CPIO} --quiet -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
