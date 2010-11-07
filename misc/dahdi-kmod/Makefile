# Ports collection makefile for:	dahdi
# Date created:				3 Mar 2010
# Whom:					Maxim Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dahdi
PORTVERSION=	${DAHDI_VERSION:S/-//g}
PORTREVISION=	4
CATEGORIES=	misc kld
MASTER_SITES=	${MASTER_SITE_LOCAL}\
		http://downloads.digium.com/pub/telephony/firmware/releases/:firmware
MASTER_SITE_SUBDIR=	fjoe
DISTNAME=	${PORTNAME}-freebsd-complete-${DAHDI_VERSION}+${DAHDI_TOOLS_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}\
		oslec-linux-${OSLEC_VERSION}${EXTRACT_SUFX}\
		zaphfc-${ZAPHFC_VERSION}${EXTRACT_SUFX}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Digium/Asterisk Hardware Device Interface

BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
LIB_DEPENDS=	newt.52:${PORTSDIR}/devel/newt

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

EXTRA_PATCHES=	${WRKDIR}/zaphfc-${ZAPHFC_VERSION}
NO_PACKAGE=	Should be in sync with the kernel to work correctly
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dahdi=../freebsd --sysconfdir=${PREFIX}/etc --with-newt=${LOCALBASE}
CONFIGURE_ENV=	WGET=/usr/bin/fetch
USE_LDCONFIG=	yes
USE_RC_SUBR=	dahdi
MAKE_ARGS=	ADDITIONAL_DRIVERS="wcb1xxp" NO_FETCH=yes
GROUPS=		dahdi

ONLY_FOR_ARCHS=	i386 amd64 sparc64
CONFLICTS=	zaptel-[0-9]*

MAN8=	dahdi_cfg.8\
	dahdi_monitor.8\
	dahdi_scan.8\
	dahdi_test.8\
	dahdi_tool.8\
	fxotune.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 703000 || (${OSVERSION} >= 800000 && ${OSVERSION} < 800108)
IGNORE=		requires firmware(9) support for kernel modules with hyphens
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
PLIST_SUB+=	X86=""
_vpmadt032=	VPMADT032
.else
PLIST_SUB+=	X86="@comment "
.endif

.for _f in ${FIRMWARES}
${_f}_NAME?=	dahdi-fw-${_f:L:S/_/-/g}
${_f}_DIR?=	${${_f}_NAME}.bin
${_f}_DISTFILE=	${${_f}_NAME}-${${_f}_VERSION}.tar.gz
DISTFILES+=	${${_f}_DISTFILE}:firmware
.endfor

pre-everything::
	@if [ ! -f /usr/src/sys/Makefile ]; then \
		${ECHO_MSG} ">> The dahdi port needs FreeBSD kernel source code to compile."; \
		${ECHO_MSG} ">> Please install FreeBSD kernel source code in /usr/src/sys."; \
		${FALSE}; \
	fi

post-extract:
	@${LN} -s ../../../linux-${OSLEC_VERSION}/drivers/staging ${WRKSRC}/freebsd/drivers
	@${REINPLACE_CMD} -E -e 's,(new|old)/,freebsd/,g' ${WRKDIR}/zaphfc-${ZAPHFC_VERSION}
.for _f in ${FIRMWARES}
	${CP} ${DISTDIR}/${${_f}_DISTFILE} ${WRKSRC}/freebsd/freebsd/${${_f}_DIR}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,g'\
		${WRKSRC}/tools/dahdi_cfg.c ${WRKSRC}/tools/fxotune.c\
		${WRKSRC}/tools/doc/dahdi_cfg.8 ${WRKSRC}/tools/doc/fxotune.8

pre-su-install:
	@${MKDIR} ${PREFIX}/lib/dahdi

post-install:
	@${TOUCH} ${PREFIX}/lib/dahdi/linker.hints

fw-versions: extract
.for _v in ${FIRMWARES:=_VERSION}
	@${ECHO_CMD} "${_v}=`${MAKE} -V ${_v} -f ${WRKSRC}/freebsd/firmware.mk`"
.endfor

.include <bsd.port.post.mk>
