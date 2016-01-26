# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pyspf
PORTVERSION=	2.0.12
DISTVERSIONSUFFIX=	t
PORTREVISION=	4
CATEGORIES=	mail python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SPF (Sender Policy Framework) implemented in Python

LICENSE=	PSFL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authres>=0:${PORTSDIR}/mail/py-authres
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>=0:${PORTSDIR}/devel/py-yaml

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/spf.py
SHEBANG_FILES=	spf.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 3300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}ipaddr>=0:${PORTSDIR}/devel/py-ipaddr
.endif

.if ${PYTHON_REL} >= 3000
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}py3dns>=0:${PORTSDIR}/dns/py-py3dns
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dns>=0:${PORTSDIR}/dns/py-dns
.endif

# Make the tests run as a module
post-extract:
	@${TOUCH} ${WRKSRC}/test/__init__.py

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py
	${LN} -s ${PYTHONPREFIX_SITELIBDIR}/spf.py ${STAGEDIR}${PREFIX}/bin/

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m test.testspf

.include <bsd.port.post.mk>
