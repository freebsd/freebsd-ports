# Created by: Graham Todd <gtodd@bellanet.org>
# $FreeBSD$

PORTNAME=	markdown
PORTVERSION=	2.4
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Markdown-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Text markup to HTML conversion engine for Python

LICENSE=	BSD3CLAUSE

TEST_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose

USES=			dos2unix
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && nosetests

.include <bsd.port.mk>
