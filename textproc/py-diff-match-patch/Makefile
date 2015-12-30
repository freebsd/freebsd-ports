# Created by: Rene Ladan <rene@FreeBSD.org>
# $FreeBSD$

PORTNAME=	diff-match-patch
PORTVERSION=	0.0.0.20121119
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
DISTNAME=	${PORTNAME}-${PORTVERSION:E}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Algorithms for converting plain text

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		python shebangfix
python_OLD_CMD=	/usr/bin/python[0-9\.]*
SHEBANG_FILES=	python*/diff_match_patch/*.py
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
