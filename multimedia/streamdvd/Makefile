# New ports collection makefile for:	streamdvd
# Date created:				Fri Jul 22 18:30:01 EDT 2005
# Whom:					Serge Gagnon <serge.gagnon@b2b2c.ca>
#
# $FreeBSD$
#

PORTNAME=	streamdvd
PORTVERSION=	0.4
CATEGORIES=	multimedia
MASTER_SITES=	http://www.badabum.de/down/

MAINTAINER=	serge.gagnon@b2b2c.ca
COMMENT=	A fast tool to backup Video DVDs 'on the fly'

LIB_DEPENDS=	dvdread:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/StreamDVD-${PORTVERSION}

PLIST_FILES=	bin/streamdvd
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|g++ -g -Wall|${CXX} ${CXXFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|' \
		${WRKSRC}/mplex/mplex.cpp ${WRKSRC}/streamdvd.c
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<unistd.h>|' \
		${WRKSRC}/mplex/mjpeg_types.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamdvd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
