# Created by: Marcus Alves Grando <mnag@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spf
PORTVERSION=	2.0.10
CATEGORIES=	mail python
MASTER_SITES=	SF/pymilter/py${PORTNAME}/py${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python implementation of the RFC 4408 SPF protocol

LICENSE=	PSFL

USE_PYTHON=	autoplist distutils
USES=		python shebangfix

PLIST_FILES=	bin/spf.py

SHEBANG_FILES=	spf.py

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 300
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dns>=0:${PORTSDIR}/dns/py-dns
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dns3>=0:${PORTSDIR}/dns/py-dns3
.endif

post-install:
	${CHMOD} ${BINMODE} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/spf.py
	${LN} -s ${PYTHONPREFIX_SITELIBDIR}/spf.py ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
