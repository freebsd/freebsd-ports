# New ports collection makefile for:	cvsup
# Version required:	15.3
# Date created:		7 August 1996
# Whom:			asami
#
# $Id: Makefile,v 1.22 1998/02/11 18:03:22 jdp Exp $
#

DISTNAME=	cvsup-15.3
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/CVSup/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/CVSup/ \
		ftp://ftp.polstra.com/pub/FreeBSD/CVSup/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-5:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3\\.5\\.:${PORTSDIR}/lang/modula-3-lib

MAN1=		cvsup.1
MAN8=		cvsupd.8

# To build the client without GUI support:
#MAKE_ENV=	M3FLAGS=-DNOGUI
# To link the programs statically:
#MAKE_ENV=	M3FLAGS=-DSTATIC
# To link just the Modula-3 libraries statically:
#MAKE_ENV=	M3FLAGS=-DM3STATIC
# If you combine these, use double quotes:
#MAKE_ENV=	M3FLAGS="-DNOGUI -DSTATIC"

.include <bsd.port.mk>
