# Created by: ijliao
# $FreeBSD$

PORTNAME=	nettle
PORTVERSION=	3.2
CATEGORIES=	security
MASTER_SITES=	GNU \
		http://www.lysator.liu.se/~nisse/archive/:liu \
		ftp://ftp.lysator.liu.se/pub/security/lsh/:liu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Low-level cryptographic library

LICENSE=	LGPL3 GPLv2+
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		gmake makeinfo
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	M4="/usr/bin/m4 -g"
CONFIGURE_ARGS=	--enable-shared
MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

PORTDOCS=	NEWS README TODO nettle.html nettle.pdf
PORTEXAMPLES=	*.c *.h
INFO=		nettle

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
CONFIGURE_ENV+=	CCPIC=-fPIC
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} \
		${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
