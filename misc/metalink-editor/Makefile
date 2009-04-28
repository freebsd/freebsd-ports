# New ports collection makefile for:	Metalink editor
# Date created:		Sun 10 Aug 2008 10:50:59 UTC
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	metalink
PORTVERSION=	1.2.0
CATEGORIES=	misc
MASTER_SITES=	SF/metalinks
PKGNAMESUFFIX?=	-editor
DISTNAME=	${PORTNAME}editor-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GUI editor to create and edit metalinks

USE_ZIP=	yes
USE_DOS2UNIX=	yes
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
