# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	3.2.19
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	GNUPG/gnutls/v3.2

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libnettle.so:${PORTSDIR}/security/nettle \
		libtasn1.so:${PORTSDIR}/security/libtasn1

USES=		gmake iconv libtool makeinfo pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-guile \
		--disable-silent-rules \
		--enable-local-libopts
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	MAKEINFOFLAGS=--no-split

OPTIONS_DEFINE=		CRYWRAP EXAMPLES LIBDANE NLS P11KIT TPM ZLIB
OPTIONS_DEFAULT=	CRYWRAP P11KIT TPM ZLIB
OPTIONS_SUB=		yes

CRYWRAP_DESC=			Enable Crywrap TLS proxy service
CRYWRAP_LIB_DEPENDS=		libidn.so:${PORTSDIR}/dns/libidn
CRYWRAP_CONFIGURE_ENABLE=	crywrap

LIBDANE_DESC=			DNSSEC support for DANE (danetool --check)
LIBDANE_LIB_DEPENDS=		libunbound.so:${PORTSDIR}/dns/unbound
LIBDANE_CONFIGURE_ENABLE=	libdane

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

P11KIT_DESC=		PKCS\#11 and p11-kit support
P11KIT_CONFIGURE_WITH=	p11-kit
P11KIT_LIB_DEPENDS=	libp11-kit.so:${PORTSDIR}/security/p11-kit

TPM_DESC=		TPM (trousers) support
TPM_CONFIGURE_WITH=	tpm
TPM_LIB_DEPENDS=	libtspi.so:${PORTSDIR}/security/trousers

ZLIB_CONFIGURE_WITH=	zlib

INFO=		gnutls gnutls-guile

post-patch:
	@${RM} ${WRKSRC}/doc/*.info*
	${SED} -i '' -e 's|^+_NORETURN_H|_NORETURN_H|' \
	  ${WRKSRC}/src/libopts/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnutls*.so.*

.include <bsd.port.mk>
