# ex:ts=8
# New ports collection makefile for:	cpp2latex
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cpp2latex
PORTVERSION=	2.1
CATEGORIES=	print
MASTER_SITES=	http://www.arnoldarts.de/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cpp2latex/cpp2latex ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
