PORTNAME=	sssd
PORTVERSION=	2.9.5
PORTREVISION=	2
CATEGORIES=	security
PKGNAMESUFFIX=	2

MAINTAINER=	jhixson@FreeBSD.org
COMMENT=	System Security Services Daemon
WWW=		https://sssd.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL?=	sssd*

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		bash:shells/bash \
		docbook-xsl>=1:textproc/docbook-xsl \
		krb5>=1.20:security/krb5 \
		p11-kit:security/p11-kit \
		nsupdate:dns/bind-tools \
		xmlcatalog:textproc/libxml2 \
		xmlcatmgr:textproc/xmlcatmgr \
		xsltproc:textproc/libxslt

LIB_DIRS+=	${LOCALBASE}/lib ${LOCALBASE}/lib/sasl2
LIB_DEPENDS=	libcares.so:dns/c-ares \
		libcom_err.so:security/krb5 \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdhash.so:devel/ding-libs \
		libfido2.so:security/libfido2 \
		libgssapi_krb5.so:security/krb5 \
		libinotify.so:devel/libinotify \
		libjansson.so:devel/jansson \
		libjose.so:net/jose \
		libkrb5.so:security/krb5 \
		libldb.so:${SAMBA_LDB_PORT} \
		libndr-krb5pac.so:${SAMBA_PORT} \
		libndr-nbt.so:${SAMBA_PORT} \
		libndr-standard.so:${SAMBA_PORT} \
		libndr.so:${SAMBA_PORT} \
		libnfs.so:net/libnfs \
		libnss3.so:security/nss \
		libp11-kit.so:security/p11-kit \
		libpcre2-posix.so:devel/pcre2 \
		libplds4.so:devel/nspr \
		libpopt.so:devel/popt \
		libsamba-util.so:${SAMBA_PORT} \
		libsasl2.so:security/cyrus-sasl2 \
		libsmbclient.so:${SAMBA_PORT} \
		libtalloc.so:devel/talloc \
		libtdb.so:databases/tdb \
		libtevent.so:devel/tevent \
		libunistring.so:devel/libunistring \
		libuuid.so:misc/e2fsprogs-libuuid

RUN_DEPENDS=	adcli:net-mgmt/adcli \
		cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi

USES=	autoreconf cpe gettext gmake gssapi:bootstrap,flags,mit iconv ldap \
	libtool localbase:ldflags pathfix pkgconfig python:3.9+ samba:env \
	shebangfix ssl

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
CPE_VENDOR=	fedoraproject

DEBUG_FLAGS=	-g
STRIP=

CONFIGURE_ARGS=	--disable-dependency-tracking \
		--datadir=${DATADIR} \
		--docdir=${DOCSDIR} \
		--localstatedir=/var \
		--disable-silent-rules \
		--disable-nls \
		--disable-cifs-idmap-plugin \
		--disable-valgrind \
		--disable-systemtap \
		--enable-pammoddir=${PREFIX}/lib \
		--enable-ldb-version-check \
		--enable-pac-responder \
		--with-db-path=/var/db/sss/db \
		--with-os=freebsd \
		--with-plugin-path=${LOCALBASE}/lib/sssd \
		--with-pubconf-path=/var/db/sss/pubconf  \
		--with-pid-path=/var/run \
		--with-pipe-path=/var/run/sss/pipes \
		--with-mcache-path=/var/db/sss/mc \
		--with-environment-file=${LOCALBASE}/etc/sssd \
		--with-init-dir=no \
		--with-manpages \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--with-krb5-plugin-path=${LOCALBASE}/lib/krb5/plugins/libkrb5 \
		--with-krb5authdata-plugin-path=${LOCALBASE}/lib/krb5/plugins/authdata \
		--with-krb5-conf=/etc/krb5.conf \
		--without-python2-bindings \
		--with-winbind-plugin-path=${LOCALBASE}/lib/samba4/modules/idmap \
		--without-selinux \
		--with-gpo-cache-path=/var/db/sss/gpo_cache  \
		--without-semanage \
		--with-app-libs=${LOCALBASE}/lib/sssd/modules \
		--without-autofs \
		--with-files-provider \
		--with-passkey \
		--with-libsifp \
		--without-libsifp \
		--with-syslog=syslog \
		--with-samba \
		--without-nfsv4-idmapd-plugin \
		--with-nfs-lib-path=${LOCALBASE}/lib \
		--with-secrets-db-path=/var/lib/sss/secrets \
		--with-kcm \
		--with-oidc-child \
		--with-ldb-lib-dir=${LOCALBASE}/lib/shared-modules/ldb \
		--with-smb-idmap-interface-version=6 \
		--without-libnl \
		--with-nscd-conf=/etc/nscd.conf \
		--with-python_prefix=${PREFIX} \
		--with-unicode-lib=libunistring

