PORTNAME=	spylls
DISTVERSION=	0.1.7
PORTREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Hunspell ported to pure Python
WWW=		https://pypi.org/project/spylls/

LICENSE=	MPL20

USES=		python
USE_PYTHON=	autoplist distutils concurrent

NO_ARCH=	yes

post-patch:
	@${RM} -r ${WRKSRC}/tests/

.include <bsd.port.mk>
