PORTNAME=	tremc
DISTVERSION=	0.9.4
CATEGORIES=	net-p2p python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console client for the BitTorrent client Transmission
WWW=		https://github.com/tremc/tremc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python shebangfix
USE_GITHUB=	yes
NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	${PORTNAME}

OPTIONS_DEFINE=	ADNS IPY PYPERCLIP
OPTIONS_DEFAULT=	ADNS IPY PYPERCLIP

ADNS_DESC=	Resolve IPs to host names
IPY_DESC=	Extract ipv4 from ipv6 addresses
PYPERCLIP_DESC=	Copy magnet links to the system clipboard

ADNS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}adns>=0:dns/py-adns@${PY_FLAVOR}
IPY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ipy>=0:net-mgmt/py-ipy@${PY_FLAVOR}
PYPERCLIP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyperclip>=0:devel/py-pyperclip@${PY_FLAVOR}

.include <bsd.port.mk>
