# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xjobs
PORTVERSION=	20170829
CATEGORIES=	sysutils
MASTER_SITES=	http://www.maier-komor.de/xjobs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility reads job descriptions line by line and executes in parallel

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/xjobs man/man1/xjobs.1.gz
USES=		tar:tgz

PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
