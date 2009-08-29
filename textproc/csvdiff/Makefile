# New ports collection makefile for:	csvdiff
# Date created:				2006/07/12
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	csvdiff
PORTVERSION=	1.3
CATEGORIES=	textproc perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION:S,.,-,g}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Compare/diff two (comma) seperated files with each other

NO_BUILD=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/csvdiff
WRKSRC=		${WRKDIR}
.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES README TODO
.endif

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
