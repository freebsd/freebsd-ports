# New ports collection makefile for:	Apache + mod_ssl
# Date created:		Sat Aug 22 12:00:00 CDT 1998
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	apache+mod_ssl
PORTVERSION=	${VERSION_APACHE}+${VERSION_MODSSL}
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		${MASTER_SITES_MODSSL:S/$/:modssl/}
DISTNAME=	apache_${VERSION_APACHE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE}${EXTRACT_SUFX}:modssl

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	The Apache 1.3 webserver with SSL/TLS functionality

LIB_DEPENDS=	mm.13:${PORTSDIR}/devel/mm
PATCH_DEPENDS=	${BUILD_DEPENDS}

CONFLICTS?=	apache+ipv6-1.* apache+ssl-1.* apache-1.* apache-2.* \
		apache_fp-1.* caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.* w3c-httpd-3.*
VERSION_APACHE=	1.3.28
VERSION_MODSSL=	2.8.15
USE_OPENSSL=	yes
HAS_CONFIGURE=	yes
USE_PERL5_BUILD=	yes
MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mod_ssl/source,}

.include <bsd.port.pre.mk>

DATADIR=	${PREFIX}/www
DOCSDIR=	${PREFIX}/share/doc/apache
DOCUMENT_ROOT=	${DATADIR}/data

.if defined(WITH_APACHE_SUEXEC) && ${WITH_APACHE_SUEXEC} == yes

APACHE_SUEXEC_CALLER?=www
APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=/var/log/httpd-suexec.log
APACHE_SUEXEC_USERDIR?=public_html
APACHE_SUEXEC_UIDMIN?=1000
APACHE_SUEXEC_GIDMIN?=1000
APACHE_SUEXEC_SAFE_PATH?=/bin:/usr/bin:${PREFIX}/bin

SUEXEC_CONF=	--enable-suexec \
		--suexec-caller=${APACHE_SUEXEC_CALLER} \
		--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
		--suexec-logfile=${APACHE_SUEXEC_LOG} \
		--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
		--suexec-uidmin=${APACHE_SUEXEC_UIDMIN} \
		--suexec-gidmin=${APACHE_SUEXEC_GIDMIN} \
		--suexec-safepath=${APACHE_SUEXEC_SAFE_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=	SUB_SUEXEC=""
SUEXEC_MAN=	suexec.8

.else   # !SUEXEC

SUEXEC_CONF=
PLIST_SUB+=	SUB_SUEXEC="@comment "
SUEXEC_MAN=

.endif  # !SUEXEC

CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		--enable-module=ssl \
		--enable-module=define \
		${SUEXEC_CONF}

.if defined(APACHE_HARD_SERVER_LIMIT)
HARD_SERVER_LIMIT=-DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
HARD_SERVER_LIMIT=-DHARD_SERVER_LIMIT=512
.endif

OPTIM=		${HARD_SERVER_LIMIT} \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"${PREFIX}/bin:/bin:/usr/bin\\" \
		-DACCEPT_FILTER_NAME=\\"httpready\\"

.if defined(APACHE_FD_SETSIZE)
OPTIM+=		-DFD_SETSIZE=${APACHE_FD_SETSIZE}
.else
OPTIM+=		-DFD_SETSIZE=1024
.endif

.if defined(APACHE_BUFFERED_LOGS) && ${APACHE_BUFFERED_LOGS} == yes
OPTIM+=		-DBUFFERED_LOGS
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == yes
CFLAGS+=	-O3
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		SSL_BASE='${OPENSSLBASE}' \
		EAPI_MM='SYSTEM' \
		PATH="${PREFIX}/bin:${PATH}"

INSTALL_TARGET=	install-quiet

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
	${SUEXEC_MAN}

TYPE=	test
CRT=
KEY=

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  WITH_APACHE_SUEXEC=yes	enable the suEXEC feature"
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} "  APACHE_SUEXEC_CALLER=user	set the suEXEC username of the allowed caller"
	@${ECHO_MSG} "				[default is www]"
	@${ECHO_MSG} "  APACHE_SUEXEC_DOCROOT=dir	set the suEXEC root directory"
	@${ECHO_MSG} "				[default is ${DOCUMENT_ROOT}]"
	@${ECHO_MSG} "  APACHE_SUEXEC_LOG=file	set the suEXEC logfile"
	@${ECHO_MSG} "				[default is /var/log/httpd-suexec.log]"
	@${ECHO_MSG} "  APACHE_SUEXEC_USERDIR=dir	set the suEXEC user subdirectory"
	@${ECHO_MSG} "				[default is public_html]"
	@${ECHO_MSG} "  APACHE_SUEXEC_UIDMIN=uid	set the suEXEC minimal allowed UID"
	@${ECHO_MSG} "				[default is 1000]"
	@${ECHO_MSG} "  APACHE_SUEXEC_GIDMIN=gid	set the suEXEC minimal allowed GID"
	@${ECHO_MSG} "				[default is 1000]"
	@${ECHO_MSG} "  APACHE_SUEXEC_SAFE_PATH=path	set the suEXEC safe PATH"
	@${ECHO_MSG} "				[default is /bin:/usr/bin:${PREFIX}/bin]"
	@${ECHO_MSG} "  APACHE_SUEXEC_UMASK=umask	set the umask for the suEXEC'd script"
	@${ECHO_MSG} "				[default is inherited from the Apache process]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  APACHE_HARD_SERVER_LIMIT=nr	Maximum number of Apache processes."
	@${ECHO_MSG} "				[default is 512]"
	@${ECHO_MSG} "  APACHE_FD_SETSIZE=nr		Maximum number of descriptors."
	@${ECHO_MSG} "				[default is 1024]"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  APACHE_BUFFERED_LOGS=yes	Log entries are buffered before writing."
	@${ECHO_MSG} "				Writes may not be atomic, entries from multiple"
	@${ECHO_MSG} "				children could become mixed together and your"
	@${ECHO_MSG} "				web stats may be inaccurate."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} "  APACHE_PERF_TUNING=yes	CFLAGS optimization."
	@${ECHO_MSG} "				This setting may produce broken code and thus"
	@${ECHO_MSG} "				is not recommended for production servers."
	@${ECHO_MSG} "				[default is no]"
	@${ECHO_MSG} ""

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/apache.sh \
		> ${WRKSRC}/apache.sh

pre-patch:
	@cd ${WRKDIR}/mod_ssl-${VERSION_MODSSL}-${VERSION_APACHE} \
	&& ${ECHO_MSG} "===>  Applying mod_ssl-${VERSION_MODSSL} extension" \
	&& ./configure --with-apache=../${DISTNAME} --expert

post-patch:
	@${PERL} -pi -e 's|-print|-print0|;s|xargs|xargs -0|' \
		${WRKSRC}/Makefile.tmpl
	@${PERL} -pi -e "s|SSL_LDFLAGS=''|SSL_LDFLAGS='${OPENSSL_LDFLAGS}'|" \
		${WRKSRC}/src/modules/ssl/libssl.module
	@cd ${WRKSRC} \
	&& ${FIND} . -type f -name "*.orig" -print | ${XARGS} ${RM} -f

post-build:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Dummy Certificate for Server (SnakeOil)" \
	&& ${ECHO_MSG} "      [use 'make certificate' to create a real one]" \
	&& ${MAKE} certificate TYPE=dummy >/dev/null 2>&1

certificate:
	@cd ${WRKSRC} \
	&& ${ECHO_MSG} "===>  Creating Test Certificate for Server" \
	&& ${MAKE} certificate TYPE=${TYPE} CRT=${CRT} KEY=${KEY}

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
