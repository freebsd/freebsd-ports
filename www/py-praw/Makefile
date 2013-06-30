# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	praw
PORTVERSION=	2.1.3
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Python Reddit API Wrapper

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>=1.2.0:${PORTSDIR}/www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
TEST_DEPENDS:=	${RUN_DEPENDS}

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	praw-dev
GH_TAGNAME=	v${DISTVERSION}
GH_COMMIT=	8687d58

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

.include <bsd.port.mk>
