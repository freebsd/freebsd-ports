PORTNAME=	tree-sitter-grammars
DISTVERSIONPREFIX=	v
DISTVERSION=		0.4.2
DISTVERSIONSUFFIX=	+1f9f9dd
CATEGORIES=	textproc
MASTER_SITES+=	https://git.sr.ht/~nbsp/tree-sitter-gemini/archive/:gemini \
		https://git.sr.ht/~ecs/tree-sitter-hare/archive/:hare \
		https://git.sr.ht/~jummit/tree-sitter-wren/archive/:wren \
		https://gitlab.com/gabmus/tree-sitter-blueprint/-/archive/${BLUEPRINT_HASH}/:blueprint \
		https://gitlab.com/TheZoq2/tree-sitter-lpf/-/archive/${LPF_HASH}/:lpf \
		https://gitlab.com/xasc/tree-sitter-t32/-/archive/${T32_HASH}/:t32 \
		https://raw.githubusercontent.com/helix-editor/helix/:lng
DISTFILES+=	${BLUEPRINT_HASH}${EXTRACT_SUFX}:blueprint \
		${LPF_HASH}${EXTRACT_SUFX}:lpf \
		${T32_HASH}${EXTRACT_SUFX}:t32 \
		${GEMINI_HASH}${EXTRACT_SUFX}:gemini \
		${HARE_HASH}${EXTRACT_SUFX}:hare \
		${LANG_HASH}/languages.toml:lng \
		${WREN_HASH}${EXTRACT_SUFX}:wren
EXTRACT_ONLY+=	${_DISTFILES:N*languages.toml}

MAINTAINER=	mikael@FreeBSD.org
COMMENT=	Collection of tree-sitter grammars
WWW=		https://github.com/lapce/tree-sitter-grammars

BUILD_DEPENDS=	tree-sitter:devel/tree-sitter-cli

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	lapce

BLUEPRINT_HASH=	863cea9f83ad5637300478e0559262f1e791684b
LPF_HASH=	db7372e60c722ca7f12ab359e57e6bf7611ab126
T32_HASH=	6da5e3cbabd376b566d04282005e52ffe67ef74a
GEMINI_HASH=	3cc5e4bdf572d5df4277fc2e54d6299bd59a54b3
HARE_HASH=	07035a248943575444aa0b893ffe306e1444c0ab
LANG_HASH=	0a4432b104099534f7a25b8ea4148234db146ab6
WREN_HASH=	6748694be32f11e7ec6b5faeb1b48ca6156d4e06

post-extract:
.for d in blueprint lpf t32 gemini hare wren
	${MKDIR} ${WRKSRC}/grammars/tree-sitter-${d}
.endfor
	${MV} ${WRKDIR}/tree-sitter-blueprint-${BLUEPRINT_HASH}/* ${WRKSRC}/grammars/tree-sitter-blueprint
	${MV} ${WRKDIR}/tree-sitter-lpf-${LPF_HASH}/* ${WRKSRC}/grammars/tree-sitter-lpf
	${MV} ${WRKDIR}/tree-sitter-t32-${T32_HASH}/* ${WRKSRC}/grammars/tree-sitter-t32
	${MV} ${WRKDIR}/tree-sitter-gemini-${GEMINI_HASH}/* ${WRKSRC}/grammars/tree-sitter-gemini
	${MV} ${WRKDIR}/tree-sitter-hare-${HARE_HASH}/* ${WRKSRC}/grammars/tree-sitter-hare
	${MV} ${WRKDIR}/tree-sitter-wren-${WREN_HASH}/* ${WRKSRC}/grammars/tree-sitter-wren

	# Recreate link correctly
.for d in markdown_inline ocaml-interface tsx wast
	${RM} ${WRKSRC}/grammars/tree-sitter-${d}
.endfor
	${LN} -s ${WRKSRC}/grammars/tree-sitter-markdown ${WRKSRC}/grammars/tree-sitter-markdown_inline
	${LN} -s ${WRKSRC}/grammars/tree-sitter-ocaml ${WRKSRC}/grammars/tree-sitter-ocaml-interface
	${LN} -s ${WRKSRC}/grammars/tree-sitter-typescript ${WRKSRC}/grammars/tree-sitter-tsx
	${LN} -s ${WRKSRC}/grammars/tree-sitter-wat ${WRKSRC}/grammars/tree-sitter-wast

	${CP} ${DISTDIR}/${LANG_HASH}/languages.toml ${WRKSRC}

post-build:
	cd ${WRKSRC}; \
		${CARGO_TARGET_DIR}/release/build-tree-sitter --output ./output --tmp ${WRKSRC}/grammars

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/output && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	${ECHO} -n ${DISTVERSION}${DISTVERSIONSUFFIX} > ${STAGEDIR}${DATADIR}/version

.include <Makefile.GH_TUPLE>
.include <bsd.port.mk>
