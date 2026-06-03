PORTNAME=	mgen
DISTVERSION=	5.1.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/USNavalResearchLaboratory/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTNAME=	src-${PORTNAME}-${DISTVERSION}-protolib

MAINTAINER=	dnpowers@me.com
COMMENT=	IP network performance tests and measurements
WWW=		https://www.nrl.navy.mil/Our-Work/Areas-of-Research/Information-Technology/NCS/MGEN/

LICENSE=	NRL
LICENSE_NAME=	Naval Research Laboratory Open Source License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		gmake

MAKEFILE=	Makefile.freebsd
ALL_TARGET=	${PORTNAME}

BUILD_WRKSRC=	${WRKSRC}/makefiles
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|g++|${CXX}|; s|gcc|${CC}|; \
		/CFLAGS =/s|$$|${CFLAGS}|' \
		${WRKSRC}/makefiles/Makefile.freebsd \
		${WRKSRC}/protolib/makefiles/Makefile.freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makefiles/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
		' ! ( -name doxy-config -o -name emacs-tab-setting ) ')
	${INSTALL_DATA} ${README.md VERSION.TXT:L:S|^|${WRKSRC}/|} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
