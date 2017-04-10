# Created by: Boris Kochergin <spawk@acm.poly.edu>
# $FreeBSD$

PORTNAME=	geomWatch
PORTVERSION=	1.3.0
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://isis.poly.edu/~bk/${PORTNAME}/ \
		http://bk.macroblock.net/${PORTNAME}/ \
		http://svnweb.freebsd.org/base/head/sys/cddl/compat/opensolaris/sys/:nvpair
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		nvpair.h?revision=279437&view=co:nvpair
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	spawk@acm.poly.edu
COMMENT=	Watches for and e-mails admins about GEOM/ZFS state changes

LIB_DEPENDS=	libesmtp.so:mail/libesmtp

USES=		tar:tbz

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	WITH_ZFS=28

BROKEN_aarch64=		fails to compile: error: ISA not supported
IGNORE_DragonFly=	requires geom(4) support

.include <bsd.port.mk>
