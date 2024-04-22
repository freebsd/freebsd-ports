PORTNAME=	paragrep
PORTVERSION=	3.3.0
PORTREVISION=	1
DISTVERSIONPREFIX=	release-
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Paragraph Grep Utility
WWW=		http://bmc.github.com/paragrep/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grizzled>=0.8.1:devel/py-grizzled@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=0:devel/py-click@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	bmc

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|'man'|'share/man/man1'|g" ${WRKSRC}/setup.py

.include <bsd.port.mk>
