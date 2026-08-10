PORTNAME=	gaupol
DISTVERSION=	2.0
CATEGORIES=	multimedia python

MAINTAINER=	nxjoseph@FreeBSD.org
COMMENT=	Subtitle editor
WWW=		https://otsaloma.io/gaupol/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		libspelling>=0.2:x11-toolkits/libspelling \
		iso-codes>=3.67:misc/iso-codes \
		gstreamer1-plugins-rust>=0:multimedia/gstreamer1-plugins-rust

USES=		desktop-file-utils gettext-tools gnome gstreamer python
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk30 intltool pygobject3
USE_GSTREAMER=	bad good gtk libav pango ugly
USE_PYTHON=	autoplist flavors
NO_ARCH=	yes

ALL_TARGET=	build

post-patch:
	@${REINPLACE_CMD} 's|#!/usr/bin/env python3|#!${PYTHON_CMD}|' \
		${WRKSRC}/bin/gaupol.in

.include <bsd.port.mk>
