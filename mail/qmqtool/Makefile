# Created by: Matthew Will <mwill@spingen.com>
# $FreeBSD$

PORTNAME=	qmqtool
PORTVERSION=	1.12
CATEGORIES=	mail
MASTER_SITES=	http://jeremy.kister.net/code/qmqtool/ \
		http://mirror.spingen.com/qmqtool/
DISTNAME=	${PORTNAME}-current
EXTRACT_SUFX=	.tgz

MAINTAINER=	mwill@spingen.com
COMMENT=	Tool to manipulate contents of a qmail queue

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
USES=		perl5

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmqtool ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in Artistic ChangeLog FAQ README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
