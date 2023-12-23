PORTNAME=	gaupol
DISTVERSION=	1.4-3
DISTVERSIONSUFFIX=	-g6116d42b
PORTREVISION=	3
CATEGORIES=	multimedia python

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Subtitle editor
WWW=		https://otsaloma.io/gaupol/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		gspell>=0:textproc/gspell \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=1.5.1:textproc/py-enchant@${PY_FLAVOR}

USES=		desktop-file-utils gnome gstreamer: python
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk30 pygobject3 intltool
USE_GSTREAMER=	good bad ugly gtk libav pango
USE_PYTHON=	distutils autoplist py3kplist noflavors
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
