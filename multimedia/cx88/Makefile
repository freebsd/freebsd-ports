# New ports collection makefile for:	cx88
# Date created:		7 September 2008
# Whom:			jah
#
# $FreeBSD$
#

PORTNAME=	cx88
PORTVERSION=	1.0.1
CATEGORIES=	multimedia kld
MASTER_SITES=	ftp://corona.homeunix.net/ports/cx88/
EXTRACT_ONLY=	cx88-${PORTVERSION}.tar.gz

MAINTAINER=	jason.harmening@gmail.com
COMMENT=	Drivers for Conexant CX23880/1/2/3-based TV/radio capture cards

LIB_DEPENDS=	tuner:${PORTSDIR}/multimedia/libtuner
BUILD_DEPENDS=	${LOCALBASE}/lib/libezxml.a:${PORTSDIR}/textproc/ezxml

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR}
MAKE_ARGS+=	LIBTUNER_LIB=${LOCALBASE}/lib/libtuner LIBTUNER_HEADER=${LOCALBASE}/include/libtuner KMODDIR=${KMODDIR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700055
IGNORE=		requires FreeBSD 7.0-RELEASE or later
.endif

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.include <bsd.port.post.mk>
