# ex:ts=8
# Ports collection makefile for:	ploticus
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ploticus
PORTVERSION=	2.10
CATEGORIES=	math
MASTER_SITES=	http://ploticus.sourceforge.net/download/
DISTNAME=	plsrc${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_XLIB=	yes
ALL_TARGET=	${PORTNAME}

MAN1=	pl.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../prefabs/* ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${MAN1} ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
