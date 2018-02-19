# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zsi
DISTVERSION=	2.1-a1
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pywebsvcs/ZSI/ZSI-${DISTVERSION:S,-,_,}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Python implementation of SOAP 1.1

USES=		python:2.7 shebangfix
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
SHEBANG_FILES=	doc/examples/*/*/*/*/*.py \
		test/*.py \
		test/wsdl2py/*.py \
		test/wsdl2py/servers/*.py

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in CHANGES README doc/zsi.* doc/*.png
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
.for dir in client server
	@${MV} ${WRKSRC}/doc/examples/${dir} ${WRKSRC}
.endfor
.for subdir in samples test client server
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${subdir}
	${CP} -rp ${WRKSRC}/${subdir}/* ${STAGEDIR}${EXAMPLESDIR}/${subdir}
.endfor

.include <bsd.port.mk>
