# Created by: Jason Harmening <jason.harmening@gmail.com>
# $FreeBSD$

PORTNAME=	cx88
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://corona.homeunix.net/ports/cx88/

MAINTAINER=	jah@FreeBSD.org
COMMENT=	Drivers for Conexant CX23880/1/2/3/5/7/8-based TV/radio capture cards

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjson-c.so:devel/json-c
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:textproc/ezxml \
		libtuner>=1.1.4:multimedia/libtuner

# XXX static libraries with PIE are currently unsupported
MAKE_ARGS+=	WITHOUT_PIE=true
MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner LIBTUNER_HEADER=${LOCALBASE}/include/libtuner KMODDIR=${KMODDIR} PREFIX=${STAGEDIR}${PREFIX}
MAKE_JOBS_UNSAFE=	yes
USES=			kmod libedit pkgconfig uidfix
USE_RC_SUBR=		cx88d

OPTIONS_DEFINE=	DEBUG LINUX_COMPAT

DEBUG_DESC=		Enable debugging and verbose driver output
LINUX_COMPAT_DESC=	Support for Linux DVB and radio API

OPTIONS_DEFAULT=	LINUX_COMPAT

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	DIAGNOSTIC=0x7f -DDEBUG
.endif

.if ${PORT_OPTIONS:MLINUX_COMPAT}
BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
MAKE_ARGS+=	-D WITH_LINUX_COMPAT
.endif

MAKE_ARGS+=	-D CX88_USE_IIC
MAKE_ARGS+=	DEFAULT_XML_CONFIG="${EXAMPLESDIR}/cx88.xml.sample"

.include <bsd.port.mk>
