# New ports collection makefile for:	sssd
# Date created:				Sep 6 2011
# Whom:					Andrew Elble <aweits@rit.edu>
#
# $FreeBSD$
#

PORTNAME=	sssd
DISTVERSION=	1.6.1
CATEGORIES=	net
MASTER_SITES=	https://fedorahosted.org/released/${PORTNAME}/

MAINTAINER=	aweits@rit.edu
COMMENT=	System Security Services Daemon

LICENSE=	GPLv3

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		talloc.2:${PORTSDIR}/devel/talloc \
		tevent.0:${PORTSDIR}/devel/tevent \
		xslt.2:${PORTSDIR}/textproc/libxslt \
		tdb.1:${PORTSDIR}/databases/tdb \
		ldb:${PORTSDIR}/databases/ldb \
		cares.2:${PORTSDIR}/dns/c-ares \
		dbus:${PORTSDIR}/devel/dbus \
		dhash.1:${PORTSDIR}/devel/ding-libs \
		pcre.0:${PORTSDIR}/devel/pcre \
		unistring.1:${PORTSDIR}/devel/libunistring \
		nss3.1:${PORTSDIR}/security/nss \
		sasl2.2:${PORTSDIR}/security/cyrus-sasl2 \
		xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	xmlcatalog:${PORTSDIR}/textproc/libxml2 \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
RUN_DEPENDS=	xmlcatmgr:${PORTSDIR}/textproc/xmlcatmgr

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-selinux=no --with-semanage=no \
		--with-ldb-lib-dir=${LOCALBASE}/lib/ldb \
		--with-xml-catalog-path=${LOCALBASE}/share/xml/catalog \
		--with-libnl=no --with-init-dir=no \
		--docdir=${WRKDIR}/docs --with-pid-path=/var/run \
		--localstatedir=/var --enable-pammoddir=${PREFIX}/lib \
		--with-db-path=/var/db/sss --with-pipe-path=/var/run/sss \
		--with-pubconf-path=/var/run/sss
CFLAGS+=	-L${LOCALBASE}/lib -fstack-protector-all
#DEBUG_FLAGS=	-g

USE_AUTOTOOLS=	autoconf automake
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_OPENLDAP=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_PYTHON=	yes

USE_RC_SUBR=	${PORTNAME}
MAN5=		sssd-ipa.5 sssd-krb5.5 sssd-ldap.5 sssd-simple.5 \
		sssd.conf.5
MAN8=		pam_sss.8 sss_cache.8 sss_groupadd.8 sss_groupdel.8 \
		sss_groupmod.8 sss_groupshow.8 sss_obfuscate.8 \
		sss_useradd.8 sss_userdel.8 sss_usermod.8 sssd.8 \
		sssd_krb5_locator_plugin.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800107
IGNORE=		is not supported prior to 8.0-RELEASE
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SIGCLD|SIGCHLD|g' ${WRKSRC}/src/util/signal.c
	@${REINPLACE_CMD} -e '/#define SIZE_T_MAX ((size_t) -1)/d' ${WRKSRC}/src/util/util.h
	@${REINPLACE_CMD} -e '/pam_misc/d' ${WRKSRC}/src/sss_client/pam_test_client.c
	@${REINPLACE_CMD} -e '/ETIME/d' ${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's| -lpam_misc||g' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|security/pam_misc.h||g' ${WRKSRC}/configure* ${WRKSRC}/src/external/pam.m4
	@${REINPLACE_CMD} -e 's|NSS_STATUS_NOTFOUND|NS_NOTFOUND|g' ${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's|NSS_STATUS_UNAVAIL|NS_UNAVAIL|g' ${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's|NSS_STATUS_TRYAGAIN|NS_TRYAGAIN|g' ${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's|NSS_STATUS_SUCCESS|NS_SUCCESS|g' ${WRKSRC}/src/sss_client/common.c
	@${REINPLACE_CMD} -e 's|security/pam_ext.h|security/pam_appl.h|g' ${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} -e 's|security/_pam_macros.h|pam_macros.h|g' ${WRKSRC}/src/sss_client/sss_pam_macros.h
	@${REINPLACE_CMD} -e 's|#include <security/pam_modutil.h>||g' ${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} -e 's|PAM_BAD_ITEM|PAM_USER_UNKNOWN|g' ${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} -e 's|pam_vsyslog(pamh,|vsyslog(|g' ${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} -e 's|pam_modutil_getlogin(pamh)|getlogin()|g' ${WRKSRC}/src/sss_client/pam_sss.c
	@${REINPLACE_CMD} -e '/..MAKE. ..AM_MAKEFLAGS. install-data-hook/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|install-data-hook install-dist_initSCRIPTS|install-dist_initSCRIPTS|g' \
		${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|install-data-hook|notinstall-data-hook|g' ${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|/etc/sssd/|${ETCDIR}/|g' ${WRKSRC}/src/man/*xml
	@${REINPLACE_CMD} -e 's|/etc/openldap/|${PREFIX}/etc/openldap/|g' ${WRKSRC}/src/man/*xml
	@${CP} ${FILESDIR}/pam_macros.h ${WRKSRC}/pam_macros.h
	@${CP} ${FILESDIR}/bsdnss.c ${WRKSRC}/src/sss_client/bsdnss.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/examples/sssd.conf ${ETCDIR}/sssd.conf.sample
	(cd ${PREFIX}/lib && ${LN} -s nss_sss.so.2 nss_sss.so.1)
	(cd ${PREFIX}/lib && ${LN} -s pam_sss.so pam_sss.so.5)
	@${RM} -f ${PREFIX}/lib/ldb/memberof.la
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
