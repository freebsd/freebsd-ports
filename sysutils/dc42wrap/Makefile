# New ports collection makefile for:	dc42wrap
# Date created:		28 June 2003
# Whom:			Eric P. Scott <eps+dc42wrap@ana.com>
#
# $FreeBSD$
#

PORTNAME=	dc42wrap
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://tools.ana.com/utils/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Wrap a \"raw\" floppy image as an Apple DiskCopy 4.2 file

MAKEFILE=	Makefile,freebsd
MAKE_ENV=	BINDIR=${PREFIX}/bin SHAREDIR=${PREFIX} NOMANCOMPRESS=yes
MAN1=		dc42wrap.1
PLIST_FILES=	bin/dc42wrap

.include <bsd.port.mk>
