# Ports collection makefile for:	dahdi
# Date created:				3 Mar 2010
# Whom:					Maxim Khon <fjoe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dahdi
PORTVERSION=	${DAHDI_VERSION:S/-//g}
PORTREVISION=	0
CATEGORIES=	misc kld
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fjoe
DISTNAME=	${PORTNAME}-freebsd-complete-${DAHDI_VERSION}+${DAHDI_TOOLS_VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}\
		oslec-linux-${OSLEC_VERSION}${EXTRACT_SUFX}\
		zaphfc-${ZAPHFC_VERSION}${EXTRACT_SUFX}

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Digium/Asterisk Hardware Device Interface

BUILD_DEPENDS=	gmake:${PORTSDIR}/devel/gmake
LIB_DEPENDS=	newt.52:${PORTSDIR}/devel/newt

DAHDI_VERSION=		2.4.0-rc4
DAHDI_TOOLS_VERSION=	2.4.0-rc1
OSLEC_VERSION=		2.6.35.4
ZAPHFC_VERSION=		r5

EXTRA_PATCHES=	${WRKDIR}/zaphfc-${ZAPHFC_VERSION}
NO_PACKAGE=	Should be in sync with the kernel to work correctly
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dahdi=../freebsd --sysconfdir=${PREFIX}/etc --with-newt=${LOCALBASE}
CONFIGURE_ENV=	WGET=/usr/bin/fetch
USE_LDCONFIG=	yes
USE_RC_SUBR=	dahdi
MAKE_ARGS=	ADDITIONAL_DRIVERS="wcb1xxp"

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
.else
PLIST_SUB+=	X86="@comment "
.endif

pre-everything::
	@if [ ! -f /usr/src/sys/Makefile ]; then \
		${ECHO_MSG} ">> The dahdi port needs FreeBSD kernel source code to compile."; \
		${ECHO_MSG} ">> Please install FreeBSD kernel source code in /usr/src/sys."; \
		${FALSE}; \
	fi

post-extract:
	@${LN} -s ../../../linux-${OSLEC_VERSION}/drivers/staging ${WRKSRC}/freebsd/drivers
	@${REINPLACE_CMD} -E -e 's,(new|old)/,freebsd/,g' ${WRKDIR}/zaphfc-${ZAPHFC_VERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,/etc,${PREFIX}/etc,g'\
		${WRKSRC}/tools/dahdi_cfg.c ${WRKSRC}/tools/fxotune.c\
		${WRKSRC}/tools/doc/dahdi_cfg.8 ${WRKSRC}/tools/doc/fxotune.8

pre-su-install:
	@${MKDIR} ${PREFIX}/lib/dahdi

post-install:
	@${TOUCH} ${PREFIX}/lib/dahdi/linker.hints

.include <bsd.port.post.mk>
