PORTNAME=	mkvalidator
PORTVERSION=	0.5.0
CATEGORIES=	multimedia
MASTER_SITES=	SF/matroska/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line tool to verify Matroska and WebM files
WWW=		https://www.matroska.org/downloads/mkvalidator.html

LICENSE=	BSD3CLAUSE BSD4CLAUSE GPLv2
LICENSE_COMB=	multi

BROKEN_mips=		fails to build: gmake[3]: mipsel-linux-gcc: Command not found
BROKEN_mips64=		fails to build: gmake[3]: mipsel-linux-gcc: Command not found
BROKEN_powerpc64=	does not compile: mkvtree.c: error: dereferencing pointer to incomplete type

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}

USES=		cpe gmake iconv localbase tar:bzip2
CPE_VENDOR=	matroska
HAS_CONFIGURE=	yes
MAKE_ENV=	V=1
MAKEFILE=	GNUmakefile

LIBS+=		${ICONV_LIB}

PLIST_FILES=	bin/mkvalidator bin/mkvtree

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/STRIP/s|strip|${STRIP_CMD:T}| ; \
		 /CCFLAGS/s|-O3 .* -W|-W|' \
		${WRKSRC}/corec/tools/coremake/gcc_linux*.build
	@${REINPLACE_CMD} -e \
		's|/usr/local|$$(DESTDIR)$$(PREFIX)|g' \
		${WRKSRC}/corec/tools/coremake/gcc_mak.inc
	@${REINPLACE_CMD} -e \
		's|arm-none-linux-gnueabi-gcc|${CC}| ; \
		 s|arm-none-linux-gnueabi-g++|${CXX}| ; \
		 s|arm-none-linux-gnueabi-ar|${AR}| ; \
		 s|arm-none-linux-gnueabi-strip|${STRIP_CMD}|' \
		${WRKSRC}/corec/tools/coremake/gcc_linux_arm.build

.include <bsd.port.mk>
