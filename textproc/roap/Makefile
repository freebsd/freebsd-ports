# ex:ts=8
# Ports collection Makefile for:	roap
# Date created:			Apr 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	roap
PORTVERSION=	0.1.2
CATEGORIES=	textproc python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Region Oriented Ascii Processor

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Region_Oriented_Ascii_Processor

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roap ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in README README.ja USAGE USAGE.ja
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.py ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.xml ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
