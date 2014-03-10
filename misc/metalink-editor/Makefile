# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metalink
PORTVERSION=	1.2.0
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	SF/${PORTNAME}s/Metalink%20Editor/${PORTVERSION}
PKGNAMESUFFIX?=	-editor
DISTNAME=	${PORTNAME}editor-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI editor to create and edit metalinks

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/license.txt

USES=		dos2unix zip
DOS2UNIX_REGEX=	.*\.txt
NO_WRKSUBDIR=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	metalink_editor-${PORTVERSION}-py${PYTHON_VER}.egg-info
USE_WX=		2.6
WX_COMPS=	python

DATADIR=	${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}

DESKTOP_ENTRIES=	"Metalink editor" \
			"GUI editor to create and edit metalinks" \
			"${DATADIR}/metalink.png" \
			"metalink_editor.py" \
			"Network;FileTransfer;" \
			true

#
# Documents to install
#
DOC_FILES=	\
		readme.txt
#
.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
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
# docs
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
# fix installation permissions for restritive umask(1)
	@${FIND} \
		${DATADIR} \
		${PYTHONPREFIX_SITELIBDIR}/Metalink_editor \
		-type f -exec \
		${CHMOD} ${SHAREMODE} {} \;

.include <bsd.port.mk>
