# New ports collection makefile for:	yabasic
# Date created:		11 Nov 1999
# Whom:			Frank Gruender
#
# $FreeBSD$
#

PORTNAME=	yabasic
PORTVERSION=	2.730
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.yabasic.de/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet another Basic for Unix and Windows

USE_XLIB=	yes
USE_BISON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		yabasic.1

post-patch:
	@${REINPLACE_CMD} -e "s|= -DUNIX|= @X_CFLAGS@ -DUNIX|g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g" ${WRKSRC}/bison.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/yabasic.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
