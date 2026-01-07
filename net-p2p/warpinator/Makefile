PORTNAME=	warpinator
DISTVERSION=	1.8.5
PORTREVISION=	2
CATEGORIES=	net-p2p gnome
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	gnome

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Share files across the LAN
WWW=		https://github.com/linuxmint/warpinator

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}grpcio-tools>0:devel/py-grpcio-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}grpcio>=1.16.0:devel/py-grpcio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ifaddr>0:net/py-ifaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=0:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-xapp>=1.6.0:x11/py-python-xapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=0:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeroconf>=0.27.0:net/py-zeroconf@${PY_FLAVOR} \
		xapp>=0:x11/xapp

USES=		gettext gnome meson python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_GNOME=	glib20 gtk30 pygobject3
GLIB_SCHEMAS=	org.x.Warpinator.gschema.xml

SHEBANG_FILES=	bin/warpinator-send.in bin/warpinator.in data/warpinator-send-check \
		generate-protobuf testing/testrun
SHEBANG_GLOB=	*.py
MESON_ARGS=	-Dbundle-grpc=false \
		-Dbundle-zeroconf=false \
		-Dflatpak-build=false \
		-Dinclude-firewall-mod=false
BINARY_ALIAS=	python3=${PYTHON_CMD}
NO_ARCH=	yes

pre-build:
	cd ${WRKSRC} && ./generate-protobuf

.include <bsd.port.mk>
