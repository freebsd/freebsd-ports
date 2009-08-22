# New ports collection makefile for:    pup Printer Utility Program
# Date created:         7 Nob 2002
# Whom:                 Klaus Goger <klaus.goger@reflex.at>
#
# $FreeBSD$
#

PORTNAME=	pup
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	print
#MASTER_SITES=	http://download.sourceforge.net/pup/
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ printer setup and maintaining tool

PLIST_FILES=	bin/pup
USE_GNOME=	gtk12

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/

post-patch:
	@echo ${WRKSRC}
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g' ${WRKSRC}/Makefile

.for file in lexgui.c build_choices.c proutines.c
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' ${WRKSRC}/${file}
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/pup ${PREFIX}/bin/

.include <bsd.port.mk>
