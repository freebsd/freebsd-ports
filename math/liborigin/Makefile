# New ports collection makefile for:	liborigin
# Date created:		2006-08-26
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	liborigin
PORTVERSION=	20070529
CATEGORIES=	math
MASTER_SITES=	SF

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Tools for importing OriginLab .OPJ files

PLIST_FILES=	bin/opj2dat \
		include/OPJFile.h \
		lib/liborigin.so \
		lib/liborigin.so.0

USE_LDCONFIG=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opj2dat ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/OPJFile.h ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/liborigin.so ${PREFIX}/lib/liborigin.so.0
	${LN} -fs ${PREFIX}/lib/liborigin.so.0 ${PREFIX}/lib/liborigin.so

.include <bsd.port.mk>
