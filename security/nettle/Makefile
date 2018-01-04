# Created by: ijliao
# $FreeBSD$

PORTNAME=	nettle
PORTVERSION=	3.4
CATEGORIES=	security
MASTER_SITES=	GNU \
		http://www.lysator.liu.se/~nisse/archive/ 

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Low-level cryptographic library

LICENSE=	GPLv2+ LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYINGv2
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYINGv3
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LESSERv3

LIB_DEPENDS=	libgmp.so:math/gmp

OPTIONS_DEFINE=	DOCS EXAMPLES

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	M4="/usr/bin/m4 -g"
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake localbase makeinfo pathfix

INFO=		nettle
PORTDOCS=	NEWS README TODO nettle.html nettle.pdf
PORTEXAMPLES=	*.c *.h

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
CONFIGURE_ENV+=	CCPIC=-fPIC
.endif

.if ${ARCH} == "mips64"
post-patch:
	@${REINPLACE_CMD} -e 's|__sgi|__unix__|' ${WRKSRC}/configure
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
