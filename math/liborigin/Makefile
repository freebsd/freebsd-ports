# New ports collection makefile for:	liborigin
# Date created:		2006-08-26
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	liborigin
PORTVERSION=	20070926
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Tools for importing OriginLab .OPJ files

CONFLICTS=	LabPlot-[0-9]*

PLIST_FILES=	bin/opj2dat \
		include/OPJFile.h \
		include/tree.hh \
		lib/liborigin.so \
		lib/liborigin.so.0

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; \
		s|^\(CFLAGS.*=\)|\1${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opj2dat ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/OPJFile.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/tree.hh ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/lib/liborigin.so.0.0.3 ${PREFIX}/lib/liborigin.so.0
	${LN} -fs ${PREFIX}/lib/liborigin.so.0 ${PREFIX}/lib/liborigin.so

.include <bsd.port.mk>
