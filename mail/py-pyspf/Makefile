# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspf
PORTVERSION=	2.0.13
PORTREVISION=	1
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPF (Sender Policy Framework) implemented in Python

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:mail/py-authres@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:devel/py-yaml@${PY_FLAVOR}

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils
USES=		python shebangfix
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/spf.py
SHEBANG_FILES=	spf.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}py3dns>=0:dns/py-py3dns@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dns>=0:dns/py-dns@${PY_FLAVOR}
.endif

# Make the tests run as a module
post-patch:
	@${TOUCH} ${WRKSRC}/test/__init__.py

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py
	${RLN} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py ${STAGEDIR}${PREFIX}/bin/

do-test:
	cd ${WRKSRC}/ && ${PYTHON_CMD} -m test.testspf

.include <bsd.port.post.mk>
