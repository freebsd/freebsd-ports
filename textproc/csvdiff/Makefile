# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	csvdiff
PORTVERSION=	1.7
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
#DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}17
EXTRACT_SUFX=	.tgz

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Compare/diff two (comma) separated files with each other

NO_BUILD=	yes
USES=		perl5
PLIST_FILES=	bin/csvdiff
WRKSRC=		${WRKDIR}
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README TODO
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
