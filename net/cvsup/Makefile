# New ports collection makefile for:	cvsup
# Version required:	13.5
# Date created:		7 August 1996
# Whom:			asami
#
# $Id: Makefile,v 1.12 1996/11/01 17:02:06 jdp Exp $
#

DISTNAME=	cvsup-13.5
CATEGORIES+=	devel
CATEGORIES+=	net
MASTER_SITES=	ftp://freefall.freebsd.org/pub/CVSup/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-4:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3\\.4\\.:${PORTSDIR}/lang/modula-3-lib

# To build the client without GUI support:
#MAKE_ENV=	M3FLAGS=-DNOGUI
# To link the programs statically:
#MAKE_ENV=	M3FLAGS=-DSTATIC
# To link just the Modula-3 libraries statically:
#MAKE_ENV=	M3FLAGS=-DM3STATIC
# If you combine these, use double quotes:
#MAKE_ENV=	M3FLAGS="-DNOGUI -DSTATIC"

.include <bsd.port.mk>
