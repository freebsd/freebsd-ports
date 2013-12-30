# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	pup
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK+ printer setup and maintaining tool

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}

USE_GNOME=	gtk12

PLIST_FILES=	bin/pup

post-patch:
	@${REINPLACE_CMD} -e \
		's| =| ?=| ; \
		 s|$$(CC) $$(SRCS)|$$(CC) $$(CFLAGS) $$(SRCS)| ; \
		 s|gtk-config|$$(GTK_CONFIG)|' ${WRKSRC}/Makefile
.for i in lexgui.c build_choices.c proutines.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pup ${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>
