PORTNAME=	dahdi-kmod
PORTVERSION=	${DAHDI_VERSION:S/-//g}
PORTREVISION=	7
CATEGORIES=	misc
MASTER_SITES=	LOCAL/fjoe \
		http://downloads.digium.com/pub/telephony/firmware/releases/:firmware
DISTNAME=	dahdi-freebsd-complete-${DAHDI_VERSION}+${DAHDI_TOOLS_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}\
		oslec-linux-${OSLEC_VERSION}${EXTRACT_SUFX}\
		zaphfc-${ZAPHFC_VERSION}${EXTRACT_SUFX}

MAINTAINER=	dgilbert@eicat.ca
COMMENT=	Digium/Asterisk Hardware Device Interface

BROKEN=		does not compile: use of undeclared identifier 'SX_NOADAPTIVE'

RUN_DEPENDS=	${LOCALBASE}/sbin/dahdi_cfg:misc/dahdi

ONLY_FOR_ARCHS=		amd64 i386 powerpc64 sparc64

DAHDI_VERSION=		2.4.0-rc5
DAHDI_TOOLS_VERSION=	2.4.0-rc1
OSLEC_VERSION=		2.6.35.4
ZAPHFC_VERSION=		r5

FIRMWARES=		OCT6114_064 OCT6114_128 TC400M HX8 ${_vpmadt032}
OCT6114_064_VERSION=	1.05.01
OCT6114_128_VERSION=	1.05.01
TC400M_VERSION=		MR6.12
HX8_VERSION=		2.06
VPMADT032_NAME=		dahdi-fwload-vpmadt032
VPMADT032_DIR=		dahdi_vpmadt032_loader
VPMADT032_VERSION=	1.25.0

WRKSRC=		${WRKDIR}/${DISTNAME}/freebsd
EXTRA_PATCHES=	${WRKDIR}/zaphfc-${ZAPHFC_VERSION}
PATCH_STRIP=	-p1
MAKEFILE=	BSDmakefile
USE_RC_SUBR=	dahdi
MAKE_ARGS=	ADDITIONAL_DRIVERS="wcb1xxp" NO_FETCH=yes DEPEND_MP= WERROR=
GROUPS=		dahdi

CONFLICTS=	zaptel dahdi-kmod26

USES=		kmod uidfix

KMODDIR=	${PREFIX}/lib/dahdi

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "i386"
PLIST_SUB+=	X86=""
_vpmadt032=	VPMADT032
.else
PLIST_SUB+=	X86="@comment "
.endif

.for _f in ${FIRMWARES}
${_f}_NAME?=	dahdi-fw-${_f:tl:S/_/-/g}
${_f}_DIR?=	${${_f}_NAME}.bin
${_f}_DISTFILE=	${${_f}_NAME}-${${_f}_VERSION}.tar.gz
DISTFILES+=	${${_f}_DISTFILE}:firmware
.endfor

post-extract:
	@${LN} -s ../../../linux-${OSLEC_VERSION}/drivers/staging ${WRKSRC}/drivers
.for _f in ${FIRMWARES}
	${CP} ${DISTDIR}/${${_f}_DISTFILE} ${WRKSRC}/freebsd/${${_f}_DIR}
.endfor

fw-versions: extract
.for _v in ${FIRMWARES:=_VERSION}
	@${ECHO_CMD} "${_v}=`${MAKE} -V ${_v} -f ${WRKSRC}/firmware.mk`"
.endfor

.include <bsd.port.post.mk>
