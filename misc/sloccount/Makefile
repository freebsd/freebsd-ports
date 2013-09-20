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

MAN1=		sloccount.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
post-install:
.for file in lexcount1 c_count java_count php_count
	@${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
