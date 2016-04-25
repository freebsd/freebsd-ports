# $FreeBSD$

PORTNAME=	mkvalidator
PORTVERSION=	0.5.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool to verify Matroska and WebM files

LICENSE=	BSD3CLAUSE BSD4CLAUSE GPLv2
LICENSE_COMB=	multi

BROKEN_powerpc64=	Does not build

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

USES=		gmake iconv tar:bzip2
HAS_CONFIGURE=	yes
MAKE_ENV=	V=1
MAKEFILE=	GNUmakefile

CFLAGS+=	-I${ICONV_PREFIX}/include
LIBS+=		-L${ICONV_PREFIX}/lib ${ICONV_LIB}

PLIST_FILES=	bin/mkvalidator bin/mkvtree

BROKEN_sparc64=	Build broken on big endian architectures

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e \
		'/STRIP/s|strip|${STRIP_CMD:T}| ; \
		 /CCFLAGS/s|-O3 .* -W|-W|' \
		${WRKSRC}/corec/tools/coremake/gcc_linux*.build
	${REINPLACE_CMD} -e \
		's|/usr/local|$$(DESTDIR)$$(PREFIX)|g' \
		${WRKSRC}/corec/tools/coremake/gcc_mak.inc
	${REINPLACE_CMD} -e \
		's|arm-none-linux-gnueabi-gcc|${CC}| ; \
		 s|arm-none-linux-gnueabi-g++|${CXX}| ; \
		 s|arm-none-linux-gnueabi-ar|${AR}| ; \
		 s|arm-none-linux-gnueabi-strip|${STRIP_CMD}|' \
		${WRKSRC}/corec/tools/coremake/gcc_linux_arm.build

.include <bsd.port.mk>