CPPFLAGS+=	-DRENEWAL_PROG_PATH='\"${LOCALBASE}/sbin/adcli\"'
CFLAGS+=	-fstack-protector-all
CFLAGS+=	-I${LOCALBASE}/include/samba4

LIBS+=	-L${LOCALBASE}/lib \
	-L${LOCALBASE}/lib/samba4/private \
	-L${LOCALBASE}/lib/sasl2  \
	-linotify -lintl

KRB5_HOME=	${LOCALBASE}
KRB5_CONFIG=	${LOCALBASE}/bin/krb5-config
KRB5_CFLAGS=	-I${LOCALBASE}/include
KRB5_LIBS=	-L${LOCALBAse}/lib -lkrb5 -lk5crypto -lcom_err

GSSAPI_KRB5_CFLAGS=	-I${LOCALBASE}/include
GSSAPI_KRB5_LIBS=	-L${LOCALBASE}/lib -lgssapi_krb5 -lkrb5 -lk5crypto -lcom_err

LDFLAGS+=	-lgssapi
LDFLAGS_SL+=	-lgssapi

INCLUDES+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	INCLUDES="${INCLUDES}" \
		LDFLAGS_SL="${LDFLAGS_SL}"
MAKE_ENV=	MAKELEVEL=0

PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
MAKE_ENV+=	LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"
SUB_FILES=	pkg-message

BINARY_ALIAS=	python3=python${PYTHON_VER}
SHEBANG_FILES=	sbus_generate.sh.in \
		src/tools/analyzer/sss_analyze \
		src/tools/sss_obfuscate \
		src/config/SSSDConfigTest.py \
		src/tests/python-test.py \
		src/tests/pysss-test.py \
		src/tests/cwrap/cwrap_test_setup.sh \
		src/tests/whitespace_test \
		src/tests/pyhbac-test.py \
		src/tests/multihost/data/memcachesize.py \
		src/tests/double_semicolon_test \
		src/tests/pysss_murmur-test.py \
		scripts/release.sh \
		contrib/git/pre-push \
		contrib/ci/rpm-spec-builddeps \
		contrib/ci/clean \
		contrib/ci/valgrind-condense \
		contrib/ci/run-multihost \
		contrib/ci/run \
		contrib/ci/get-matrix.py \
		contrib/vagrant/bootstrap.sh \
		contrib/fedora/make_srpm.sh

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=yes
GH_ACCOUNT=sssd

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		-e 's|/var/lib/sss/pubconf/|/var/db/sss/pubconf/|g' \
		${WRKSRC}/src/man/sss_ssh_knownhostsproxy.1.xml \
		${WRKSRC}/src/man/po/*.po || true
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' \
		-e 's|/etc/openldap/|${LOCALBASE}/etc/openldap/|g' \
		${WRKSRC}/src/man/*xml || true
	@${CP} ${FILESDIR}/sss_bsd_errno.h ${WRKSRC}/src/util/sss_bsd_errno.h
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd-example.conf \
		${STAGEDIR}${ETCDIR}/sssd.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system.d
	${INSTALL_DATA} ${WRKSRC}/src/responder/ifp/org.freedesktop.sssd.infopipe.conf \
		${STAGEDIR}${PREFIX}/share/dbus-1/system.d/org.freedesktop.sssd.infopipe.conf
	${MKDIR} ${STAGEDIR}${PREFIX}/share/dbus-1/system-services
	${INSTALL_DATA} ${WRKSRC}/src/responder/ifp/org.freedesktop.sssd.infopipe.service \
		${STAGEDIR}${PREFIX}/share/dbus-1/system-services/org.freedesktop.sssd.infopipe.service
	${LN} -sf libnss_sss.so.2 ${STAGEDIR}${PREFIX}/lib/nss_sss.so.1

.include <bsd.port.mk>
