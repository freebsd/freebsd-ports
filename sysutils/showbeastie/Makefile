# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	showbeastie
PORTVERSION=	0.3
CATEGORIES=	sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	t@tobik.me
COMMENT=	Preview FreeBSD loader logos

LICENSE=	BSD2CLAUSE

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=	requires kernel source files in ${SRC_BASE}
.endif

NO_FETCH=	yes

ALL_TARGET=	testmain

PLIST_FILES=	bin/${PORTNAME}

# Make sure building succeeds on HEAD
MAKE_ARGS+=	-m ${SRC_BASE}/share/mk

WRKSRC_SUBDIR=	ficl

pre-patch:
	@${MKDIR} ${WRKSRC}
	@${TAR} -C ${SRC_BASE}/sys/boot \
		--exclude '*.o' --exclude '*.a' --exclude 'testmain' \
		-cf - . | ${TAR} -C ${WRKSRC}/.. -xf -

post-patch:
	${REINPLACE_CMD} 's|-I.*/\.\./common|-I${SRC_BASE}/sys/boot/common|g' \
		${WRKSRC}/Makefile

# Make sure building on FreeBSD 11.0/i386 works. Calls to biospci_* are not
# needed for this program.
	${REINPLACE_CMD} 's|ifdef __i386__|if 0|g' ${WRKSRC}/loader.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/testmain ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
