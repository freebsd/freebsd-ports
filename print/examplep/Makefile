# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	examplep
PORTVERSION=	0.04
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex2e/contrib/
DISTNAME=	${PORTNAME}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	LaTeX style files for typesetting verbatim source code listings

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		zip
USE_TEX=	latex

PLIST=		${WRKDIR}/pkg-plist

TEXMFDIR=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
CLASS_FILES=	${PORTNAME}.sty codep.sty verbfwr.sty

NO_STAGE=	yes
do-build:

pre-install:
	${RM} -f ${PLIST}
.for F in ${CLASS_FILES}
	${ECHO_CMD} "${CLASSDIR}/${F}" >> ${PLIST}
.endfor
	${ECHO_CMD} "@dirrm ${CLASSDIR}" >> ${PLIST}
	${ECHO_CMD} "@exec ${MKTEXLSR}" >> ${PLIST}
	${ECHO_CMD} "@unexec ${MKTEXLSR}" >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${CLASSDIR}
	${ECHO_CMD} ${CLASS_FILES}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}

post-install:
	${MKTEXLSR}

.include <bsd.port.mk>
