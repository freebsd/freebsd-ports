# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	nassl
PORTVERSION=	4.0.2
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Experimental OpenSSL wrapper for SSLyze

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:3.7+ ssl
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	nabla-c0d3
USE_GITHUB=	yes

post-patch:
	@${RM} ${WRKSRC}/build_tasks.py ${WRKSRC}/tasks.py ${WRKSRC}/nassl/legacy_ssl_client.py
	@${REINPLACE_CMD} -e 's|%%OPENSSLINC%%|${OPENSSLINC}|; s|%%OPENSSLLIB%%|${OPENSSLLIB}|' ${WRKSRC}/setup.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
