PORTNAME=	gaupol
DISTVERSION=	1.15
PORTREVISION=	1
CATEGORIES=	multimedia python

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Subtitle editor
WWW=		https://otsaloma.io/gaupol/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}charset-normalizer>=2.0:textproc/py-charset-normalizer@${PY_FLAVOR} \
		gspell>=1.0.0:textproc/gspell \
		iso-codes>=3.67:misc/iso-codes

USES=		desktop-file-utils gnome gstreamer python
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk30 intltool pygobject3
USE_GSTREAMER=	bad good gtk libav pango ugly
USE_PYTHON=	autoplist distutils flavors
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-runtime gettext-tools
NLS_USES_OFF=	gettext-tools

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

post-patch:
	@${REINPLACE_CMD} -e 's|%%STAGEDIR%%|"${STAGEDIR}"|' \
		-e 's|%%PREFIX%%|"${PREFIX}"|' \
		-e 's|#!/usr/bin/env python3|#!${PYTHON_CMD}|' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
