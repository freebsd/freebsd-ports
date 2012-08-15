# New ports collection makefile for:	gnutls
# Date created:				13 Nov 2002
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	gnutls
PORTVERSION=	2.12.18
PORTREVISION=	1
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GNU Transport Layer Security library

LIB_DEPENDS=	nettle:${PORTSDIR}/security/nettle \
		gpg-error:${PORTSDIR}/security/libgpg-error \
		p11-kit:${PORTSDIR}/security/p11-kit

CONFLICTS=	gnutls-devel-[0-9]*

USE_BZIP2=	yes
USE_ICONV=	yes
USE_PKGCONFIG=	build
USE_GNOME=	ltverhack gnomehack
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-fPIC
CONFIGURE_ARGS+=	--disable-guile
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if defined(WITH_LIBTASN1)
LIB_DEPENDS+=	tasn1:${PORTSDIR}/security/libtasn1
.else
CONFIGURE_ARGS+=	--with-included-libtasn1
.endif

.if defined(WITH_LZO)
LIB_DEPENDS+=		lzo2:${PORTSDIR}/archivers/lzo2
CONFIGURE_ARGS+=	--with-lzo
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
.include <bsd.port.post.mk>
