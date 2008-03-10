# New ports collection makefile for:	gnutls-devel
# Date created:				27 Aug 2006
# Whom:					Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	2.3.3
CATEGORIES=	security net
MASTER_SITES=	http://alpha.gnu.org/gnu/gnutls/ \
		ftp://alpha.gnu.org/gnu/gnutls/
PKGNAMESUFFIX=	-devel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	gcrypt.15:${PORTSDIR}/security/libgcrypt \
		gpg-error.0:${PORTSDIR}/security/libgpg-error

CONFLICTS=	gnutls-[0-9]*

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig ltverhack
USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--with-included-lzo
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>
.if defined(WITH_OPENCDK) || exists(${LOCALBASE}/lib/libopencdk.so.9)
LIB_DEPENDS+=	opencdk.9:${PORTSDIR}/security/opencdk
.endif

.if defined(WITH_LIBTASN1) || exists(${LOCALBASE}/lib/libtasn1.so.3)
LIB_DEPENDS+=	tasn1.3:${PORTSDIR}/security/libtasn1
.endif

.if ${OSVERSION} < 600000
BUILD_DEPENDS+=	${LOCALBASE}/bin/makeinfo:${PORTSDIR}/print/texinfo
CONFIGURE_ENV+=	MAKEINFO="${LOCALBASE}/bin/makeinfo"
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

post-patch:
	@${REINPLACE_CMD} -e 's,(libdir)/pkgconfig,(prefix)/libdata/pkgconfig,' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/libextra/Makefile.in

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
