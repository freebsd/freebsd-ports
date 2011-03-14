# New ports collection makefile for:	streamdvd
# Date created:				Fri Jul 22 18:30:01 EDT 2005
# Whom:					Serge Gagnon <serge.gagnon@b2b2c.ca>
#
# $FreeBSD$
#

PORTNAME=	streamdvd
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	ftp://quenix2.dyndns.org/FreeBSD/ports/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A fast tool to backup Video DVDs 'on the fly'

DEPRECATED=     upstream and distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	dvdread.4:${PORTSDIR}/multimedia/libdvdread

WRKSRC=		${WRKDIR}/StreamDVD-${PORTVERSION}

PLIST_FILES=	bin/streamdvd
PORTDOCS=	README

post-patch:
	@${REINPLACE_CMD} -e 's|g++ -g -Wall|${CXX} ${CXXFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|' \
		${WRKSRC}/mplex/mplex.cpp ${WRKSRC}/streamdvd.c
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<unistd.h>|' \
		${WRKSRC}/mplex/mjpeg_types.h
	@${REINPLACE_CMD} -e '48s|ZAlphaStream::||' ${WRKSRC}/mplex/zalphastrm.hpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/streamdvd ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
