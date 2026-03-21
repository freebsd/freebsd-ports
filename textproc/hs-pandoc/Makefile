PORTNAME=	pandoc
DISTVERSION=	3.9.0.2
CATEGORIES=	textproc haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Conversion between markup formats
WWW=		https://pandoc.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		cabal cpe

CABAL_WRAPPER_SCRIPTS=	${CABAL_EXECUTABLES}

OPTIONS_DEFINE=	EMBED_DATA
OPTIONS_SUB=	yes

EMBED_DATA_DESC=	Embed data files in binary for relocatable executable
EMBED_DATA_CABAL_FLAGS=	embed_data_files

HACKAGE_DISTNAME=	pandoc-cli-${DISTVERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMBED_DATA}
# No need to use wrapper scripts when all data is compiled into an executable
.undef CABAL_WRAPPER_SCRIPTS
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
# compiler goes out of memory
BUILD_ARGS+=	--disable-optimization
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/pandoc.1 ${STAGEDIR}${MANDIRS}/man1
	${INSTALL_MAN} ${WRKSRC}/man/pandoc-lua.1 ${STAGEDIR}${MANDIRS}/man1
	${INSTALL_MAN} ${WRKSRC}/man/pandoc-server.1 ${STAGEDIR}${MANDIRS}/man1

post-install-EMBED_DATA-off:
	cd ${CABAL_DEPSDIR}/${PORTNAME}-${PORTVERSION} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
