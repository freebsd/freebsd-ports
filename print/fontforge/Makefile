# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20010410
CATEGORIES=	print
MASTER_SITES=   http://bibliofile.mc.duke.edu/gww/Freeware/PfaEdit/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${PORTNAME}_src-${DIST_VER}.tgz \
		libgunicode-${LIBGUNI_VER}.tgz libgdraw-${LIBGDRAW_VER}.tgz

MAINTAINER=	kanou@mil.allnet.ne.jp

DIST_VER=	230401
LIBGDRAW_VER=	220401
LIBGUNI_VER=	220401

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
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
	${INSTALL_MAN} ${WRKSRC}/pfaedit/pfaedit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
