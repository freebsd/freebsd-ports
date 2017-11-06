# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	memtest86+
PORTVERSION=	5.01
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.memtest.org/download/${PORTVERSION}/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Stand-alone memory test for x86 architecture computers

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

USES=	gmake
ALL_TARGET=	all
PORTDOCS=	*

USE_GCC=	4.8

# Please provide absolute path below (cannot be root)
BOOT_DIR?=	/boot/opt

OPTIONS_DEFINE=	SERIAL HISPEED DOCS
OPTIONS_DEFAULT=	BOOT
OPTIONS_MULTI=	BOOT_TYPE
OPTIONS_MULTI_BOOT_TYPE=	ISO BOOT
ISO_DESC=	Build bootable ISO image
BOOT_DESC=	Build ELF image loadable by boot2 and loader
SERIAL_DESC=	Enable serial console at COM1/9600
HISPEED_DESC=	Set COM1 serial console speed to 115200

ISO_PLIST_FILES=	${DATADIR}/mt${PORTVERSION:C/\.//}.iso
ISO_BUILD_DEPENDS=	genisoimage:sysutils/genisoimage
ISO_ALL_TARGET=	iso
BOOT_PLIST_FILES=	${BOOT_DIR}/memtest86+
BOOT_PLIST_DIRS=	${BOOT_DIR}
BOOT_SUB_FILES=	pkg-message
BOOT_SUB_LIST+=	BOOT_DIR=${BOOT_DIR}

pre-fetch:
.if !defined(PACKAGE_BUILDING)
	@${ECHO} "If you only need bootable ISO image of memtest86+, you can"
	@${ECHO} "simply download it from http://www.memtest.org/.  Use this"
	@${ECHO} "port if you need ELF image of memtest86+ that can be loaded"
	@${ECHO} "by boot2 or loader(8), or if you want to use this port to"
	@${ECHO} "build ISO image with custom tweaks in memtest86+ code."
.endif

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/Makefile
.if ${PORT_OPTIONS:MSERIAL}
	${REINPLACE_CMD} -e 's|SERIAL_CONSOLE_DEFAULT 0|SERIAL_CONSOLE_DEFAULT 1|' ${WRKSRC}/config.h
. if ${PORT_OPTIONS:MHISPEED}
	${REINPLACE_CMD} -e 's|9600|115200|' ${WRKSRC}/config.h
. endif
.endif

do-install:
.if ${PORT_OPTIONS:MISO}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mt${PORTVERSION:C/\.//}.iso ${STAGEDIR}${DATADIR}
.endif
.if ${PORT_OPTIONS:MBOOT}
	@${MKDIR} ${STAGEDIR}${BOOT_DIR}
# XXX is INSTALL_KLD really appropriate here? XXX
	${INSTALL_KLD} ${WRKSRC}/memtest ${STAGEDIR}${BOOT_DIR}/memtest86+
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
