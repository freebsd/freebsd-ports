# Created by: Emmanuel Vadot <manu@freebsd.org>
# $FreeBSD$

PORTNAME=	u-boot-tools
DISTVERSION=	2019.10
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
DISTNAME=	u-boot-${PORTVERSION}

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	U-boot related tools

LICENSE=	GPLv2

USES=	bison tar:bzip2 gmake python:2.7,build ssl

BROKEN_SSL=	libressl
BROKEN_SSL_REASON_libressl=	not supported by the upstream

CONFLICTS=	uboot-mkimage
ALL_TARGET=	tools-only
MAKE_ARGS=	ARCH=sandbox \
		CC="${CC}" \
		HOSTCC="${CC}" \
		KBUILD_VERBOSE=1 \
		NOSTDINC_FLAGS="" \

PLIST_FILES=	bin/mkimage bin/mkenvimage bin/dumpimage bin/fit_info

do-configure:
	(cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} sandbox_defconfig)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/dumpimage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fit_info ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkenvimage ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkimage ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
