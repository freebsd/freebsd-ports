# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gaupol
DISTVERSION=	1.4-3
DISTVERSIONSUFFIX=	-g6116d42b
CATEGORIES=	multimedia python

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Subtitle editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	iso-codes>=0:misc/iso-codes \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}enchant>=1.5.1:textproc/py-enchant@${PY_FLAVOR}

USES=		desktop-file-utils gnome python:3.2+
USE_GITHUB=	yes
GH_ACCOUNT=	otsaloma
USE_GNOME=	gtk30 pygobject3 intltool
USE_PYTHON=	distutils autoplist py3kplist noflavors
INSTALLS_ICONS=	yes
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
