# ex:ts=8
# Ports collection makefile for:	ploticus
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ploticus
PORTVERSION=	2.04
CATEGORIES=	math
MASTER_SITES=	http://ploticus.sourceforge.net/download/
DISTNAME=	plsrc${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Generates plots and graphs from data

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

USE_XLIB=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	# empty
MAKE_ENV=	LIBS="-L${LOCALBASE}/lib"

MAN1=	pl.1

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/../prefabs/* ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${MAN1} ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
