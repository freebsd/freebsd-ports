# New ports collection makefile for:	py-medusa
# Date created:		27 March 2002
# Whom:			Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	medusa
PORTVERSION=	0.5.4
CATEGORIES=	net devel python
MASTER_SITES=	http://www.amk.ca/files/python/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Asynchronous socket-based server framework for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DIST_SUBDIR=	python
DOCFILES=	CHANGES.txt INSTALL.txt LICENSE.txt README.txt TODO.txt
EXAMPLEDIRS=	demo test thread
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/docs
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}/docs
.for exdir in ${EXAMPLEDIRS}
	@${MKDIR} ${EXAMPLESDIR}/${exdir}
	@${INSTALL_DATA} ${WRKSRC}/${exdir}/* ${EXAMPLESDIR}/${exdir}
.endfor
.endif

.include <bsd.port.mk>
