# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20010808
CATEGORIES=	print
MASTER_SITES=   http://pfaedit.sourceforge.net/
DISTFILES=	${PORTNAME}_src-${DIST_VER}.tgz \
		libgunicode-${LIBGUNI_VER}.tgz libgdraw-${LIBGDRAW_VER}.tgz \
		cidmaps.tgz

MAINTAINER=	kanou@mil.allnet.ne.jp

DIST_VER=	010808
LIBGDRAW_VER=	010808
LIBGUNI_VER=	010808

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	pfaedit

MAN1=		pfaedit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfaedit/pfaedit ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pfaedit
	${INSTALL_DATA} ${WRKDIR}/*.cidmap ${PREFIX}/share/pfaedit
	${INSTALL_MAN} ${WRKSRC}/pfaedit/pfaedit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
