# New ports collection makefile for:	teTeX
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $FreeBSD$
#

PORTNAME=	teTeX
PORTVERSION=	2.0.2
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite

RUN_DEPENDS=	${TETEX_MODESW}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/share/texmf/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		latex:${PORTSDIR}/print/teTeX-base \
		${LOCALBASE}/share/texmf-local/tex/latex/base/latex.ltx:${PORTSDIR}/print/teTeX-latex2e \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		xdvi:${PORTSDIR}/print/xdvik

TETEX_MODESW=	${LOCALBASE}/bin/tetex-modesw

PKGINSTALL=	${WRKDIR}/pkg-install.sh
PKGDEINSTALL=	${WRKDIR}/pkg-install.sh
PKGINSTALL_SUB=	TETEX_MODESW=${TETEX_MODESW} \
		MODE=${DEFAULT_MODE}

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

OPTIONS=	LETTERSIZE "Use letter size by default" off

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
DEPENDS_ARGS+=	WITH_LETTERSIZE=true
DEFAULT_MODE=	tetex-letter
.else
DEFAULT_MODE=	tetex
.endif

# XXX: this does not work
#.if defined(FLAVOR)
#PKGNAMESUFFIX=	${FLAVOR:S,^,-,:Q:S,\\ ,,g:S,\\-,-,g}
#.endif

do-configure:
	${SED} ${PKGINSTALL_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		< ${FILESDIR}/pkg-install.in > ${PKGINSTALL}
	${CHMOD} 0755 ${PKGINSTALL}

do-build:
	@${DO_NADA}

do-install: #emtpy
	@${DO_NADA}

post-install:
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
