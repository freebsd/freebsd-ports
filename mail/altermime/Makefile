# New ports collection makefile for:   altermime
# Date created:        2005-01-25
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Tecnik: ports/mail/altermime/Makefile,v 1.4 2006/04/07 20:30:34 itetcu Exp $
#

PORTNAME=	altermime
PORTVERSION=	0.3.8
CATEGORIES=	mail textproc
MASTER_SITES=	http://www.pldaniels.com/altermime/ \
	http://sce-tindy.tecnik93.com/FreeBSD/ports/altermime/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Small C program which is used to alter your mime-encoded mailpacks

PLIST_FILES=	bin/altermime
PORTDOCS=	CHANGELOG LICENCE README

post-patch:
	@${REINPLACE_CMD} -e "s#CFLAGS=-Wall -g#CFLAGS=-Wall ${CFLAGS}#" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
