# New ports collection makefile for:	mgv
# Date created:		4 Mar 1998
# Whom:			handy@physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	mgv
PORTVERSION=	3.1.5
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.netsw.org/graphic/postscript/interpreter/mgv/ \
		http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PostScript and PDF previewer

USE_XORG=	xpm
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimize \
		--disable-debug
PLIST_SUB=	MGV_VERSION=${PORTVERSION}

MAN1=		mgv.1

post-install:
		@ ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
