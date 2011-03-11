# New ports collection makefile for:	py-qpy
# Date created:		13 Nov 2006
# Whom:	      		Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	qpy
PORTVERSION=	1.8
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qpy/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generating safely-quoted html text from python code

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@cd ${WRKSRC} && \
		${INSTALL_DATA} CHANGES.txt LICENSE.txt README.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
