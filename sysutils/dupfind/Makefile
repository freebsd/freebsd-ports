# New ports collection makefile for:   dupfind
# Date created:        2004-12-30
# Whom:                bdluevel@heitec.net
#
# $FreeBSD$
#

PORTNAME=	dupfind
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.heitec.net/pub/distfiles/

MAINTAINER=	bdluevel@heitec.net
COMMENT=	Finds duplicate files in directory trees

LIB_DEPENDS=	fcrc.1:${PORTSDIR}/devel/fastcrc

MAN1=		dupfind.1

PLIST_FILES=	bin/dupfind
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"no ftw.h header file on 4.x"
.endif

.include <bsd.port.post.mk>
