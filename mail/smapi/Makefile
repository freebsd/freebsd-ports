# New ports collection makefile for:	smapi
# Date created:				19 June 2000
# Whom:				Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	smapi
PORTVERSION=	010218
CATEGORIES=	mail
MASTER_SITES=	http://cvs.physcip.uni-stuttgart.de/cvs2/

MAINTAINER=	gonza@techline.ru

WRKSRC=		${WRKDIR}/smapi
MAKEFILE=	makefile.bsd

ALL_TARGET=	libsmapibsd.a

FILES=		alc.h api_brow.h compiler.h ffind.h msgapi.h patmat.h prog.h  \
		progprot.h stamp.h typedefs.h unused.h semaphor.h

do-install:
	${MKDIR} ${PREFIX}/include/smapi
.for FILE in ${FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/include/smapi
.endfor
	${INSTALL_DATA} ${WRKSRC}/libsmapibsd.a ${PREFIX}/lib/libsmapi.a

.include <bsd.port.mk>
