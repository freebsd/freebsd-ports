# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dolly
DISTVERSION=	0.58C
CATEGORIES=	sysutils net
MASTER_SITES=	http://www.cs.inf.ethz.ch/CoPs/patagonia/dolly/
DISTNAME=	${PORTNAME}.${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to clone harddisks/partitions over a fast switched network

OPTIONS_DEFINE=	BZIP2 HIGHEST_COMPRESSION DOCS
OPTIONS_DEFAULT=	BZIP2 HIGHEST_COMPRESSION
BZIP2_DESC=	bzip2 instead of gzip for compressing
HIGHEST_COMPRESSION_DESC=	Highest rather than fastest compression

DOCS=		README

.include <bsd.port.options.mk>
do-configure:
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(CFLAGS[[:space:]]*=.*)$$|\1 ${CFLAGS}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
. for _file in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${_file} ${STAGEDIR}${DOCSDIR}/
. endfor
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

# Correctly depend upon bzip2 if necessary
.if ${PORT_OPTIONS:MBZIP2}
EXTRA_PATCHES+=	${FILESDIR}/extra-bzip2-patch-dolly.c
.endif

post-patch:
# fix comment error
	@${REINPLACE_CMD} -E \
		-e 's|use gzip|use gunzip|' \
		${WRKSRC}/dolly.c
# Properly reference bzip2 instead of gzip
.if ${PORT_OPTIONS:MBZIP2}
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/gzip|${BZIP2_CMD}|' \
		-e 's|gzip|bzip2|' \
		-e 's|/usr/bin/gunzip|${BZCAT}|' \
		${WRKSRC}/dolly.c
# Use specific FreeBSD references
# Fix spelling
	@${REINPLACE_CMD} -E \
		-e 's|gnu-zipped|bzipped|' \
		-e 's|sda([[:digit:]])|da\1|g' \
		-e 's|/sda|/da|g' \
		-e 's|sda_|da_|g' \
		-e 's|hypennormal|hyphennormal|' \
		${WRKSRC}/README
	@${REINPLACE_CMD} -E \
		-e 's|gunzip|bzcat|' \
		-e 's|\.gz|\.bz2|g' \
		${WRKSRC}/*
.endif
# Highest compression possible
.if ${PORT_OPTIONS:MHIGHEST_COMPRESSION}
	@${REINPLACE_CMD} -E \
		-e 's|-cf|-9cf|' \
		${WRKSRC}/dolly.c
.endif

.include <bsd.port.mk>
