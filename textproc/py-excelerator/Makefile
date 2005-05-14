# New ports collection makefile for:	py-excelerator
# Date created:		13 May 2005
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	excelerator
PORTVERSION=	0.5.0a
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyexcelerator
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyExcelerator-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A Python library for generating Excel 97/2000/XP/2003 files

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES.txt LICENSE.txt README.txt THANKS.txt TODO.txt
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCSDIR}
.endfor
.endif

	@${MKDIR} ${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/examples -type f -depth 1 -exec ${INSTALL_DATA} {} ${EXAMPLESDIR} \;

.include <bsd.port.mk>
