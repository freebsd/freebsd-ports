# New ports collection makefile for:    ifxetex
# Date created:         2008-09-24
# Whom:                 Martin Dieringer <martin.dieringer@gmx.de>
#
# $FreeBSD$

PORTNAME=	ifxetex
PORTVERSION=	20080729
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/generic/${PORTNAME}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.sty

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	The file ifxetex.sty tests whether XeTeX is being used

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.

PLIST=		${WRKDIR}/pkg-plist

TEXMFDIR=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
CLASS_FILES=	${DISTFILES}

PLIST_SUB=	CLASSDIR=${CLASSDIR}
PLIST_FILES=	${CLASSDIR}/${CLASS_FILES}
PLIST_DIRS=	${CLASSDIR}

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
