# New ports collection makefile for:	pfaedit
# Date created:		25 March 2001
# Whom:			KANOU Hiroki <kanou@mil.allnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	pfaedit
PORTVERSION=	20${DIST_VER}
CATEGORIES=	print
MASTER_SITES=	http://pfaedit.sourceforge.net/
DISTFILES=	${PORTNAME}_full-${DIST_VER}.tgz cidmaps.tgz

MAINTAINER=	kanou@mil.allnet.ne.jp

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif

USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	pfaedit

MAN1=		pfaedit.1

DIST_VER=	020122

post-patch:
	${PERL} -pi.orig -e 's,/usr/share/,${PREFIX}/share/,g' \
		${WRKSRC}/pfaedit/pfaedit.1
	${PERL} -pi.orig -e 's,/usr/pkg/,${PREFIX}/,g' \
		${WRKSRC}/*/[mM]akefile.*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfaedit/pfaedit ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pfaedit
	${INSTALL_DATA} ${WRKDIR}/*.cidmap ${PREFIX}/share/pfaedit
	${MKDIR} ${PREFIX}/share/doc/pfaedit
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/pfaedit
	${INSTALL_MAN} ${WRKSRC}/pfaedit/pfaedit.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
