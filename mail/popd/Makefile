# New ports collection makefile for:	popd
# Date created:				17 April 2001
# Whom:					ianf@za.uu.net
#
# $FreeBSD$
#

PORTNAME=	popd
PORTVERSION=	2.2.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp3.za.freebsd.org/pub/popd/

MAINTAINER=	ianf@za.uu.net

BROKEN=		distfiles rerolled, discussing with author

MAN8=   popd.8

INSTALLS_SHLIB=	yes
MANCOMPRESSED=	maybe
.if defined(NOPROFILE)
PLIST_SUB=	NOPROFILE="@comment "
.else
PLIST_SUB=	NOPROFILE=""
.endif

.include <bsd.port.mk>
