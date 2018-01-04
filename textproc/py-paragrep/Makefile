# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	paragrep
PORTVERSION=	3.1.3
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Paragraph Grep Utility

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grizzled>=0.8.1:devel/py-grizzled@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	bmc

post-patch:
	@${REINPLACE_CMD} -e "s|'man'|'man/man1'|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
