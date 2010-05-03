# New ports collection makefile for:	gnutls-devel
# Date created:				8 Jan 2009
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	2.9.10
CATEGORIES=	security net
MASTER_SITES=	http://alpha.gnu.org/gnu/gnutls/
PKGNAMESUFFIX=	-devel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.16:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

CONFLICTS=	gnutls-[0-9]*

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GNOME=	pkgconfig ltverhack
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -fPIC" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--disable-guile
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if (defined(WITH_LIBTASN1) || exists(${LOCALBASE}/lib/libtasn1.so.4)) && !defined(WITHOUT_LIBTASN1)
LIB_DEPENDS+=	tasn1.4:${PORTSDIR}/security/libtasn1
.else
CONFIGURE_ARGS+=	--with-included-libtasn1
.endif

.if (defined(WITH_LZO) || exists(${LOCALBASE}/lib/liblzo2.so)) && !defined(WITHOUT_LZO)
LIB_DEPENDS+=		lzo2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--with-lzo
.else
CONFIGURE_ARGS+=	--with-lzo=no
.endif

.if defined(WITHOUT_CXX)
CONFIGURE_ARGS+=	--disable-cxx
PLIST_SUB+=		CXX="@comment "
.else
PLIST_SUB+=		CXX=""
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=		AUTHORS NEWS README THANKS
.endif
EXAMPLES=	doc/examples/*.c

pre-configure:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/libextra/Makefile.in
	@${REINPLACE_CMD} -e 's,(top_builddir)$$,(top_builddir) -I$$(top_builddir)/lib/includes -I$$(top_builddir)/libextra/includes,' \
		${WRKSRC}/doc/Makefile.in

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include "Makefile.man"
.include <bsd.port.post.mk>
