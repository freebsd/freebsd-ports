# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zsi
DISTVERSION=	2.1-a1
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pywebsvcs/ZSI/ZSI-${DISTVERSION:S,-,_,}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Python implementation of SOAP 1.1

USES=		python:2
USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.png
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
.for dir in client server
	@${MV} ${WRKSRC}/doc/examples/${dir} ${WRKSRC}
.endfor
.for subdir in samples test client server
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${subdir}
	${CP} -rp ${WRKSRC}/${subdir}/* ${STAGEDIR}${EXAMPLESDIR}/${subdir}
.endfor

.include <bsd.port.mk>
