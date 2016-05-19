# Created by: Weongyo Jeong <weongyo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bwn-firmware
PORTVERSION=	0.1.2
CATEGORIES=	net
MASTER_SITES=	http://downloads.openwrt.org/sources/ \
		http://mirror2.openwrt.org/sources/
PKGNAMESUFFIX=	-kmod
DISTFILES=	${FWFILE} ${FWFILE_LP} ${FWFILE_N}
EXTRACT_ONLY=

MAINTAINER=	swhetzel@gmail.com
COMMENT=	Broadcom AirForce IEEE 802.11 Firmware Kernel Module

BUILD_DEPENDS=	b43-fwcutter:sysutils/b43-fwcutter

FIRMWARES=								\
	ucode ucode5 ucode11 ucode13 ucode14 ucode15			\
	pcm5 a0g1initvals5 a0g0initvals5				\
	b0g0initvals5 b0g0initvals13 a0g1bsinitvals5 a0g0bsinitvals5	\
	b0g0bsinitvals5 						\
	lp0initvals13 lp0initvals14 lp0initvals15 lp0bsinitvals13	\
	lp0bsinitvals14 lp0bsinitvals15					\
	n0initvals11 n0bsinitvals11					\

FIRMWARES_LP=								\
	ucode ucode5 ucode11 ucode13 ucode14 ucode15			\
	pcm5 a0g1initvals5 a0g0initvals5				\
	b0g0initvals5 b0g0initvals13 a0g1bsinitvals5 a0g0bsinitvals5	\
	b0g0bsinitvals5 						\
	lp0initvals13 lp0initvals14 lp0initvals15 lp0bsinitvals13	\
	lp0bsinitvals14 lp0bsinitvals15					\
	n0initvals11 n0bsinitvals11

FIRMWARES_N=								\
	ucode16_mimo							\
	n0initvals16 n0initvals24					\
	n0bsinitvals16 n0bsinitvals24					\

WRKSRC=		${WRKDIR}
FWNAME=		bwn_v4
FWFILE=		broadcom-wl-${FWVERSION}.tar.bz2
FWVERSION=	4.150.10.5
KMODNAME=	${FWNAME}_ucode

FWNAME_LP=	bwn_v4_lp
FWFILE_LP=	broadcom-wl-${FWVERSION_LP}.tar.bz2
FWVERSION_LP=	4.178.10.4
KMODNAME_LP=	${FWNAME_LP}_ucode

FWNAME_N=	bwn_v4_n
FWFILE_N=	broadcom-wl-${FWVERSION_N}.tar.bz2
FWVERSION_N=	5.100.138
KMODNAME_N=	${FWNAME_N}_ucode

PLIST_SUB=	KMODNAME="${KMODNAME}" \
		KMODNAME_LP="${KMODNAME_LP}" \
		KMODNAME_N="${KMODNAME_N}"

NO_PACKAGE=	this is a modified version of a restricted firmware

USES=		kmod uidfix

do-build:
	cd ${WRKSRC} && \
	tar xjf ${DISTDIR}/${FWFILE}
	mkdir -p ${WRKSRC}/bg
	b43-fwcutter -w ${WRKSRC}/bg \
	   ${WRKSRC}/broadcom-wl-${FWVERSION}/driver/wl_apsta_mimo.o
	${TOUCH} ${WRKSRC}/bg/v4/ucode.fw

	@${ECHO_CMD} "KMOD= ${KMODNAME}" > ${WRKSRC}/bg/v4/Makefile
	@${ECHO_CMD} "FIRMWS= ${FIRMWARES:C/.*/&.fw:${FWNAME}_&/}" >> \
		${WRKSRC}/bg/v4/Makefile
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> ${WRKSRC}/bg/v4/Makefile
	@cd ${WRKSRC}/bg/v4; make all

	cd ${WRKSRC} && \
	tar xjf ${DISTDIR}/${FWFILE_LP}
	mkdir -p ${WRKSRC}/lp
	b43-fwcutter -w ${WRKSRC}/lp \
	   ${WRKSRC}/broadcom-wl-${FWVERSION_LP}/linux/wl_apsta.o
	${TOUCH} ${WRKSRC}/lp/v4/ucode.fw
	@${ECHO_CMD} "KMOD= ${KMODNAME_LP}" > ${WRKSRC}/lp/v4/Makefile
	@${ECHO_CMD} "FIRMWS= ${FIRMWARES_LP:C/.*/&.fw:${FWNAME_LP}_&/}" >> \
		${WRKSRC}/lp/v4/Makefile
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> ${WRKSRC}/lp/v4/Makefile
	@cd ${WRKSRC}/lp/v4; make all

	cd ${WRKSRC} && \
	tar xjf ${DISTDIR}/${FWFILE_N}
	mkdir -p ${WRKSRC}/n
	b43-fwcutter -w ${WRKSRC}/n \
	   ${WRKSRC}/broadcom-wl-${FWVERSION_N}/linux/wl_apsta.o
	${TOUCH} ${WRKSRC}/n/v4/ucode.fw
	@${ECHO_CMD} "KMOD= ${KMODNAME_N}" > ${WRKSRC}/n/v4/Makefile
	@${ECHO_CMD} "FIRMWS= ${FIRMWARES_N:C/.*/&.fw:${FWNAME}_&/}" >> \
		${WRKSRC}/n/v4/Makefile
	@${ECHO_CMD} ".include <bsd.kmod.mk>" >> ${WRKSRC}/n/v4/Makefile
	@cd ${WRKSRC}/n/v4; make all


do-install:
	@cd ${WRKSRC}/bg/v4; ${SETENV} ${MAKE_ENV} KMODDIR="${STAGEDIR}${KMODDIR}" make install
	@cd ${WRKSRC}/lp/v4; ${SETENV} ${MAKE_ENV} KMODDIR="${STAGEDIR}${KMODDIR}" make install
	@cd ${WRKSRC}/n/v4; ${SETENV} ${MAKE_ENV} KMODDIR="${STAGEDIR}${KMODDIR}" make install

.include <bsd.port.mk>
