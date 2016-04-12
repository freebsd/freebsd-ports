# Created by: Tim Vanderhoek <ac199@freenet.hamilton.on.ca>
# $FreeBSD$

PORTNAME=	slnr
PORTVERSION=	2.3.0
CATEGORIES=	news
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simplistic reader for SOUP (HDPF) mail and news packets

BROKEN=		unfetchable

RUN_DEPENDS=	zip:archivers/zip

MAKEFILE=	src/Makefile

DOCFILES=	${FILESDIR}/porting.notes other/soup12.doc other/slnr.doc \
		LICENSE other/default.dot.slnrrc

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/slnr
	@(cd ${WRKSRC}; \
		${INSTALL_DATA} ${DOCFILES} ${STAGEDIR}${DOCSDIR})
	${INSTALL_MAN} ${WRKSRC}/other/slnr.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/slnr ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
