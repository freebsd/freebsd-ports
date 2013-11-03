# Created by: Sergei Kolobov <sergei@kolobov.com>
# $FreeBSD$

PORTNAME=	gnutls
PORTVERSION=	2.12.23
PORTREVISION=	2
CATEGORIES=	security net
MASTER_SITES=	\
	ftp://ftp.gnutls.org/gcrypt/gnutls/v${PORTVERSION:C/.[0-9]+$//}/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	nettle:${PORTSDIR}/security/nettle \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		p11-kit:${PORTSDIR}/security/p11-kit

CONFLICTS=	gnutls-devel-[0-9]*

USES=		pathfix pkgconfig iconv
USE_BZIP2=	yes
USE_GNOME=	ltverhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
LIBTOOLFILES=	configure lib/configure libextra/configure
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-fPIC
CONFIGURE_ARGS+=	--disable-guile
MANCOMPRESSED=	no

OPTIONS_DEFINE=	LIBTASN1 CXX LZO NLS

LIBTASN1_DESC=	Use system libtasn1 instead of local one
CXX_DESC=	Install C++ library
LZO_DESC=	LZO compression

OPTIONS_DEFAULT=	LIBTASN1 CXX

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBTASN1}
LIB_DEPENDS+=	tasn1:${PORTSDIR}/security/libtasn1
.else
CONFIGURE_ARGS+=	--with-included-libtasn1
.endif

.if ${PORT_OPTIONS:MLZO}
LIB_DEPENDS+=		lzo2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--with-lzo
.endif

.if ${PORT_OPTIONS:MCXX}
CONFIGURE_ARGS+=	--disable-cxx
PLIST_SUB+=		CXX="@comment "
.else
PLIST_SUB+=		CXX=""
.endif

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USES+=		gettext
PLIST_SUB+=		NLS=""
.endif

PORTDOCS=		AUTHORS NEWS README THANKS
PORTEXAMPLES=		*.c

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -type f | ${XARGS} ${REINPLACE_CMD} \
		-e 's|[$$][(]LTLIBPTHREAD[)]||g'

post-install:
.if !defined (NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES:C,^,doc/examples/,} \
		${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.mk>
