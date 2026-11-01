PORTNAME=	minismtpd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5
CATEGORIES=	mail python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Minimal SMTP server

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	cuu508
USE_PYTHON=	autoplist pep517

post-patch:
	@${REINPLACE_CMD} -e 's|^license = .*|license = { text = "BSD-3-Clause AND PSF-2.0" }|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
