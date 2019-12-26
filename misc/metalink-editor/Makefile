# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metalink
PORTVERSION=	1.2.0
PORTREVISION=	9
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}s/Metalink%20Editor/${PORTVERSION}
PKGNAMESUFFIX?=	-editor
DISTNAME=	${PORTNAME}editor-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI editor to create and edit metalinks

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		dos2unix python:2.7 zip
DOS2UNIX_REGEX=	.*\.txt
NO_WRKSUBDIR=	yes
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	metalink_editor-${PORTVERSION}-py${PYTHON_VER}.egg-info
USE_WX=		3.0+
WX_COMPS=	python
NO_ARCH=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

DESKTOP_ENTRIES=	"Metalink editor" \
			"" \
			"${DATADIR}/metalink.png" \
			"metalink_editor.py" \
			"Network;FileTransfer;" \
			true

PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

post-extract:
# Create a package to avoid namespace pollution
	@${MKDIR} ${WRKSRC}/Metalink_editor
	@${TOUCH} ${WRKSRC}/Metalink_editor/__init__.py
	@${MV} ${WRKSRC}/metalink.py ${WRKSRC}/Metalink_editor/

post-patch:
# Correct location of image files
	@${REINPLACE_CMD} -E \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/metalink_editor.py

pre-configure:
# Prepare new setup.py
	@${SED} \
		-e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|' \
		-e 's|%%VERSION%%|${PORTVERSION}|' \
		${FILESDIR}/setup.py \
		> ${WRKSRC}/${PYSETUP}

post-install:
# fix installation permissions for restritive umask(1)
	@${FIND} \
		${STAGEDIR}${DATADIR} \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Metalink_editor \
		-type f -exec \
		${CHMOD} ${SHAREMODE} {} \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
