# New ports collection makefile for:	liborigin
# Date created:		2006-08-26
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	liborigin
PORTVERSION=	20070926
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2007

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Tools for importing OriginLab .OPJ files

CONFLICTS=	LabPlot-1.5.*

PLIST_FILES=	bin/opj2dat \
		include/${PORTNAME}/OPJFile.h \
		include/${PORTNAME}/tree.hh \
		lib/liborigin.so \
		lib/liborigin.so.0
PLIST_DIRS=	include/${PORTNAME}

USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; \
		s|^\(CFLAGS.*=\)|\1${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opj2dat ${PREFIX}/bin
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/OPJFile.h ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/tree.hh ${PREFIX}/include/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/lib/liborigin.so.0.0.3 ${PREFIX}/lib/liborigin.so.0
	${LN} -fs ${PREFIX}/lib/liborigin.so.0 ${PREFIX}/lib/liborigin.so

.include <bsd.port.mk>
