# ex:ts=8
# Ports collection makefile for:	floatator
# Date created:			Jun 1, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	floatator
PORTVERSION=	0.2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.cichon.com/floatator/download/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_XLIB=	yes
USE_MOTIF=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
.for f in floatator floatator_X_interface
	${INSTALL_PROGRAM} ${WRKSRC}/$f ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
