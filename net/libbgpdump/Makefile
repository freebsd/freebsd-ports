PORTNAME=	libbgpdump
DISTVERSION=	1.6.2
CATEGORIES=	net
MASTER_SITES=	https://github.com/RIPE-NCC/bgpdump/releases/download/v${DISTVERSION}/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Analyzing dump files produced by Zebra/Quagga or MRT
WWW=		https://github.com/RIPE-NCC/bgpdump/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
SOVER=		0
MAKE_ARGS=	SOFLAGS="-shared -Wl,-soname,${PORTNAME}.so.${SOVER}"
PLIST_SUB=	SOVER=${SOVER}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bgpdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/${PORTNAME}.* ${STAGEDIR}${PREFIX}/lib
	${RLN}  ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.${SOVER}
	${INSTALL_DATA} \
		${bgpdump_attr.h bgpdump_formats.h bgpdump_lib.h bgpdump_mstream.h \
		:L:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/include

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
