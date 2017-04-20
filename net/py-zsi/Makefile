# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zsi
DISTVERSION=	2.1-a1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net python
MASTER_SITES=	SF/pywebsvcs/ZSI/ZSI-${DISTVERSION:S,-,_,}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tu}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pure Python implementation of SOAP 1.1

USES=		python:2 shebangfix
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
SHEBANG_FILES=	test/wsdl2py/*.py test/*.py \
		doc/examples/server/send_response/complex/manual/*.py \
		doc/examples/server/send_response/complex/wsdl2py/*.py \
		doc/examples/server/send_response/complex/client/*.py \
		doc/examples/server/send_response/simple/no_typecode/*.py \
		doc/examples/server/send_response/simple/wsdl2py/*.py \
		doc/examples/server/receive_request/simple/standalone/*.py \
		doc/examples/client/receive_response/simple/wsdl2py/*.py \
		doc/examples/client/receive_response/simple/ServiceProxy/*.py \
		doc/examples/client/receive_response/simple/server/*.py \
		doc/examples/server/receive_request/simple/client/*.py \
		doc/examples/server/receive_request/complex/wsdl2py/*.py \
		doc/examples/client/receive_response/complex/wsdl2py/*.py \
		doc/examples/client/receive_response/complex/manual/*.py \
		doc/examples/client/receive_response/complex/server/*.py \
		doc/examples/client/send_request/complex/wsdl2py/*.py \
		doc/examples/client/send_request/complex/manual/*.py \
		doc/examples/client/send_request/complex/server/*.py \
		doc/examples/client/send_request/simple/Binding/*.py \
		doc/examples/client/send_request/simple/wsdl2py/*.py \
		doc/examples/client/send_request/simple/server/*.py \
		doc/examples/client/send_request/simple/ServiceProxy/*.py \
		doc/examples/server/receive_request/complex/manual/*.py \
		doc/examples/server/receive_request/complex/client/*.py \
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
