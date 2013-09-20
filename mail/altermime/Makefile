# Created by: Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
# $FreeBSD$

PORTNAME=	altermime
PORTVERSION=	0.3.11.a1
CATEGORIES=	mail textproc
#MASTER_SITES=	http://www.pldaniels.com/altermime/ \
MASTER_SITES=	http://T32.tecnik93.com/FreeBSD/ports/altermime/sources/

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Small C program which is used to alter your mime-encoded mailpacks

PLIST_FILES=	bin/altermime
PORTDOCS=	CHANGELOG LICENCE README

NO_STAGE=	yes
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
