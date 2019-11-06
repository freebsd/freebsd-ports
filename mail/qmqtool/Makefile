# Created by: Matthew Will <mwill@spingen.com>
# $FreeBSD$

PORTNAME=	qmqtool
PORTVERSION=	1.12
CATEGORIES=	mail
MASTER_SITES=	http://jeremy.kister.net/code/qmqtool/ \
		http://mirror.spingen.com/qmqtool/
DISTNAME=	${PORTNAME}-current

MAINTAINER=	mwill@spingen.com
COMMENT=	Tool to manipulate contents of a qmail queue

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USES=		perl5 tar:tgz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmqtool ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in Artistic ChangeLog FAQ README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
