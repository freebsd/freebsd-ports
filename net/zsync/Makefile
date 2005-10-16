# Ports collection makefile for:	zsync
# Date created:			16 Jan 2005
# Whom:				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	zsync
PORTVERSION=	0.4.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gordon@FreeBSD.org
COMMENT=	A file transfer program

PLIST_FILES=	bin/zsync \
		bin/zsyncmake

.if !defined(NOPORTDOCS)
PORTDOCS=	COPYING \
		README
.endif

MAN1=		zsync.1 \
		zsyncmake.1

GNU_CONFIGURE=	yes

do-install:
.for FILE in zsync zsyncmake
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.for FILE in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/${FILE} ${MAN1PREFIX}/man/man1
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
