# ports collection Makefile for: mairix
# Whom:		Oliver Braun <obraun@FreeBSD.org>
# Date created:	2003-03-27
#
# $FreeBSD$
#

PORTNAME=	mairix
PORTVERSION=	0.11
CATEGORIES=	mail
MASTER_SITES=	http://www.rrbcurnow.freeuk.com/mairix/

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Indexing and searching in Maildir or MH folders

USE_SIZE=	yes
USE_BISON=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d ; /^CFLAGS/d ; /dfasyn/d' \
		 ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mairix ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mairix.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
