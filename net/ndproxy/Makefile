PORTNAME=	ndproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3
CATEGORIES=	net

MAINTAINER=	fbsd.bugzilla@fenyo.net
COMMENT=	Implementation of IPv6 Neighbor Discovery proxy
WWW=		http://www.fenyo.net/newweb/ndproxy.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler kmod
USE_GITHUB=	yes
GH_ACCOUNT=	AlexandreFenyo
USE_RC_SUBR=	${PORTNAME}

# build for a kernel with 'options VIMAGE'
CFLAGS+=	-DVIMAGE ${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_gcc=	-Wno-error=strict-prototypes

SUB_FILES=	pkg-message

PLIST_FILES=	${KMODDIR}/${PORTNAME}.ko share/man/man4/${PORTNAME}.4.gz
PORTDOCS=	README.md TESTING.TXT \
		${PORTNAME}.html ${PORTNAME}.pdf ${PORTNAME}.ps \
		network-architecture.png

OPTIONS_DEFINE=	DOCS

pre-build:
	(cd ${BUILD_WRKSRC}; ${MAKE} depend)

do-install:
	${INSTALL_KLD} ${WRKSRC}/${PORTNAME}.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.4 ${STAGEDIR}${PREFIX}/share/man/man4/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
