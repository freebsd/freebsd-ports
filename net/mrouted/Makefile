# New ports collection makefile for:	mrouted
# Date created:		28 September 2006
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mrouted
PORTVERSION=	3.9
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.research.att.com/pub/fenner/mrouted/ \
		http://www.mirrorservice.org/sites/www.ibiblio.org/gentoo/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}beta3+IOS12

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multicast routing daemon providing DVMRP for IPv4

USE_RC_SUBR=	mrouted
BUILD_ENV+=	CFLAGS="-O2 -fno-strict-aliasing -DRSRR -Dlog=logit"

MAN8=		map-mbone.8 mrouted.8 mrinfo.8

MROUTED_BINARIES=	map-mbone mrouted mrinfo

PLIST_FILES=	sbin/map-mbone sbin/mrouted sbin/mrinfo

do-install:
.for i in ${MROUTED_BINARIES}
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/sbin/${i}
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man8
.endfor

.include <bsd.port.mk>
