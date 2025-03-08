PORTNAME=	sssd
PORTVERSION=	2.12.0
CATEGORIES=	security
PKGNAMESUFFIX=	2

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	System Security Services Daemon
WWW=		https://sssd.io/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		bash:shells/bash \
		docbook-xsl>=1:textproc/docbook-xsl \
		p11-kit:security/p11-kit \
		nsupdate:dns/bind-tools \
		xmlcatalog:textproc/libxml2 \
		xmlcatmgr:textproc/xmlcatmgr \
		xsltproc:textproc/libxslt

LIB_DEPENDS=	libcares.so:dns/c-ares \
		libcurl.so:ftp/curl \
		libdbus-1.so:devel/dbus \
		libdhash.so:devel/ding-libs \
		libfido2.so:security/libfido2 \
		libinotify.so:devel/libinotify \
		libjansson.so:devel/jansson \
		libjose.so:net/jose \
		libldb.so:${SAMBA_LDB_PORT:U${SAMBA_PORT}} \
		libndr-krb5pac.so:${SAMBA_PORT} \
		libndr-nbt.so:${SAMBA_PORT} \
		libndr-standard.so:${SAMBA_PORT} \
		libndr.so:${SAMBA_PORT} \
		libp11-kit.so:security/p11-kit \
		libpcre2-8.so:devel/pcre2 \
		libpopt.so:devel/popt \
		libsamba-util.so:${SAMBA_PORT} \
		libsasl2.so:security/cyrus-sasl2 \
		libsmbclient.so:${SAMBA_PORT} \
		libtalloc.so:${SAMBA_TALLOC_PORT} \
		libtdb.so:${SAMBA_TDB_PORT} \
		libtevent.so:${SAMBA_TEVENT_PORT} \
		libunistring.so:devel/libunistring \
		libuuid.so:misc/libuuid \
		libutf8proc.so:textproc/utf8proc

RUN_DEPENDS=	adcli:net-mgmt/adcli \
		cyrus-sasl-gssapi>0:security/cyrus-sasl2-gssapi \
		nsupdate:dns/bind-tools

USES=	autoreconf cpe gettext gmake gssapi:flags,mit iconv ldap \
	libtool localbase:ldflags pathfix pkgconfig python samba:env \
	shebangfix ssl

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPE_VENDOR=	fedoraproject

CONFIGURE_ARGS=	--disable-cifs-idmap-plugin \
		--disable-linux-caps \
		--without-selinux \
		--without-autofs \
		--enable-pammoddir=${PREFIX}/lib \
		--with-db-path=/var/db/sss/db \
		--with-pubconf-path=/var/db/sss/pubconf  \
		--with-pid-path=/var/run \
		--with-pipe-path=/var/run/sss/pipes \
		--with-mcache-path=/var/db/sss/mc \
		--with-environment-file=${LOCALBASE}/etc/sssd \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--with-krb5-plugin-path=${LOCALBASE}/lib/krb5/plugins/libkrb5 \
		--with-krb5authdata-plugin-path=${LOCALBASE}/lib/krb5/plugins/authdata \
		--with-krb5-conf=/etc/krb5.conf \
		--with-winbind-plugin-path=${SAMBA_IDMAP_MODULESDIR} \
		--with-gpo-cache-path=/var/db/sss/gpo_cache \
		--with-secrets-db-path=/var/lib/sss/secrets \
		--with-passkey \
		--without-nfsv4-idmapd-plugin \
		--with-ldb-lib-dir=${SAMBA_LDB_MODULESDIR} \
		--with-smb-idmap-interface-version=6
CONFIGURE_ENV=	KRB5_CONFIG="${KRB5CONFIG}" \
		SOFTHSM2_PATH=${LOCALBASE}/lib/softhsm/libsofthsm2.so

CPPFLAGS=	-DRENEWAL_PROG_PATH='\"${LOCALBASE}/sbin/adcli\"'
LIBS=		-lintl

PLIST_SUB=	PYTHON_VER=${PYTHON_VER} \
		SAMBA_IDMAP_MODULESDIR=${SAMBA_IDMAP_MODULESDIR} \
		SAMBA_LDB_MODULESDIR=${SAMBA_LDB_MODULESDIR}

BINARY_ALIAS=	python3=python${PYTHON_VER}
SHEBANG_FILES=	src/tools/analyzer/sss_analyze \
		src/tools/sss_obfuscate \
		src/config/SSSDConfigTest.py \
		src/tests/*.py \
		src/tests/double_semicolon_test \
		src/tests/multihost/data/memcachesize.py \
		src/tests/whitespace_test \
		contrib/vagrant/bootstrap.sh

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes

OPTIONS_DEFINE=	NLS TEST
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls

TEST_BUILD_DEPENDS=	cwrap>0:devel/cwrap \
			${LOCALBASE}/lib/softhsm/libsofthsm2.so:security/softhsm2
TEST_LIB_DEPENDS=	libcheck.so:devel/check \
			libcmocka.so:sysutils/cmocka

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1500000
CPPFLAGS+=	-DHAVE_TIMEZONE=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		-e 's|/var/lib/sss/pubconf/|/var/db/sss/pubconf/|g' \
		${WRKSRC}/src/man/po/*.po || true
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' \
		-e 's|/etc/openldap/|${LOCALBASE}/etc/openldap/|g' \
		${WRKSRC}/src/man/*xml || true
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd-example.conf \
		${STAGEDIR}${ETCDIR}/sssd.conf.sample
	${LN} -sf libnss_sss.so.2 ${STAGEDIR}${PREFIX}/lib/nss_sss.so.1

# Skip whitespace tests, see
# https://github.com/SSSD/sssd/commit/308bacbd22f2f5a483cb2cef098082b5f9625b8d
pre-test:
	${RM} -r ${WRKSRC}/.git

.include <bsd.port.post.mk>
