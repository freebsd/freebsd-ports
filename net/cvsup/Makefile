# New ports collection makefile for:	cvsup
# Version required:	15.2
# Date created:		7 August 1996
# Whom:			asami
#
# $Id: Makefile,v 1.21 1997/09/28 21:33:41 jdp Exp $
#

DISTNAME=	cvsup-15.2
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/CVSup/ \
		ftp://ftp.polstra.com/pub/FreeBSD/CVSup/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-5:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3\\.5\\.:${PORTSDIR}/lang/modula-3-lib

# To build the client without GUI support:
#MAKE_ENV=	M3FLAGS=-DNOGUI
# To link the programs statically:
#MAKE_ENV=	M3FLAGS=-DSTATIC
# To link just the Modula-3 libraries statically:
#MAKE_ENV=	M3FLAGS=-DM3STATIC
# If you combine these, use double quotes:
#MAKE_ENV=	M3FLAGS="-DNOGUI -DSTATIC"

.include <bsd.port.mk>
