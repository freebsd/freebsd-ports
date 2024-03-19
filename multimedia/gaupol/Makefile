PORTNAME=	gaupol
DISTVERSION=	1.13
CATEGORIES=	multimedia python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor
WWW=		https://otsaloma.io/gaupol/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=1.5.1:textproc/py-enchant@${PY_FLAVOR} \
		gspell>=0:textproc/gspell \
		iso-codes>=0:misc/iso-codes

USES=		desktop-file-utils gnome gstreamer: python
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk30 intltool pygobject3
USE_GSTREAMER=	bad good gtk libav pango ugly
USE_PYTHON=	autoplist distutils noflavors py3kplist
NO_ARCH=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

.include <bsd.port.pre.mk>

# PYDISTUTILS_INSTALLNOSINGLE is deprecated so...
PYDISTUTILS_INSTALLARGS:=	${PYDISTUTILS_INSTALLARGS:N--single-version-externally-managed}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%STAGEDIR%%|"${STAGEDIR}"|' \
		-e 's|%%PREFIX%%|"${PREFIX}"|' \
		${WRKSRC}/setup.py

.include <bsd.port.post.mk>
