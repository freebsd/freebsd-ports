PORTNAME=	ssh-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
PORTREVISION=	1
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	SSH server auditing
WWW=		https://github.com/jtesta/ssh-audit

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	jtesta
USE_PYTHON=	pep517

post-install:
	${INSTALL_MAN} ${WRKSRC}/ssh-audit.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${ECHO_CMD} share/man/man1/ssh-audit.1.gz >> ${TMPPLIST}

.include <bsd.port.mk>
