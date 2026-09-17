PORTNAME=	cdist
DISTVERSION=	7.0.0
CATEGORIES=	sysutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Usable Configuration Management System
WWW=		http://cdi.st/

LICENSE=	GPLv3

USES=		python
USE_PYTHON=	distutils

NO_ARCH=	yes

post-install:
	@${FIND} ${WRKSRC}/docs/dist/man/man1 -type f -maxdepth 1 -name '*.1' -exec \
		${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man1 \;
	@${FIND} ${WRKSRC}/docs/dist/man/man7 -type f -maxdepth 1 -name '*.7' -exec \
		${INSTALL_MAN} {} ${STAGEDIR}${PREFIX}/share/man/man7 \;

.include <bsd.port.mk>
