PORTNAME=	reduce
PORTVERSION=	${SFSUBDIR:S/snapshot_//:S/-//g}
PORTREVISION=	2
CATEGORIES=	math lang
MASTER_SITES=	SF/${PORTNAME}-algebra/${SFSUBDIR}/
DISTNAME=	Reduce-svn6339-src

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Codemist Standard Lisp REDUCE general-purpose computer system
WWW=		http://www.reduce-algebra.com/

LICENSE=	BSD2CLAUSE

BROKEN_armv7=	fails to compile: error: no viable overloaded '=': return *this = int128_t(rhs);
BROKEN_i386=	fails to compile: sysv.S:832:1: changed section flags for .eh_frame, expected: 0x2

BUILD_DEPENDS=	gnuplot:math/gnuplot
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		autoreconf:build libtool gmake ncurses jpeg xorg
USE_XORG=	x11 xcursor xext xorgproto xft xrandr xrender

SFSUBDIR=	snapshot_2022-06-17

TARGET_SDIR=	${ARCH:S/amd64/x86_64/}-unknown-${OPSYS:tl}${OSREL}
CPPFLAGS+=	-I${NCURSESINC}

# Avoid GNU_CONFIGURE as it breaks staging
HAS_CONFIGURE=	yes
ALL_TARGET=

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--with-csl
CPPFLAGS+=	`freetype-config --cflags`
LDFLAGS+=	`freetype-config --libs`

REDUCE_BINS=	${WRKSRC}/cslbuild/${TARGET_SDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${REDUCE_BINS}/csl/reduce.img ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${REDUCE_BINS}/csl/reduce ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${FILESDIR}/runcsl.sh ${STAGEDIR}${PREFIX}/bin/redcsl
	${INSTALL_MAN} ${FILESDIR}/redcsl.1 ${STAGEDIR}${PREFIX}/share/man/man1/
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
