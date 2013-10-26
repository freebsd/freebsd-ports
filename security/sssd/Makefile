# Created by: Lukas Slebodnik <lukas.slebodnik@intrak.sk>
# $FreeBSD$

PORTNAME=	sssd
DISTVERSION=	1.9.5
CATEGORIES=	security
MASTER_SITES=   https://fedorahosted.org/released/${PORTNAME}/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	lukas.slebodnik@intrak.sk
COMMENT=	System Security Services Daemon

LICENSE=	GPLv3

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libtalloc.so:${PORTSDIR}/devel/talloc \
		libtevent.so:${PORTSDIR}/devel/tevent \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
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
		libldap.so:${PORTSDIR}/net/openldap24-sasl-client \
		libinotify.so:${PORTSDIR}/devel/libinotify
BUILD_DEPENDS=	xmlcatalog:${PORTSDIR}/textproc/libxml2 \
		docbook-xsl>=1:${PORTSDIR}/textproc/docbook-xsl \
		xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr \
		krb5>=1.10:${PORTSDIR}/security/krb5

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
CFLAGS+=	-L${LOCALBASE}/lib -fstack-protector-all -Wno-format
LDFLAGS+=	-linotify
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
#DEBUG_FLAGS=  -g
MAKE_ENV+=	LINGUAS="bg de eu es fr hu id it ja nb nl pl pt ru sv tg tr uk zh_CN zh_TW"
SUB_FILES=	pkg-message

USE_AUTOTOOLS=	autoconf automake aclocal
AUTOMAKE_ARGS= --add-missing
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_OPENLDAP=	yes
USES=		gettext gmake iconv pkgconfig

USE_RC_SUBR=	${PORTNAME}
PORTDATA=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
IGNORE=		is not supported prior to 8.0-RELEASE
.endif
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
	    	${WRKSRC}/configure* ${WRKSRC}/src/external/pam.m4
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
	@${REINPLACE_CMD} -e '/..MAKE. ..AM_MAKEFLAGS. install-data-hook/d' \
	    	${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' \
		-e 's|install-data-hook install-dist_initSCRIPTS|install-dist_initSCRIPTS|g' \
		-e 's|install-data-hook|notinstall-data-hook|g' \
		-e 's| -lpam_misc||g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' \
		-e 's|/etc/openldap/|${LOCALBASE}/etc/openldap/|g' \
		${WRKSRC}/src/man/*xml
	@${CP} ${FILESDIR}/pam_macros.h ${WRKSRC}/pam_macros.h
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd-example.conf ${STAGEDIR}${ETCDIR}/sssd.conf.sample
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s nss_sss.so.2 nss_sss.so.1)
	(cd ${STAGEDIR}${PREFIX}/lib && ${LN} -s pam_sss.so pam_sss.so.5)
	@${RM} -f ${STAGEDIR}${PREFIX}/lib/ldb/memberof.la

.include <bsd.port.post.mk>
