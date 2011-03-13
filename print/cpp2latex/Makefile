# ex:ts=8
# New ports collection makefile for:	cpp2latex
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cpp2latex
PORTVERSION=	2.3
CATEGORIES=	print
MASTER_SITES=	http://www.arnoldarts.de/downloads/cpp2latex/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert C++ source to a file you can input in an LaTeX-document

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/cpp2latex
PORTDOCS=	AUTHORS ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docfile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
