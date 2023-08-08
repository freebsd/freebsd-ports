PORTNAME=	networkmgr
DISTVERSION=	6.2
CATEGORIES=	net-mgmt

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	FreeBSD/GhostBSD network connection manager
WWW=		https://github.com/GhostBSD/networkmgr

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		sudo:security/sudo

USES=		gettext-tools gnome python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD
USE_GNOME=	pygobject3
USE_PYTHON=	distutils noflavors
SHEBANG_GLOB=	*.py

NO_ARCH=	yes

.include <bsd.port.mk>
