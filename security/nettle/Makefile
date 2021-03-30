# Created by: ijliao
# $FreeBSD$

PORTNAME=	nettle
PORTVERSION=	3.7.2
CATEGORIES=	security
MASTER_SITES=	GNU \
		https://www.lysator.liu.se/~nisse/archive/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-level cryptographic library

LICENSE=	GPLv2+ LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYINGv2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSERv3

BUILD_DEPENDS=	gmp>=6.0.0:math/gmp
LIB_DEPENDS=	libgmp.so:math/gmp

USES=		compiler:c11 gmake localbase makeinfo pathfix

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	M4="/usr/bin/m4 -g"
GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_LDCONFIG=	yes

INFO=		nettle

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
CONFIGURE_ENV+=	CCPIC=-fPIC
.endif

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS = / s| examples||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/libdir=/ s|lib32|lib|' ${WRKSRC}/configure
.if ${ARCH} == "mips64"
	@${REINPLACE_CMD} -e 's|__sgi|__unix__|' ${WRKSRC}/configure
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} NEWS README nettle.html nettle.pdf ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.[ch] ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
