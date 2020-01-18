# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	diff-match-patch
PORTVERSION=	20181111
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Algorithms for converting plain text

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python shebangfix
USE_PYTHON=	autoplist distutils
python_OLD_CMD=	/usr/bin/python[0-9\.]*
SHEBANG_FILES=	diff_match_patch/*.py diff_match_patch/tests/*.py

NO_ARCH=	yes

do-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
