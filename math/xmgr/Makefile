# New ports collection makefile for:	xmgr-4.1.1
# Version required:	4.1.1
# Date created:		Sun 18 Dec 1997
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $Id$
#

DISTNAME=	xmgr-4.1.1
CATEGORIES=	math print
MASTER_SITES=	ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/ \
		ftp://fire.mpi-stuttgart.mpg.de/pub/mirror/xmgr4/src/ \
		ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

BUILD_DEPENDS=	${X11BASE}/lib/libhlpclient.a:${PORTSDIR}/x11/libhelp \
		${LOCALBASE}/lib/libmfhdf.a:${PORTSDIR}/graphics/hdf
LIB_DEPENDS=	Xbae\\.6\\.:${PORTSDIR}/x11/xbae

USE_X11=	YES
REQUIRE_MOTIF=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	-prefix=${X11BASE} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--enable-extra-ldpath=${LOCALBASE}/lib --enable-libhelp \
	--enable-mfhdf --enable-acegr-home=${X11BASE}/lib/X11/xmgr

ALL_TARGET=
INSTALL_TARGET=	install links

.include <bsd.port.mk>
