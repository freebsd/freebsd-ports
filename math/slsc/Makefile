# New ports collection makefile for:	slsc
# Date created:			6 January 2000
# Whom:				Jonathan McDowell <noodles@earth.li>
#
# $FreeBSD$
#

PORTNAME=	slsc
PORTVERSION=	0.2.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slsc/
DISTNAME=	${PORTNAME}

MAINTAINER=	noodles@earth.li
COMMENT=	A enhanced slang-based version of the sc spreadsheet program

LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2

BROKEN=	Does not compile with devel/libslang2
DEPRECATED=    No longer maintained by author
EXPIRATION_DATE=   2009-02-18

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${PREFIX}/bin/slsc ${PREFIX}/share/slsc/vprint

.include <bsd.port.mk>
