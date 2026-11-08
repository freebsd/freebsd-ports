PORTNAME=	gaupol
DISTVERSION=	2.0.1
CATEGORIES=	multimedia python

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Subtitle editor
WWW=		https://otsaloma.io/gaupol/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		iso-codes>=3.67:misc/iso-codes \
		libspelling>=0.2:x11-toolkits/libspelling

USES=		desktop-file-utils gettext-tools gnome gstreamer python \
		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk40 intltool pygobject3
USE_GSTREAMER=	bad good gtk libav pango ugly
USE_PYTHON=	flavors

SHEBANG_FILES=	bin/gaupol.in

ALL_TARGET=	build

NO_ARCH=	yes

OPTIONS_DEFINE=	RUST
RUST_DESC=	Depend on gstreamer1-plugins-rust for embedded video playing through gtk4paintablesink
RUST_USE=	GSTREAMER=rust

.include <bsd.port.mk>
