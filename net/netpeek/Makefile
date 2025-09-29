PORTNAME=	netpeek
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.4
CATEGORIES=	net gnome python

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Modern local network scanner for GNOME
WWW=		https://github.com/zingytomato/netpeek \
		https://flathub.org/apps/io.github.zingytomato.netpeek

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-nmap>=0:security/py-python-nmap@${PY_FLAVOR}

USES=		gettext-tools gnome meson pkgconfig python:build,run
USE_GITHUB=	yes
GH_ACCOUNT=	ZingyTomato
GH_PROJECT=	NetPeek
USE_GNOME=	glib20 gtk40

post-patch:
	${REINPLACE_CMD} 's,python3,python${PYTHON_VER},g' \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
