# Created by: Lukas Slebodnik <lukas.slebodnik@intrak.sk>

PORTNAME=	sssd
PORTVERSION=	1.16.5
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	https://releases.pagure.org/SSSD/${PORTNAME}/

MAINTAINER=	lukas.slebodnik@intrak.sk
COMMENT=	System Security Services Daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpopt.so:devel/popt \
		libtalloc.so:devel/talloc \
		libtevent.so:devel/tevent \
		libtdb.so:databases/tdb \
		libldb.so:databases/ldb21 \
		libcares.so:dns/c-ares \
		libdbus-1.so:devel/dbus \
		libdhash.so:devel/ding-libs \
		libpcre.so:devel/pcre \
		libunistring.so:devel/libunistring \
		libnss3.so:security/nss \
		libsasl2.so:security/cyrus-sasl2 \
		libinotify.so:devel/libinotify \
		libplds4.so:devel/nspr
BUILD_DEPENDS=	xmlcatalog:textproc/libxml2 \
		docbook-xsl>=1:textproc/docbook-xsl \
		xsltproc:textproc/libxslt \
		xmlcatmgr:textproc/xmlcatmgr \
		krb5>=1.10:security/krb5 \
		nsupdate:dns/bind-tools

FLAVORS=	default smb
FLAVOR?=	${FLAVORS:[1]}
smb_PKGNAMESUFFIX=	-smb

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-selinux --without-semanage \
		--without-libnl --without-nfsv4-idmapd-plugin \
		--without-autofs --without-secrets --without-kcm \
		--without-python2-bindings --with-python-prefix=${PREFIX} \
		--with-init-dir=no \
		--disable-cifs-idmap-plugin \
		--with-unicode-lib=libunistring \
		--with-ldb-lib-dir=${LOCALBASE}/lib/shared-modules/ldb \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--datadir=${DATADIR} --docdir=${DOCSDIR} --localstatedir=/var \
		--with-db-path=/var/db/sss/db --with-mcache-path=/var/db/sss/mc \
		--with-pubconf-path=/var/db/sss/pubconf  \
		--with-gpo-cache-path=/var/db/sss/gpo_cache  \
		--with-pid-path=/var/run --with-pipe-path=/var/run/sss/pipes \
		--with-krb5-conf=/etc/krb5.conf \
		--enable-pammoddir=${PREFIX}/lib
CFLAGS+=	-fstack-protector-all
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
#DEBUG_FLAGS=	-g
MAKE_ENV+=	LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"
SUB_FILES=	pkg-message

TEST_TARGET=	check

USES=		autoreconf cpe gettext gmake iconv libtool pathfix pkgconfig \
		python:3.6+ shebangfix gssapi:mit
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	fedoraproject

BINARY_ALIAS=	python3=python${PYTHON_VER}
SHEBANG_FILES=	src/tools/sss_obfuscate \
		src/sbus/sbus_codegen

USE_RC_SUBR=	${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	DOCS SMB
OPTIONS_SUB=	yes

SMB_DESC=		Install IPA and AD providers (requires Samba4)
SMB_USES=		samba:lib
SMB_CONFIGURE_WITH=	samba smb-idmap-interface-version=6
SMB_LIB_DEPENDS=	libndr-nbt.so.0:net/samba412 \
			libndr-krb5pac.so.0:net/samba412 \
			libndr-standard.so.0:net/samba412 \
			libndr.so.1:net/samba412 \
			libsamba-util.so.0:net/samba412 \
			libsmbclient.so.0:net/samba412

.if ${FLAVOR} == smb
OPTIONS_DEFAULT+=	SMB
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|NSS_STATUS_NOTFOUND|NS_NOTFOUND|g' \
		-e 's|NSS_STATUS_UNAVAIL|NS_UNAVAIL|g' \
		-e 's|NSS_STATUS_TRYAGAIN|NS_TRYAGAIN|g' \
		-e '/ETIME/d' \
		-e 's|NSS_STATUS_SUCCESS|NS_SUCCESS|g' \
		${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} \
		-e 's|pam_modutil_getlogin(pamh)|getlogin()|g' \
		${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} \
		-e 's|install-data-hook install-dist_initSCRIPTS|install-dist_initSCRIPTS|g' \
		-e 's|install-data-hook|notinstall-data-hook|g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' \
		-e 's|/etc/openldap/|${LOCALBASE}/etc/openldap/|g' \
		${WRKSRC}/src/man/*xml
	@${REINPLACE_CMD} -e 's|/usr/bin/|${PREFIX}/bin/|g' \
		-e 's|/var/lib/sss/pubconf/|/var/db/sss/pubconf/|g' \
		${WRKSRC}/src/man/sss_ssh_knownhostsproxy.1.xml \
		${WRKSRC}/src/man/*/sss_ssh_knownhostsproxy.1.xml \
		${WRKSRC}/src/man/po/*.po
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c
	@${CP} ${FILESDIR}/sss_bsd_errno.h ${WRKSRC}/src/util/sss_bsd_errno.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd-example.conf \
		${STAGEDIR}${ETCDIR}/sssd.conf.sample
	${LN} -sf nss_sss.so ${STAGEDIR}${PREFIX}/lib/nss_sss.so.1

# clean unused man dirs
.for i in es/man1 nl/man1 nl/man5 pt/man1 pt/man5 sv/man1
	@${RMDIR} ${STAGEDIR}${PREFIX}/man/${i}
.endfor

.include <bsd.port.mk>
