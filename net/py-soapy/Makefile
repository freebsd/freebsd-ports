# New ports collection makefile for:	py-soapy
# Date created:		10 July 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	soapy
PORTVERSION=	0.1
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SOAP/XML schema library for Python

RUN_DEPENDS=	${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}/test
	@ ${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}/test
.endif

.include <bsd.port.mk>
