# New ports collection makefile for:	xmgr
# Date created:		So   2 Mär 1997 12:11:43 MET
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	xmgr
PORTVERSION=	4.1.1
CATEGORIES=	math print
MASTER_SITES=	ftp://ftp.uni-bielefeld.de/pub/systems/FreeBSD/lkoeller/ \
		ftp://plasma-gate.weizmann.ac.il/pub/xmgr4/src/old/ \
		ftp://fire.mpi-stuttgart.mpg.de/pub/mirrors/xmgr4/src/old/ \
		ftp://wauug.erols.com/pub/X-Windows/xmgr4/src/old/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.DE

BUILD_DEPENDS=	${X11BASE}/lib/libhlpclient.a:${PORTSDIR}/x11/libhelp \
		${LOCALBASE}/lib/libmfhdf.a:${PORTSDIR}/graphics/hdf
LIB_DEPENDS=	Xbae.8:${PORTSDIR}/x11-toolkits/xbae

USE_X_PREFIX=	YES
USE_MOTIF=	YES
HAS_CONFIGURE=	YES
CONFIGURE_ARGS=	-prefix=${X11BASE} \
	--enable-extra-incpath=${X11BASE}/include/X11:${LOCALBASE}/include \
	--enable-extra-ldpath=${LOCALBASE}/lib --enable-libhelp \
	--enable-mfhdf --enable-acegr-home=${X11BASE}/lib/X11/xmgr

ALL_TARGET=
INSTALL_TARGET=	install links

post-patch:
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure.input
	${SED} "s%__MOTIFLIB__%${MOTIFLIB}%" ${WRKSRC}/configure.input > ${WRKSRC}/configure
	${RM} -f ${WRKSRC}/configure.input
	${CHMOD} 755 ${WRKSRC}/configure

.include <bsd.port.mk>
