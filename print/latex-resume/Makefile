# ex:ts=8
# Ports collection makefile for:	latex-res
# Date created:			Jul 30, 2007
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	resume
PORTVERSION=	20010823
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	macros/latex/contrib/${PORTNAME}
PKGNAMEPREFIX=	latex-
DISTNAME=	res
EXTRACT_SUFX=	.cls
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org
COMMENT=	A resume class for LaTeX

BUILD_DEPENDS=	mktexlsr:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.

TEXMFDIR=	share/texmf
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
CLASSDIR=	${TEXMFDIR}/tex/latex/${PORTNAME}
CLASS_FILES=	${DISTFILES}

PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		CLASSDIR=${CLASSDIR}

do-install:
	@${MKDIR} ${PREFIX}/${CLASSDIR}
	${INSTALL_DATA} ${CLASS_FILES:S@^@${WRKSRC}/@} ${PREFIX}/${CLASSDIR}

post-install:
	@${MKTEXLSR}

.include <bsd.port.mk>
