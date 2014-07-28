# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	3.2.16
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	GNUPG/gnutls/v3.2

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LICENSE=	GPLv3 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LESSER

LIB_DEPENDS=	libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libidn.so:${PORTSDIR}/dns/libidn \
		libtasn1.so:${PORTSDIR}/security/libtasn1 \
		libtspi.so:${PORTSDIR}/security/trousers

USES=		gmake iconv libtool makeinfo pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-guile \
		--disable-silent-rules \
		--enable-local-libopts
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	MAKEINFOFLAGS=--no-split

OPTIONS_DEFINE=	EXAMPLES LIBDANE NLS
OPTIONS_SUB=	yes

LIBDANE_DESC=		DNSSEC support for DANE (danetool --check)
LIBDANE_LIB_DEPENDS=	libunbound.so:${PORTSDIR}/dns/unbound
LIBDANE_CONFIGURE_ENABLE=	libdane

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

INFO=		gnutls gnutls-guile

post-patch:
	@${RM} ${WRKSRC}/doc/*.info*

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgnutls*.so.*

.include <bsd.port.mk>
