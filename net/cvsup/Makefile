# New ports collection makefile for:	cvsup
# Version required:	16.1
# Date created:		7 August 1996
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	cvsup-16.1
CATEGORIES=	devel net
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/development/CVSup/sources/ \
		ftp://ftp.cs.tu-berlin.de/pub/FreeBSD/development/CVSup/sources/

MAINTAINER=	jdp@FreeBSD.org

BUILD_DEPENDS=	m3build-6:${PORTSDIR}/lang/modula-3
LIB_DEPENDS=	m3.6:${PORTSDIR}/lang/modula-3-lib

MAN1=		cvpasswd.1 cvsup.1
MAN8=		cvsupd.8
NOT_FOR_ARCHS=	alpha

# Support building on systems with or without X11 installed.
.ifdef NO_X11
M3FLAGS+=	-DNOGUI
.else
pre-fetch:
	@${ECHO_MSG} -n "To build this port without X11 (and without the GUI),"
	@${ECHO_MSG} " define \"NO_X11\"."

.endif

# Build options.  Uncomment the desired ones.
# To link the programs statically:
#M3FLAGS+=	-DSTATIC
# To link just the Modula-3 libraries statically:
#M3FLAGS+=	-DM3STATIC

MAKE_ARGS+=	PREFIX=${PREFIX} M3FLAGS="${M3FLAGS}"

.include <bsd.port.mk>
