# Created by: Tobias Kortkamp <t@tobik.me>
# $FreeBSD$

PORTNAME=	showbeastie
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=
DISTFILES=

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

pre-patch:
	@${MKDIR} ${WRKSRC}
	@${TAR} -C ${SRC_BASE}/sys/boot/ficl \
		--exclude '*.o' --exclude '*.a' --exclude 'testmain' \
		-cf - . | ${TAR} -C ${WRKSRC} -xf -

post-patch:
	${REINPLACE_CMD} 's|-I.*/\.\./common|-I${SRC_BASE}/sys/boot/common|g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/testmain ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
