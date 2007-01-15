# New ports collection makefile for:	endian
# Date created:		3 Jan 2006
# Whom:			bacon@smithers.neuro.mcw.edu
#
# $FreeBSD$
#

PORTNAME=	endian
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://www.neuro.mcw.edu/~bacon/Ports/distfiles/ \
		http://bacon.is-a-geek.org/~bacon/Ports/distfiles/

MAINTAINER=	bacon@smithers.neuro.mcw.edu
COMMENT=	Report endianness of a system

MAN1=		endian.1

PLIST_FILES=	bin/endian

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
