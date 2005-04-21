# New ports collection makefile for:	xd
# Date created:		17 October 1997
# Whom:			KIRIYAMA Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xd
PORTVERSION=	2.3
CATEGORIES=	misc
MASTER_SITES=	http://www.bsddiary.net/xd/
DISTNAME=	xd-8087

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another dump utility

MAKE_ARGS=	CC="${CC}" BINDIR="${PREFIX}/bin" \
		MANDIR="${MAN1PREFIX}/man/man"

MAN1=		xd.1
MANCOMPRESSED=	maybe
PLIST_FILES=	bin/xd

.include <bsd.port.mk>
