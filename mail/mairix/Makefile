# ports collection Makefile for: mairix
# Whom:		Oliver Braun <obraun@FreeBSD.org>
# Date created:	2003-03-27
#
# $FreeBSD$
#

PORTNAME=	mairix
PORTVERSION=	0.15.2
CATEGORIES=	mail
MASTER_SITES=	http://www.rpcurnow.force9.co.uk/mairix/

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Indexing and searching in Maildir or MH folders

HAS_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} '/dfasyn/d' ${WRKSRC}/Makefile.in

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mairix ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/dotmairixrc.eg ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mairix.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
