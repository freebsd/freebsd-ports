PORTNAME=	zapzap
DISTVERSION=	6.2
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	WhatsApp desktop application written in PyQt6
WWW=		https://rtosta.com/zapzap/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		desktop-file-utils pyqt:6 python
USE_GITHUB=	yes
GH_ACCOUNT=	rafatosta
USE_PYQT=	webengine:run
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
