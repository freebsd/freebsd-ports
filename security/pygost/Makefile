PORTNAME=	pygost
PORTVERSION=	5.13
CATEGORIES=	security python
MASTER_SITES=	http://www.pygost.cypherpunks.ru/ \
		http://www.grosbein.net/freebsd/distfiles/ \
		LOCAL/eugen
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	Pure Python 2.7/3.x GOST cryptographic functions library
WWW=		http://www.pygost.cypherpunks.ru/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyderasn>=9.3:devel/pyderasn@${PY_FLAVOR}

USES=		tar:zst python
USE_PYTHON=	autoplist concurrent distutils optsuffix

NO_ARCH=	yes
PYDISTUTILS_INSTALLARGS+=	--install-data ${DOCSDIR}

.include <bsd.port.mk>
