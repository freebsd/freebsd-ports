# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bleach
PORTVERSION=	1.2.2
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	An easy whitelist-based HTML-sanitizing tool for Python

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}html5lib==0.95:${PORTSDIR}/www/py-html5lib

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	jsocol
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	baf1eac

TEST_DEPENDS:=	${RUN_DEPENDS} \
		nosetests:${PORTSDIR}/devel/py-nose \

regression-test: build
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYSETUP} test

NO_STAGE=	yes
.include <bsd.port.mk>
