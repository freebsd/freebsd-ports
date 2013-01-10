# Created by: Jason Harmening <jason.harmening@gmail.com>
# $FreeBSD$

PORTNAME=	cx88
PORTVERSION=	1.4.6
CATEGORIES=	multimedia kld
MASTER_SITES=	ftp://corona.homeunix.net/ports/cx88/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Drivers for Conexant CX23880/1/2/3/5/7/8-based TV/radio capture cards

LICENSE=	BSD

LIB_DEPENDS=	tuner.1:${PORTSDIR}/multimedia/libtuner
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:${PORTSDIR}/textproc/ezxml \
		libtuner>=1.0.9:${PORTSDIR}/multimedia/libtuner

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner LIBTUNER_HEADER=${LOCALBASE}/include/libtuner KMODDIR=${KMODDIR}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DEBUG LINUX_COMPAT HAL

DEBUG_DESC= Enable debugging and verbose driver output
LINUX_COMPAT_DESC= Support for Linux DVB and radio API
HAL_DESC=	Register Linux DVB devices with HAL

OPTIONS_DEFAULT=	LINUX_COMPAT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	DIAGNOSTIC=0x7f
.endif

.if ${PORT_OPTIONS:MLINUX_COMPAT}
LIB_DEPENDS+=	cuse4bsd.1:${PORTSDIR}/multimedia/cuse4bsd-kmod
BUILD_DEPENDS+= v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat
MAKE_ARGS+=	-D WITH_LINUX_COMPAT
.if ${PORT_OPTIONS:MHAL}
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal \
		dbus-1:${PORTSDIR}/devel/dbus
MAKE_ARGS+=	-D WITH_HAL
.endif
.endif

MAKE_ARGS+=	DEFAULT_XML_CONFIG="${EXAMPLESDIR}/cx88.xml.sample"

.if (${OSVERSION} < 802513) || ((${OSVERSION} >= 900000) && (${OSVERSION} < 900041))
IGNORE= requires kernel support for DRIVER_MODULE_ORDERED macro (FreeBSD 8.3+, FreeBSD 9.0+)
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.include <bsd.port.mk>
