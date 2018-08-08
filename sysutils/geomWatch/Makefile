# Created by: Boris Kochergin <spawk@acm.poly.edu>
# $FreeBSD$

PORTNAME=	geomWatch
PORTVERSION=	1.3.0
PORTREVISION=	3
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

BROKEN_aarch64=		fails to compile: ISA not supported
BROKEN_armv6=		fails to compile: call to 'atomic_add_64' is ambiguous
BROKEN_armv7=		fails to compile: call to 'atomic_add_64' is ambiguous
IGNORE_DragonFly=	requires geom(4) support

USES=		tar:tbz
USE_CXXSTD=	gnu++98

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	WITH_ZFS=28

.include <bsd.port.mk>
