# ex:ts=8
# Ports collection makefile for:	ploticus
# Date created:			Jan 23, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ploticus
PORTVERSION=	2.02
CATEGORIES=	math
MASTER_SITES=	http://ploticus.sourceforge.net/download/
DISTNAME=	plsrc${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	# empty
MAKE_ENV=	LIBS="-L${LOCALBASE}/lib"

MAN1=	pl.1 ploticus.1 plpng.1 pltab.1

post-patch:
	@${PERL} -pi -e "s,%%X11BASE%%,${X11BASE},g ; \
		s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/Makefile

do-install:
.for file in pl pltab
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	@${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/../prefabs/* ${DATADIR}
.for file in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/../man/man1/${file} ${MAN1PREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
