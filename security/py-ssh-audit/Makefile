# $FreeBSD$

PORTNAME=	ssh-audit
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.0
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	SSH server auditing

LICENSE=	MIT

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jtesta
USE_PYTHON=	concurrent
NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	ssh-audit.py

PLIST_FILES=	bin/ssh-audit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ssh-audit.py ${STAGEDIR}${PREFIX}/bin/ssh-audit

.include <bsd.port.mk>
