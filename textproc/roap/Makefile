# Created by: ijliao
# $FreeBSD$

PORTNAME=	roap
PORTVERSION=	0.1.2
CATEGORIES=	textproc python
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Region Oriented Ascii Processor

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Region_Oriented_Ascii_Processor

NO_STAGE=	yes
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
