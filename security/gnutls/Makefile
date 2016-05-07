# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	3.4.11
CATEGORIES=	security net
MASTER_SITES=	GNUPG/gnutls/v${PORTVERSION:R}

MAINTAINER=	tijl@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libnettle.so:security/nettle \
		libtasn1.so:security/libtasn1
BUILD_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USES=		cpe gmake iconv libtool makeinfo pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-guile \
		--disable-silent-rules \
		--enable-local-libopts \
		ac_cv_type_max_align_t=yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_ENV=	MAKEINFOFLAGS=--no-split
INSTALL_TARGET=	install-strip

CPE_VENDOR=	gnu

OPTIONS_DEFINE=		CRYWRAP DANE EXAMPLES IDN NLS P11KIT TPM ZLIB
OPTIONS_DEFAULT=	CRYWRAP IDN P11KIT TPM ZLIB
OPTIONS_SUB=		yes

CRYWRAP_DESC=			Enable Crywrap TLS proxy service
CRYWRAP_IMPLIES=		IDN
CRYWRAP_CONFIGURE_ENABLE=	crywrap

DANE_DESC=		Certificate verification via DNSSEC
DANE_LIB_DEPENDS=	libunbound.so:dns/unbound
DANE_CONFIGURE_ENABLE=	libdane

IDN_CONFIGURE_WITH=	idn
IDN_LIB_DEPENDS=	libidn.so:dns/libidn

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

P11KIT_DESC=		PKCS\#11 and p11-kit support
P11KIT_CONFIGURE_WITH=	p11-kit
P11KIT_LIB_DEPENDS=	libp11-kit.so:security/p11-kit

TPM_DESC=		TPM (trousers) support
TPM_CONFIGURE_WITH=	tpm
TPM_LIB_DEPENDS=	libtspi.so:security/trousers

ZLIB_CONFIGURE_WITH=	zlib

INFO=		gnutls gnutls-guile

post-patch:
	@${RM} ${WRKSRC}/doc/*.info*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
