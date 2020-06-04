# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	3.6.14
CATEGORIES=	security net
MASTER_SITES=	GNUPG/gnutls/v${PORTVERSION:R}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/doc/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/doc/COPYING.LESSER

LIB_DEPENDS=	libgmp.so:math/gmp \
		libnettle.so:security/nettle \
		libtasn1.so:security/libtasn1 \
		libunistring.so:devel/libunistring
RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		compiler:c11 cpe gmake iconv libtool localbase makeinfo \
		pkgconfig tar:xz
USE_LDCONFIG=	yes

CPE_VENDOR=	gnu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-guile \
		--enable-local-libopts \
		--with-system-priority-file=${PREFIX}/etc/gnutls/default-priorities \
		--with-default-trust-store-file=${LOCALBASE}/share/certs/ca-root-nss.crt \
		--with-trousers-lib=${LOCALBASE}/lib/libtspi.so.1 \
		AUTOGEN=false \
		ac_cv_type_max_align_t=yes
MAKE_ENV=	MAKEINFOFLAGS=--no-split
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		DANE EXAMPLES IDN NLS P11KIT TPM
OPTIONS_DEFAULT=	IDN P11KIT TPM
OPTIONS_SUB=		yes

DANE_DESC=		Certificate verification via DNSSEC
DANE_LIB_DEPENDS=	libunbound.so:dns/unbound
DANE_CONFIGURE_ENABLE=	libdane

IDN_CONFIGURE_WITH=	idn
IDN_LIB_DEPENDS=	libidn2.so:dns/libidn2

NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_OFF=	ac_cv_lib_intl_gettext=no
NLS_USES=		gettext

P11KIT_DESC=		PKCS\#11 and p11-kit support
P11KIT_CONFIGURE_WITH=	p11-kit
P11KIT_CONFIGURE_ON=	--with-default-trust-store-pkcs11="pkcs11:model=p11-kit-trust;manufacturer=PKCS%2311%20Kit"
P11KIT_LIB_DEPENDS=	libp11-kit.so:security/p11-kit

TPM_DESC=		Trusted Platform Module support
TPM_CONFIGURE_WITH=	tpm
TPM_LIB_DEPENDS=	libtspi.so:security/trousers

INFO=		gnutls gnutls-guile

post-patch:
	@${RM} ${WRKSRC}/doc/*.info*
	@${REINPLACE_CMD} 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/doc/manpages/*.[13]
	@${REINPLACE_CMD} -E 's,/etc/(gnutls|tpasswd),${PREFIX}&,g' \
		${WRKSRC}/doc/cha-gtls-app.texi \
		${WRKSRC}/doc/gnutls-api.texi \
		${WRKSRC}/doc/invoke-certtool.texi \
		${WRKSRC}/doc/invoke-gnutls-cli.texi \
		${WRKSRC}/doc/invoke-gnutls-serv.texi \
		${WRKSRC}/doc/invoke-p11tool.texi \
		${WRKSRC}/doc/invoke-srptool.texi \
		${WRKSRC}/doc/manpages/certtool.1 \
		${WRKSRC}/doc/manpages/gnutls_priority_init2.3 \
		${WRKSRC}/doc/manpages/gnutls-cli.1 \
		${WRKSRC}/doc/manpages/gnutls-serv.1 \
		${WRKSRC}/doc/manpages/p11tool.1 \
		${WRKSRC}/doc/manpages/srptool.1 \
		${WRKSRC}/lib/includes/gnutls/pkcs11.h \
		${WRKSRC}/lib/pkcs11.c \
		${WRKSRC}/src/p11tool-args.c.bak \
		${WRKSRC}/src/srptool.c
	@${REINPLACE_CMD} \
		's,/etc/pkcs11/modules,${PREFIX}/share/p11-kit/modules,' \
		${WRKSRC}/doc/cha-tokens.texi \
		${WRKSRC}/doc/invoke-p11tool.texi \
		${WRKSRC}/doc/manpages/p11tool.1 \
		${WRKSRC}/src/p11tool-args.c.bak
# Prevent regeneration.  The order is important.
	@${TOUCH} ${WRKSRC}/doc/enums.texi \
		${WRKSRC}/doc/invoke-gnutls-cli.texi \
		${WRKSRC}/doc/invoke-gnutls-cli-debug.texi \
		${WRKSRC}/doc/invoke-gnutls-serv.texi \
		${WRKSRC}/doc/invoke-certtool.texi \
		${WRKSRC}/doc/invoke-ocsptool.texi \
		${WRKSRC}/doc/invoke-danetool.texi \
		${WRKSRC}/doc/invoke-srptool.texi \
		${WRKSRC}/doc/invoke-psktool.texi \
		${WRKSRC}/doc/invoke-p11tool.texi \
		${WRKSRC}/doc/invoke-tpmtool.texi \
		${WRKSRC}/doc/pkcs11-api.texi \
		${WRKSRC}/doc/manpages/stamp_mans \
		${WRKSRC}/doc/stamp_enums \
		${WRKSRC}/doc/stamp_functions

post-install:
	@${RM} ${STAGEDIR}${DOCSDIR}/*.png
	@${RMDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
