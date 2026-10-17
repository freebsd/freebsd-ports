PORTNAME=	froxlor
DISTVERSION=	2.3.15
CATEGORIES=	sysutils www
MASTER_SITES=	https://files.froxlor.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP-based ISP Server Management Panel
WWW=		https://www.froxlor.org/

LICENSE=	GPLv2

USES=		cpe php:cli shebangfix
USE_PHP=	bcmath curl filter ftp pdo_mysql posix session xml zip

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-deinstall pkg-message
SUB_LIST=	PORTNAME=${PORTNAME} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}
NO_WRKSUBDIR=	yes
PLIST_SUB=	${SUB_LIST}

OPTIONS_DEFINE=	DKIM LIBNSS LOGROTATE MYSQLS NLS PCNTL
OPTIONS_DEFAULT=	APACHE DOVECOT2 MYSQLS PCNTL POSTFIX PROFTPD WEBALIZER

OPTIONS_MULTI=		WWWST
OPTIONS_MULTI_WWWST=	AWSTATS WEBALIZER
OPTIONS_RADIO=		DNS FTP IMAPPOP3 SMTP WEB
OPTIONS_RADIO_DNS=	ISCDNS POWERDNS
OPTIONS_RADIO_FTP=	PROFTPD PUREFTPD
OPTIONS_RADIO_IMAPPOP3=	COURIER DOVECOT2
OPTIONS_RADIO_SMTP=	EXIM POSTFIX
OPTIONS_RADIO_WEB=	APACHE LIGHTTPD NGINX

APACHE_DESC=	Apache as HTTP/HTTPS server
AWSTATS_DESC=	Awstats (more fancy, dynamic and static result pages)
COURIER_DESC=	Courier as IMAP/POP3 server
DKIM_DESC=	OpenDKIM for DomainKeys Identified Mail
DNS_DESC=	DNS server dependency
DOVECOT2_DESC=	Dovecot 2.x as IMAP/POP3 server
EXIM_DESC=	Exim as SMTP server
FTP_DESC=	FTP server dependency
IMAPPOP3_DESC=	IMAP/POP3 server dependency
ISCDNS_DESC=	SC BIND 9.20 from ports as DNS server
LIBNSS_DESC=	Libnss-mysql for authentication
LIGHTTPD_DESC=	Lighttpd as HTTP/HTTPS server
LOGROTATE_DESC=	Logrotate for log rotation
MYSQLS_DESC=	Depend on MySQL server
NGINX_DESC=	Nginx as HTTP/HTTPS server
NLS_DESC=	Enable NLS support (required for webFTP frontend)
PCNTL_DESC=	Use php-pcntl (speeds up statistics creation)
POSTFIX_DESC=	Postfix as SMTP server
POWERDNS_DESC=	Powerdns as DNS server
PROFTPD_DESC=	ProFTPd as FTP server
PUREFTPD_DESC=	Pure-FTPd as FTP server
SMTP_DESC=	SMTP server dependency
WEBALIZER_DESC=	Webalizer (small, fast, static result pages)
WEB_DESC=	Web server dependency
WWWST_DESC=	Web access and traffic statistics dependency

APACHE_USES=	apache php:mod

AWSTATS_RUN_DEPENDS=	awstats>=6.8:www/awstats

COURIER_RUN_DEPENDS=	courier:mail/courier

DKIM_RUN_DEPENDS=	opendkim:mail/opendkim

DOVECOT2_RUN_DEPENDS=	dovecot>=2:mail/dovecot

EXIM_RUN_DEPENDS=	exim:mail/exim

ISCDNS_RUN_DEPENDS=	bind920>=9.20.0:dns/bind920

LIBNSS_RUN_DEPENDS=	${LOCALBASE}/lib/nss_mysql.so:net/libnss-mysql

LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd

LOGROTATE_RUN_DEPENDS=	logrotate:sysutils/logrotate

MYSQLS_USES=	mysql:server

NGINX_RUN_DEPENDS=	nginx:www/nginx

NLS_USES=	gettext-runtime
NLS_USE=	PHP=gettext

PCNTL_USE=	PHP=pcntl

POSTFIX_RUN_DEPENDS=	postfix:mail/postfix

POWERDNS_RUN_DEPENDS=	pdns_control:dns/powerdns

PROFTPD_RUN_DEPENDS=	${LOCALBASE}/libexec/proftpd/mod_sql_mysql.so:databases/proftpd-mod_sql_mysql

PUREFTPD_RUN_DEPENDS=	pure-ftpd:ftp/pure-ftpd

WEBALIZER_RUN_DEPENDS=	webalizer:www/webalizer

do-install:
	cd ${WRKSRC}/${PORTNAME} && \
	${FIND} . ! -name .gitignore | \
	${CPIO} --quiet -pdm ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
