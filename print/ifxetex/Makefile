# Created by: Martin Dieringer <martin.dieringer@gmx.de>
# $FreeBSD$

PORTNAME=	ifxetex
PORTVERSION=	20090124
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/generic/
DISTNAME=	${PORTNAME}

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	The file ifxetex.sty tests whether XeTeX is being used

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		zip
USE_TEX=	latex

PLIST=		${WRKDIR}/pkg-plist

TEXMFDIR=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
CLASS_FILES=	${PORTNAME}.sty

NO_STAGE=	yes
do-build:
	cd ${WRKSRC}  && latex ${PORTNAME}.ins

pre-install:
	${ECHO_CMD} "${CLASSDIR}/${CLASS_FILES}" > ${PLIST}
	${ECHO_CMD} "@dirrm ${CLASSDIR}" >> ${PLIST}
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
