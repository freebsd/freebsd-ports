# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	3.1.22
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.gnutls.org/gcrypt/gnutls/v3.1/
PKGNAMESUFFIX=	${GNUTLS_SUFFIX}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

BUILD_DEPENDS=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
LIB_DEPENDS=	libgpg-error.so:${PORTSDIR}/security/libgpg-error \
		libnettle.so:${PORTSDIR}/security/nettle \
		libp11-kit.so:${PORTSDIR}/security/p11-kit \
		libidn.so:${PORTSDIR}/dns/libidn \
		libunbound.so:${PORTSDIR}/dns/unbound \
		libtspi.so:${PORTSDIR}/security/trousers

GNUTLS_SUFFIX=	3

USES=		gmake iconv pkgconfig
USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack
USE_LDCONFIG=	${PREFIX}/lib/gnutls3
USE_XZ=		yes
CPPFLAGS+=	-I${LOCALBASE}/include -fPIC
LDFLAGS=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=		MAKEINFO=${PREFIX}/bin/makeinfo
CONFIGURE_ARGS=	--program-suffix=${GNUTLS_SUFFIX} \
			--includedir="${PREFIX}/include/gnutls${GNUTLS_SUFFIX}" \
			--libdir="${PREFIX}/lib/gnutls${GNUTLS_SUFFIX}" \
			--disable-guile \
			--disable-nls \
			--disable-silent-rules \
			--disable-hardware-acceleration \
			--enable-local-libopts

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${GNUTLS_SUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${GNUTLS_SUFFIX}
INFO_SUBDIR=	gnutls${GNUTLS_SUFFIX}

OPTIONS_DEFINE=		CXX DOCS EXAMPLES LIBTASN1
OPTIONS_DEFAULT=	CXX
OPTIONS_SUB=		yes

LIBTASN1_DESC=	Use libtasn1 from ports

CXX_CONFIGURE_ENABLE=	cxx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBTASN1} || exists(${LOCALBASE}/lib/libtasn1.so.7)
LIB_DEPENDS+=	libtasn1.so:${PORTSDIR}/security/libtasn1
.else
CONFIGURE_ARGS+=	--with-included-libtasn1
.endif

PORTDOCS=		AUTHORS NEWS README THANKS
EXAMPLES=	doc/examples/*.c

#INFO=	gnutls

post-patch:
	@${MV} ${WRKSRC}/libdane/gnutls-dane.pc.in \
		${WRKSRC}/libdane/gnutls${GNUTLS_SUFFIX}-dane.pc.in

pre-configure:
	@${CP} ${WRKSRC}/lib/gnutls.pc.in ${WRKSRC}/lib/gnutls${GNUTLS_SUFFIX}.pc.in
	@${REINPLACE_CMD} \
		-e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		-e 's,gnutls\.pc,gnutls${GNUTLS_SUFFIX}\.pc,g' \
		-e 's,gnutls-dane\.pc,gnutls${GNUTLS_SUFFIX}-dane\.pc,g' \
		${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/libdane/Makefile.in \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,(top_builddir)$$,(top_builddir) -I$$(top_builddir)/lib/includes -I$$(top_builddir)/libextra/includes,' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
