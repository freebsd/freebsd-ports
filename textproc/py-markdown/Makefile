# Created by: Graham Todd <gtodd@bellanet.org>
# $FreeBSD$

PORTNAME=		markdown
PORTVERSION=		2.3.1
CATEGORIES=		textproc python
MASTER_SITES=		CHEESESHOP
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
DISTNAME=		Markdown-${PORTVERSION}

MAINTAINER=		koobs@FreeBSD.org
COMMENT=		Text markup to HTML conversion engine for Python

LICENSE=	BSD

TEST_DEPENDS=	nosetests:${PORTSDIR}/devel/py-nose

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_PKGNAME=	Markdown

regression-test: build
	@cd ${WRKSRC} && nosetests

NO_STAGE=	yes
.include <bsd.port.mk>
