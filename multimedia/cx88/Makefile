# New ports collection makefile for:   cx88
# Date created:        7 September 2008
# Whom:                jah
#
# $FreeBSD$
#

PORTNAME=	cx88
PORTVERSION=	1.4.1
CATEGORIES=	multimedia kld
MASTER_SITES=	ftp://corona.homeunix.net/ports/cx88/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Drivers for Conexant CX23880/1/2/3/5/7/8-based TV/radio capture cards

LICENSE=	BSD

LIB_DEPENDS=	tuner.1:${PORTSDIR}/multimedia/libtuner
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:${PORTSDIR}/textproc/ezxml \
		libtuner>=1.0.7:${PORTSDIR}/multimedia/libtuner

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner LIBTUNER_HEADER=${LOCALBASE}/include/libtuner KMODDIR=${KMODDIR}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 801000)
LIB_DEPENDS+= cuse4bsd.1:${PORTSDIR}/multimedia/cuse4bsd-kmod
BUILD_DEPENDS+= v4l_compat>=1.0.20100321:${PORTSDIR}/multimedia/v4l_compat \
		cuse4bsd-kmod>=0.1.12:${PORTSDIR}/multimedia/cuse4bsd-kmod
MAKE_ARGS+= -D WITH_LINUX_DVB
.endif

.if (${OSVERSION} < 704000) || ((${OSVERSION} >= 800000) && (${OSVERSION} < 801000))
IGNORE= requires kernel support for kmem_alloc_attr() (FreeBSD 7.4+, FreeBSD 8.1+)
.endif

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.include <bsd.port.post.mk>
