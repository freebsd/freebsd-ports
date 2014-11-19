# Created by: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
# $FreeBSD$

PORTNAME=	sssd
DISTVERSION=	1.9.6
PORTREVISION=	9
CATEGORIES=	security
MASTER_SITES=   https://fedorahosted.org/released/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	lukas.slebodnik@intrak.sk
COMMENT=	System Security Services Daemon

LICENSE=	GPLv3

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libtalloc.so:${PORTSDIR}/devel/talloc \
		libtevent.so:${PORTSDIR}/devel/tevent \
		libtdb.so:${PORTSDIR}/databases/tdb \
		libldb.so:${PORTSDIR}/databases/ldb \
		libcares.so:${PORTSDIR}/dns/c-ares \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdhash.so:${PORTSDIR}/devel/ding-libs \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libunistring.so:${PORTSDIR}/devel/libunistring \
		libnss3.so:${PORTSDIR}/security/nss \
		libsasl2.so:${PORTSDIR}/security/cyrus-sasl2 \
		libkrb5.so:${PORTSDIR}/security/krb5 \
		libinotify.so:${PORTSDIR}/devel/libinotify
BUILD_DEPENDS=	xmlcatalog:${PORTSDIR}/textproc/libxml2 \
		docbook-xsl>=1:${PORTSDIR}/textproc/docbook-xsl \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr \
		krb5>=1.10:${PORTSDIR}/security/krb5 \
		nsupdate:${PORTSDIR}/dns/bind99

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-selinux=no --with-semanage=no \
		--with-ldb-lib-dir=${LOCALBASE}/lib/shared-modules/ldb/ \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--with-libnl=no --with-init-dir=no --datadir=${DATADIR} \
		--docdir=${DOCSDIR} --with-pid-path=/var/run \
		--localstatedir=/var --enable-pammoddir=${PREFIX}/lib \
		--with-db-path=/var/db/sss --with-pipe-path=/var/run/sss \
		--with-pubconf-path=/var/run/sss --with-mcache-path=/var/db/sss_mc \
		--with-unicode-lib=libunistring --with-autofs=no
CONFIGURE_ENV=	XMLLINT="/bin/echo"
CFLAGS+=	-fstack-protector-all
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
#DEBUG_FLAGS=  -g
MAKE_ENV+=	LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"
SUB_FILES=	pkg-message

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes
USES=		gettext gmake iconv libtool pathfix pkgconfig python shebangfix
PATHFIX_MAKEFILEIN=	Makefile.am
SHEBANG_FILES=	src/tools/sss_obfuscate

USE_RC_SUBR=	${PORTNAME}
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not link on ia64, powerpc, or sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SIGCLD|SIGCHLD|g' ${WRKSRC}/src/util/signal.c
	@${REINPLACE_CMD} -e '/#define SIZE_T_MAX ((size_t) -1)/d' \
		${WRKSRC}/src/util/util.h
	@${REINPLACE_CMD} -e '/pam_misc/d' \
		${WRKSRC}/src/sss_client/pam_test_client.c
	@${REINPLACE_CMD} -e 's|security/pam_misc.h||g' \
		${WRKSRC}/configure.ac ${WRKSRC}/src/external/pam.m4
	@${REINPLACE_CMD} -e 's|NSS_STATUS_NOTFOUND|NS_NOTFOUND|g' \
		-e 's|NSS_STATUS_UNAVAIL|NS_UNAVAIL|g' \
		-e 's|NSS_STATUS_TRYAGAIN|NS_TRYAGAIN|g' \
		-e '/ETIME/d' \
		-e 's|NSS_STATUS_SUCCESS|NS_SUCCESS|g' \
		${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's|security/_pam_macros.h|pam_macros.h|g' \
		${WRKSRC}/src/sss_client/sss_pam_macros.h
	@${REINPLACE_CMD} -e 's|#include <security/pam_modutil.h>||g' \
		-e 's|PAM_BAD_ITEM|PAM_USER_UNKNOWN|g' \
		-e 's|security/pam_ext.h|security/pam_appl.h|g' \
		-e 's|pam_modutil_getlogin(pamh)|getlogin()|g' \
		-e 's|pam_vsyslog(pamh,|vsyslog(|g' \
		${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} \
		-e 's|install-data-hook install-dist_initSCRIPTS|install-dist_initSCRIPTS|g' \
		-e 's|install-data-hook|notinstall-data-hook|g' \
		-e 's| -lpam_misc||g' \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' \
		-e 's|/etc/openldap/|${LOCALBASE}/etc/openldap/|g' \
		${WRKSRC}/src/man/*xml
	@${CP} ${FILESDIR}/pam_macros.h ${WRKSRC}/pam_macros.h
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c
	@${CP} ${FILESDIR}/sss_bsd_errno.h ${WRKSRC}/src/util/sss_bsd_errno.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd-example.conf ${STAGEDIR}${ETCDIR}/sssd.conf.sample
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s nss_sss.so nss_sss.so.1)

	# clean these up from the install; we create them in rc script start_precmd
.for VARDIRS in db/sss db/sss_mc log/sssd run/sss/krb5.include.d run/sss/private run/sss
	@${RMDIR} ${STAGEDIR}/var/${VARDIRS}
.endfor

.include <bsd.port.mk>
