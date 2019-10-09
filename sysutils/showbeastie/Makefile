# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	showbeastie
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Preview FreeBSD loader logos

LICENSE=	BSD2CLAUSE

BROKEN_armv6=		fails to link: testmain uses VFP register arguments, dict.o does not
BROKEN_armv7=		fails to link: testmain uses VFP register arguments, dict.o does not
BROKEN_mips64=		fails to link: relocation truncated to fit: R_MIPS_26 against `__assert@@FBSD_1.0'
BROKEN_FreeBSD_12=	fails to build: ficl/Makefile line 13: Could not find bsd.stand.mk
BROKEN_FreeBSD_13=	fails to build: ficl/Makefile line 13: Could not find bsd.stand.mk

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

ALL_TARGET=	testmain

PLIST_FILES=	bin/${PORTNAME}

# Make sure building succeeds on HEAD
CFLAGS+=	-I/usr/include # uses -nostdinc
MAKE_ARGS+=	-m ${SRC_BASE}/share/mk

WRKSRC_SUBDIR=	ficl

.if exists(${SRC_BASE}/sys/boot/ficl/testmain.c)
SRC_STAND=	${SRC_BASE}/sys/boot
.else
SRC_STAND=	${SRC_BASE}/stand
.endif

pre-patch:
	@${MKDIR} ${WRKSRC}
	@${TAR} -C ${SRC_STAND} \
		--exclude '*.o' --exclude '*.a' --exclude 'testmain' \
		-cf - . | ${TAR} -C ${WRKSRC}/.. -xf -

post-patch:
	@${REINPLACE_CMD} 's|-I.*/\.\./common|-I${SRC_STAND}/common|g' \
		${WRKSRC}/Makefile
	@if [ -f "${WRKSRC}/../defs.mk" ]; then \
		${REINPLACE_CMD} '/jagged-little-pill/d' ${WRKSRC}/../defs.mk \
	; fi
# Make sure building on FreeBSD 11.0/i386 works. Calls to biospci_* are not
# needed for this program.
	@${REINPLACE_CMD} 's|ifdef __i386__|if 0|g' ${WRKSRC}/loader.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/testmain ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
