# New ports collection makefile for:	unrtf
# Date created:		26 March 2002
# Whom:			Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	unrtf
PORTVERSION=	0.19.3
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A converter from RTF to several formats, including HTML and LaTeX

USE_REINPLACE=	yes
ALL_TARGET=	unrtf

MAN1=		unrtf.1
PLIST_FILES=	bin/unrtf

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC| ; s|^CFLAGS|#CFLAGS| ; \
		s|||" ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|<malloc\.h>|<stdlib.h>|" ${WRKSRC}/malloc.c
	${REINPLACE_CMD} -e 's/printf (op->\(.*\))/printf (op->\1 == NULL ? "" : op->\1)/' ${WRKSRC}/convert.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unrtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/unrtf.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
