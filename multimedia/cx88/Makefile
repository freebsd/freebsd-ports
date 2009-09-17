# New ports collection makefile for:   cx88
# Date created:        7 September 2008
# Whom:                jah
#
# $FreeBSD$
#

PORTNAME=	cx88
PORTVERSION=	1.2.1
CATEGORIES=	multimedia kld
MASTER_SITES=	ftp://corona.homeunix.net/ports/cx88/

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Drivers for Conexant CX23880/1/2/3/5/7/8-based TV/radio capture cards

LIB_DEPENDS=	tuner.1:${PORTSDIR}/multimedia/libtuner
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:${PORTSDIR}/textproc/ezxml \
		libtuner>=1.0.4:${PORTSDIR}/multimedia/libtuner

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner LIBTUNER_HEADER=${LOCALBASE}/include/libtuner KMODDIR=${KMODDIR}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700055
IGNORE=		requires FreeBSD 7.0-RELEASE or later
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.include <bsd.port.post.mk>
