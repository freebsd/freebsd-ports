# New ports collection makefile for:	bwi-firmware-kmod
# Date created:				May 01 2009
# Whom:					Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bwi-firmware
PORTVERSION=	${FWVERSION}
CATEGORIES=	net kld
MASTER_SITES=	http://downloads.openwrt.org/sources/ \
		http://people.freebsd.org/~thompsa/:fwcutter
PKGNAMESUFFIX=	-kmod
DISTFILES=	${FWFILE} b43-fwcutter-freebsd.tar.bz2:fwcutter
EXTRACT_ONLY=	b43-fwcutter-freebsd.tar.bz2

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Broadcom AirForce IEEE 802.11 Firmware Kernel Module

FIRMWARES=	ucode ucode11 ucode2 ucode4 ucode5 \
		a0g0bsinitvals2 a0g0bsinitvals5 a0g0initvals2 \
		a0g0initvals5 a0g1bsinitvals5 a0g1initvals5 \
		b0g0bsinitvals2 b0g0bsinitvals5 b0g0initvals2 b0g0initvals5 \
		pcm4 pcm5

WRKSRC=		${WRKDIR}
FWNAME=		bwi_v3
FWFILE=		wl_apsta-${FWVERSION}.0.o
FWVERSION=	3.130.20
KMODDIR=	/boot/modules
KMODNAME=	${FWNAME}_ucode
PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODDIR="${KMODDIR}"

NO_PACKAGE=	this is a modified version of a restricted firmware

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} &&  \
	${CC} ${CFLAGS} -DFWCUTTER_VERSION_=008 -c fwcutter.c && \
	${CC} ${CFLAGS} -DFWCUTTER_VERSION_=008 -c md5.c && \
	${CC} ${CFLAGS} -o b43-fwcutter fwcutter.o md5.o
	${WRKSRC}/b43-fwcutter -w ${WRKSRC} ${DISTDIR}/${FWFILE}
	${TOUCH} ${WRKSRC}/v3/ucode.fw

	@${ECHO_CMD} "KMOD= ${KMODNAME}" > ${WRKSRC}/v3/Makefile
	@${ECHO_CMD} "FIRMWS= ${FIRMWARES:C/.*/&.fw:${FWNAME}_&/}" >> \
		${WRKSRC}/v3/Makefile
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> ${WRKSRC}/v3/Makefile
	@cd ${WRKSRC}/v3; ${SETENV} KMODDIR="${KMODDIR}" make all

do-install:
	@cd ${WRKSRC}/v3; ${SETENV} KMODDIR="${KMODDIR}" make install

.include <bsd.port.post.mk>
