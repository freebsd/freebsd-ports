PORTNAME=	freeipa-server
DISTVERSION=	4.13.1
CATEGORIES=	net
MASTER_SITES=	https://releases.pagure.org/freeipa/
DISTNAME=	freeipa-${DISTVERSION}

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	FreeIPA server
WWW=		https://www.freeipa.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/getopt:misc/getopt \
		${LOCALBASE}/libdata/pkgconfig/dirsrv.pc:net/389-ds-base \
		${LOCALBASE}/libdata/pkgconfig/sss_idmap.pc:security/sssd2 \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}lesscpy>0:www/py-lesscpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rjsmin>0:archivers/py-rjsmin@${PY_FLAVOR} \
		bash:shells/bash \
		samba416>=0:net/samba416

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libini_config.so:devel/ding-libs \
		libintl.so:devel/gettext-runtime \
		libjansson.so:devel/jansson \
		libkrad.so:security/krb5 \
		libnspr4.so:devel/nspr \
		libpopt.so:devel/popt \
		libpwquality.so:security/libpwquality \
		libsasl2.so:security/cyrus-sasl2 \
		libsss_nss_idmap.so:security/sssd2 \
		libtalloc.so:devel/talloc \
		libtevent.so:devel/tevent \
		libunistring.so:devel/libunistring \
		libuuid.so:misc/libuuid \
		libxmlrpc.so:net/xmlrpc-c

RUN_DEPENDS=	${LOCALBASE}/libexec/apache24/mod_auth_gssapi.so:www/freeipa-auth-gssapi \
		${LOCALBASE}/libexec/apache24/mod_deflate.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_expires.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_lookup_identity.so:www/mod_lookup_identity \
		${LOCALBASE}/libexec/apache24/mod_proxy.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_proxy_ajp.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_proxy_http.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_rewrite.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_session.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_session_cookie.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_ssl.so:www/apache24 \
		${LOCALBASE}/libexec/apache24/mod_wsgi.so:www/mod_wsgi@${PY_FLAVOR} \
		${LOCALBASE}/sbin/certmonger:security/certmonger \
		${LOCALBASE}/sbin/gssproxy:security/gssproxy \
		${LOCALBASE}/sbin/httpd:www/apache24 \
		${LOCALBASE}/sbin/oddjobd:sysutils/oddjob \
		${PYTHON_PKGNAMEPREFIX}dbus>0:devel/py-dbus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gssapi>0:security/py-gssapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>0:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jwcrypto>0:security/py-jwcrypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kdcproxy>0:security/py-kdcproxy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lib389>=0:net/py-lib389@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-augeas>0:textproc/py-python-augeas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		389-ds-base>=0:net/389-ds-base \
		dogtag-pki>0:security/dogtag-pki \
		samba416>=0:net/samba416 \
		slapi-nis>=0.70.0:net/slapi-nis

USES=		autoreconf gettext-runtime gettext-tools gmake gssapi:mit iconv \
		ldap libtool localbase:ldflags nodejs:build pkgconfig python \
		shebangfix ssl

USE_RC_SUBR=	ipa-custodia freeipa-server

SHEBANG_FILES=	install/ui/util/build.sh install/ui/util/change-profile.sh \
		install/ui/util/clean.sh install/ui/util/compile.sh \
		install/ui/util/make-builder.sh install/ui/util/make-dojo.sh \
		install/ui/util/make-patternfly.sh install/ui/util/make-ui.sh \
		install/ui/util/prepare-dojo.sh install/ui/util/sync.sh

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--disable-client \
		--with-ipaplatform=freebsd \
		--with-vendor-suffix=+FreeBSD

CONFIGURE_ENV=	LIBS="-lintl" \
		LIBVERTO_CFLAGS="-I${LOCALBASE}/include" \
		LIBVERTO_LIBS="-L${LOCALBASE}/lib -lverto"

CFLAGS+=	-D__BSD_VISIBLE=1

CONFLICTS_INSTALL=	freeipa-client

BINARY_ALIAS=	getopt=${LOCALBASE}/bin/getopt
SUB_FILES=	ipa-otpd-wrapper
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}

USERS=		ipaapi kdcproxy
GROUPS=		ipaapi kdcproxy

OPTIONS_DEFINE=	DOCS

post-build:
	${MAKE_CMD} -C ${WRKSRC}/client \
		LIBINTL_LIBS="-lintl" ipa-getkeytab ipa-rmkeytab ipa-join

post-install:
	${CHMOD} 0555 ${STAGEDIR}${PREFIX}/libexec/ipa/certmonger/*
	${INSTALL_SCRIPT} ${WRKSRC}/client/ipa-client-install.in \
		${STAGEDIR}${PREFIX}/sbin/ipa-client-install
	@${REINPLACE_CMD} -e "1s|^#!/usr/bin/python3.*|#!${PYTHON_CMD} -I|" \
		${STAGEDIR}${PREFIX}/sbin/ipa-client-install
	@${RM} ${STAGEDIR}${PREFIX}/sbin/ipa-client-install.bak
	${INSTALL_SCRIPT} ${WRKSRC}/client/ipa-client-automount.in \
		${STAGEDIR}${PREFIX}/sbin/ipa-client-automount
	@${REINPLACE_CMD} -e "1s|/usr/bin/python3|${PYTHON_CMD} -I|" \
		${STAGEDIR}${PREFIX}/sbin/ipa-client-automount
	@${RM} ${STAGEDIR}${PREFIX}/sbin/ipa-client-automount.bak
	${INSTALL_PROGRAM} ${WRKSRC}/client/ipa-getkeytab \
		${STAGEDIR}${PREFIX}/sbin/ipa-getkeytab
	${INSTALL_PROGRAM} ${WRKSRC}/client/ipa-rmkeytab \
		${STAGEDIR}${PREFIX}/sbin/ipa-rmkeytab
	${INSTALL_PROGRAM} ${WRKSRC}/client/ipa-join \
		${STAGEDIR}${PREFIX}/sbin/ipa-join
	${INSTALL_SCRIPT} ${WRKDIR}/ipa-otpd-wrapper \
		${STAGEDIR}${PREFIX}/libexec/ipa/ipa-otpd-wrapper
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/freeipa-server.newsyslog.conf \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/freeipa-server.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/ipa-client/pki
	@${MKDIR} ${STAGEDIR}/var/db/ipa-client/sysrestore
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ipa/client
	${INSTALL_DATA} ${WRKSRC}/client/share/freeipa.template \
		${STAGEDIR}${PREFIX}/share/ipa/client/freeipa.template
	${INSTALL_DATA} ${WRKSRC}/client/share/freeipa-realm.template \
		${STAGEDIR}${PREFIX}/share/ipa/client/freeipa-realm.template

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/README.md ${STAGEDIR}${DOCSDIR}/README.md

.include <bsd.port.mk>
