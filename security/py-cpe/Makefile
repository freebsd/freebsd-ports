PORTNAME=	cpe
DISTVERSION=	1.3.0
CATEGORIES=	security python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	CPE: Common Platform Enumeration for Python
WWW=		https://github.com/nilp0inter/cpe

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|expression2_2|tests/expression2_2|g' \
		${WRKSRC}/tests/testfile_cpelang2_2.txt
	@${REINPLACE_CMD} -e 's|expression2_3|tests/expression2_3|g' \
		${WRKSRC}/tests/testfile_cpelang2_3.txt

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest

.include <bsd.port.mk>
