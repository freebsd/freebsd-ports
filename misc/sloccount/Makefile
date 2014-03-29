# Created by: ijliao
# $FreeBSD$

PORTNAME=	sloccount
PORTVERSION=	2.26
CATEGORIES=	misc
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	freaky@aagh.net
COMMENT=	Counts physical Source Lines of Code (SLOC)

USES=		perl5

MAKEFILE=	makefile
INSTALL_TARGET=	install_programs install_man

PORTDOCS=	ChangeLog README TODO sloccount.html

post-install:
.for file in lexcount1 c_count java_count php_count
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
