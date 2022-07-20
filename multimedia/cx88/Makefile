PORTNAME=	cx88
DISTVERSION=	1.5.4
CATEGORIES=	multimedia
MASTER_SITES=	https://corona.homeunix.net/distfiles/ports/cx88/

MAINTAINER=	jah@FreeBSD.org
COMMENT=	Drivers for Conexant CX23880x-based PCI(e) TV/radio capture cards

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libjson-c.so:devel/json-c
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:textproc/ezxml \
		libtuner>=1.1.5:multimedia/libtuner

# XXX static libraries with PIE are currently unsupported
MAKE_ARGS+=	WITHOUT_PIE=true

MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner \
		LIBTUNER_HEADER=${LOCALBASE}/include/libtuner \
		KMODDIR=${KMODDIR} \
		PREFIX=${STAGEDIR}${PREFIX} \
		-D CX88_USE_IIC \
		DEFAULT_XML_CONFIG="${EXAMPLESDIR}/cx88.xml.sample"

MAKE_JOBS_UNSAFE=	yes
USES=			kmod libedit pkgconfig uidfix
USE_RC_SUBR=		cx88d

OPTIONS_DEFINE=	DEBUG LINUXCOMPAT VERBOSE
OPTIONS_DEFAULT=	LINUXCOMPAT

VERBOSE_DESC=		Enable verbose output
LINUXCOMPAT_DESC=	Support for Linux DVB and radio API

DEBUG_IMPLIES=		VERBOSE
DEBUG_MAKE_ARGS+=	-DDEBUG

VERBOSE_MAKE_ARGS+=	DIAGNOSTIC=0x7f

LINUXCOMPAT_BUILD_DEPENDS+=	v4l_compat>=1.0.20100321:multimedia/v4l_compat
LINUXCOMPAT_MAKE_ARGS+=	-D WITH_LINUX_COMPAT

.include <bsd.port.mk>
