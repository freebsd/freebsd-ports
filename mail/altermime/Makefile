# New ports collection makefile for:   altermime
# Date created:        2005-01-25
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	altermime
PORTVERSION=	0.3.6
CATEGORIES=	mail textproc
MASTER_SITES=	http://www.pldaniels.com/altermime/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Small C program which is used to alter your mime-encoded mailpacks

PLIST_FILES=	bin/altermime

USE_REINPLACE=	yes

PORTDOCS=	CHANGELOG LICENCE README

post-patch:
	@${REINPLACE_CMD} -e "s/CFLAGS=-Wall -g/CFLAGS=-Wall ${CFLAGS}/" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
