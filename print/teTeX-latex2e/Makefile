# New ports collection makefile for:	teTeX-latex
# Date created:		13 September 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	teTeX-latex2e
PORTVERSION=	1.0.20031201
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_LOCAL:S,%SUBDIR%/,hrs/${PORTNAME}/%SUBDIR%/,}
MASTER_SITE_SUBDIR=	macros/latex
DISTNAME=	base
DIST_SUBDIR=	teTeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	The latest version of LaTeX2e macro package for teTeX

BUILD_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

WRKSRC=		${WRKDIR}/base
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		LOCALBASE="${LOCALBASE}" \
		TEXMFLOCAL="${PREFIX}/${TEXMFLOCAL}" \
		MKTEXLSR="${MKTEXLSR}" \
		FMTUTIL="${FMTUTIL}"
PLIST_SUB=	MKTEXLSR=${MKTEXLSR} \
		LATEXBASE=${LATEXBASE} \
		INDEXSTYLE=${INDEXSTYLE} \
		FMTUTIL="${FMTUTIL}"
MAKEFILE=	${FILESDIR}/Makefile-latex-base
CONFLICTS=	ja-ptex-base-[0-9]* latex2e-[0-9]* \
		tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

TEXMFLOCAL=	share/texmf-local
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr
LATEXBASE=	${TEXMFLOCAL}/tex/latex/base
INDEXSTYLE=	${TEXMFLOCAL}/makeindex
FMTUTIL=	${SETENV} PATH=${PATH}:${LOCALBASE}/bin \
		${LOCALBASE}/bin/fmtutil --byfmt latex

.include <bsd.port.mk>
