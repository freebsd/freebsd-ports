# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zsi
PORTVERSION=	2.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pywebsvcs/ZSI/ZSI-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Python module that provides an implementation of SOAP 1.1

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS=	${PYXML}

CONFLICTS=	py-zsi-devel-2.*

USES=		python:2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.tex
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.for subdir in interop samples test
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${subdir}
	${CP} -rp ${WRKSRC}/${subdir}/* ${STAGEDIR}${EXAMPLESDIR}/${subdir}
.endfor

.include <bsd.port.mk>
