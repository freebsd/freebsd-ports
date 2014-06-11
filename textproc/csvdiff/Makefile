# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	csvdiff
PORTVERSION=	1.7
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
#DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}17
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compare/diff two (comma) separated files with each other

NO_BUILD=	yes
USES=		perl5
PLIST_FILES=	bin/csvdiff
WRKSRC=		${WRKDIR}
PORTDOCS=	CHANGES README TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
