# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	reduce
PORTVERSION=	20141130
CATEGORIES=	math lang
MASTER_SITES=	SF/${PORTNAME}-algebra/${SFSUBDIR}/
DISTNAME=	${PORTNAME}-src-2014-11-30

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	Portable general-purpose computer algebra system

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		autoreconf:build gmake ncurses tar:bzip2
TARGET_SDIR=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=	--build=${TARGET_SDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-I${NCURSESINC}

SFSUBDIR=	Snapshot_2014-11-30-kept-only-for-historical-interest

# Avoid GNU_CONFIGURE as it breaks staging
HAS_CONFIGURE=	yes
ALL_TARGET=

MAKE_JOBS_UNSAFE=	yes

OPTIONS_SINGLE=		SGLSP
OPTIONS_SINGLE_SGLSP=	CSL PSL
CSL_DESC=	Codemist Standard Lisp - redcsl (portable, X11)
PSL_DESC=	Portable Standard Lisp - redpsl (fast, amd64 only)
OPTIONS_DEFAULT=	CSL

CSL_CONFIGURE_WITH=	csl
PSL_CONFIGURE_WITH=	psl
CSL_USE=	xorg=x11,xext,xft
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCSL}
LIB_DEPENDS+=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff
USES+=		jpeg
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`
.else
ONLY_FOR_ARCHS= amd64
.endif

.if ${PORT_OPTIONS:MCSL}
REDUCE_BINS=	${WRKSRC}/cslbuild/${TARGET_SDIR}
.else
REDUCE_BINS=	${WRKSRC}/pslbuild/${TARGET_SDIR}
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MCSL}
	${INSTALL_DATA} ${REDUCE_BINS}/csl/reduce.img ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${REDUCE_BINS}/csl/reduce ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/runcsl.sh ${STAGEDIR}${PREFIX}/bin/redcsl
	${INSTALL_MAN} ${FILESDIR}/redcsl.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DATADIR}/reduce.doc
	(cd ${REDUCE_BINS}/csl/reduce.doc && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/reduce.doc)
	${MKDIR} ${STAGEDIR}${PREFIX}/${FONTDIR}
	(cd ${REDUCE_BINS}/csl/reduce.fonts && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/reduce.fonts)
.else
	${INSTALL_SCRIPT} ${FILESDIR}/runpsl.sh ${STAGEDIR}${PREFIX}/bin/redpsl
	${INSTALL_MAN} ${FILESDIR}/redpsl.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DATADIR}/psl
	${INSTALL_PROGRAM} ${REDUCE_BINS}/psl/bpsl ${STAGEDIR}${DATADIR}/psl/
	(cd ${REDUCE_BINS}/psl && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/psl "! -name bpsl")
	${MKDIR} ${STAGEDIR}${PREFIX}/red
	(cd ${REDUCE_BINS}/red && ${COPYTREE_SHARE} . \
	    ${STAGEDIR}${DATADIR}/red)
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf\
	    ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/primers/*.pdf \
	    ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
