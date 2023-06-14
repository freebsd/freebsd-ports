PORTNAME=	nassl
PORTVERSION=	5.0.1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Experimental OpenSSL wrapper for SSLyze
WWW=		https://github.com/nabla-c0d3/nassl

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# Upstream bug https://github.com/nabla-c0d3/nassl/issues/110
BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	Fails to detect OpenSSL 3.0.0 libcrypt.so

USES=		python ssl
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	nabla-c0d3
USE_GITHUB=	yes

post-patch:
	@${RM} ${WRKSRC}/build_tasks.py ${WRKSRC}/tasks.py ${WRKSRC}/nassl/legacy_ssl_client.py
	@${REINPLACE_CMD} -e 's|%%OPENSSLINC%%|${OPENSSLINC}|; s|%%OPENSSLLIB%%|${OPENSSLLIB}|' ${WRKSRC}/setup.py

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
