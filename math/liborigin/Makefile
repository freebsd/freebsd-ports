# New ports collection makefile for:	liborigin
# Date created:		2006-08-26
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	liborigin
PORTVERSION=	20070115
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	makc@issp.ac.ru
COMMENT=	Tools for importing OriginLab .OPJ files

PLIST_FILES=	bin/opj2dat \
		include/OPJFile.h \
		lib/liborigin.so \
		lib/liborigin.so.0

USE_LDCONFIG=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opj2dat ${PREFIX}/bin
	${CP} ${WRKSRC}/OPJFile.h ${PREFIX}/include/OPJFile.h
	${INSTALL_PROGRAM} ${WRKSRC}/liborigin.so ${PREFIX}/lib/liborigin.so.0
	${LN} -fs ${PREFIX}/lib/liborigin.so.0 ${PREFIX}/lib/liborigin.so

.include <bsd.port.mk>
