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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Apache 1.3 webserver with SSL/TLS functionality

LIB_DEPENDS=	mm.13:${PORTSDIR}/devel/mm

MASTER_SITES_MODSSL=	http://www.modssl.org/source/ \
		ftp://ftp.modssl.org/source/ \
		ftp://ftp.pca.dfn.de/pub/tools/net/mod_ssl/ \
		ftp://ftp.ecrc.net/pub/security/mod_ssl/ \
		ftp://ftp.nvg.ntnu.no/pub/unix/mod_ssl/ \
		ftp://ftp.ulpgc.es/pub/mod_ssl/ \
		ftp://glock.missouri.edu/pub/mod_ssl/ \
		ftp://ftp.infoscience.co.jp/pub/Crypto/SSL/mod_ssl/ \
		ftp://ftp.uni-trier.de/pub/unix/security/mod_ssl/ \
		ftp://ftp.blatzheim.com/pub/mod_ssl/ \
		ftp://ftp.fu-berlin.de/unix/security/mod_ssl/ \
		ftp://ftp.ntrl.net/pub/mirror/ralfsw/mod_ssl/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/www/mod_ssl/source,}

.include <bsd.port.pre.mk>

VERSION_APACHE=	1.3.28
VERSION_MODSSL=	2.8.15

DATADIR=	${PREFIX}/www
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

USE_PERL5=	yes
HAS_CONFIGURE=	yes
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

.include "${PORTSDIR}/security/openssl/bsd.openssl.mk"

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
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "  WITH_APACHE_SUEXEC=yes	enable the suEXEC feature"
	@${ECHO} "				[default is no]"
	@${ECHO} "  APACHE_SUEXEC_CALLER=user	set the suEXEC username of the allowed caller"
	@${ECHO} "				[default is www]"
	@${ECHO} "  APACHE_SUEXEC_DOCROOT=dir	set the suEXEC root directory"
	@${ECHO} "				[default is ${DOCUMENT_ROOT}]"
	@${ECHO} "  APACHE_SUEXEC_LOG=file	set the suEXEC logfile"
	@${ECHO} "				[default is /var/log/httpd-suexec.log]"
	@${ECHO} "  APACHE_SUEXEC_USERDIR=dir	set the suEXEC user subdirectory"
	@${ECHO} "				[default is public_html]"
	@${ECHO} "  APACHE_SUEXEC_UIDMIN=uid	set the suEXEC minimal allowed UID"
	@${ECHO} "				[default is 1000]"
	@${ECHO} "  APACHE_SUEXEC_GIDMIN=gid	set the suEXEC minimal allowed GID"
	@${ECHO} "				[default is 1000]"
	@${ECHO} "  APACHE_SUEXEC_SAFE_PATH=path	set the suEXEC safe PATH"
	@${ECHO} "				[default is /bin:/usr/bin:${PREFIX}/bin]"
	@${ECHO} "  APACHE_SUEXEC_UMASK=umask	set the umask for the suEXEC'd script"
	@${ECHO} "				[default is inherited from the Apache process]"
	@${ECHO} ""
	@${ECHO} "  APACHE_HARD_SERVER_LIMIT=nr	Maximum number of Apache processes."
	@${ECHO} "				[default is 512]"
	@${ECHO} "  APACHE_FD_SETSIZE=nr		Maximum number of descriptors."
	@${ECHO} "				[default is 1024]"
	@${ECHO} ""
	@${ECHO} "  APACHE_BUFFERED_LOGS=yes	Log entries are buffered before writing."
	@${ECHO} "				Writes may not be atomic, entries from multiple"
	@${ECHO} "				children could become mixed together and your"
	@${ECHO} "				web stats may be inaccurate."
	@${ECHO} "				[default is no]"
	@${ECHO} "  APACHE_PERF_TUNING=yes	CFLAGS optimization."
	@${ECHO} "				This setting may produce broken code and thus"
	@${ECHO} "				is not recommended for production servers."
	@${ECHO} "				[default is no]"
	@${ECHO} ""

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
	@${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.post.mk>
