PORTNAME=	xlmmacrodeobfuscator
PORTVERSION=	0.2.7
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	XLMMacroDeobfuscator-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XLM Emulation engine designed to analyze and deobfuscate malicious XLM macros
WWW=		https://github.com/DissectMalware/XLMMacroDeobfuscator

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lark>=0:devel/py-lark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msoffcrypto-tool>=0:security/py-msoffcrypto-tool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyxlsb2>=0:textproc/py-pyxlsb2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}roman>=0:math/py-roman@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}untangle>=1.2.1:textproc/py-untangle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd2>=0:textproc/py-xlrd2@${PY_FLAVOR}

USES=		dos2unix python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

.include <bsd.port.mk>
