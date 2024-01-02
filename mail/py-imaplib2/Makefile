PORTNAME=	imaplib2
PORTVERSION=	3.6
CATEGORIES=	mail python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dereks@lifeofadishwasher.com
COMMENT=	Threaded Python IMAP4 client
WWW=		https://github.com/jazzband/imaplib2/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		pytest python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

# Copy tests until a new release
# https://github.com/jazzband/imaplib2/pull/38
post-extract:
	@${MKDIR} ${WRKSRC}/${PORTNAME}/tests
	@${CP} ${FILESDIR}/test_imports.py ${WRKSRC}/${PORTNAME}/tests/

.include <bsd.port.mk>
