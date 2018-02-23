# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	reduce
PORTVERSION=	20180117
CATEGORIES=	math lang
MASTER_SITES=	SF/${PORTNAME}-algebra/${SFSUBDIR}/
DISTNAME=	Reduce-svn4372-src

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	REDUCE Codemist Standard Lisp general-purpose computer system

LICENSE=	BSD2CLAUSE

BROKEN_powerpc64=	fails to compile: arith01.cpp: 'statuc' does not name a type

RUN_DEPENDS=	gnuplot:math/gnuplot

LIB_DEPENDS+=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

MAKE_JOBS_UNSAFE=	yes

SFSUBDIR=	snapshot_2018-01-17

USES=		autoreconf:build libtool gmake ncurses
TARGET_SDIR=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS=	--build=${TARGET_SDIR}
WRKSRC=		${WRKDIR}/${DISTNAME}
CPPFLAGS+=	-I${NCURSESINC}

# Avoid GNU_CONFIGURE as it breaks staging
HAS_CONFIGURE=	yes
ALL_TARGET=

USE_XORG=	x11 xext xproto xft
USES+=		jpeg
CONFIGURE_ARGS=	--with-csl
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`

REDUCE_BINS=	${WRKSRC}/cslbuild/${TARGET_SDIR}

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/manual.pdf\
	    ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/primers/*.pdf \
	    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
