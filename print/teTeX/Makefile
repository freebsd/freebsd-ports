# New ports collection makefile for:	teTeX
# Date created:		5 December 1996
# Whom:			Bernd Rosauer <br@netland.inka.de>
#
# $FreeBSD$
#

PORTNAME=	teTeX
PORTVERSION=	3.0
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite

RUN_DEPENDS=	${TEXMFLOCAL_LSR}:${PORTSDIR}/print/tex-texmflocal \
		${LOCALBASE}/${TEXMFDISTDIR}/LICENSE.texmf:${PORTSDIR}/print/teTeX-texmf \
		latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		xdvi:${PORTSDIR}/print/xdvik

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

OPTIONS=	LETTERSIZE "Use letter size by default" off

CONFLICTS=	latex2e-[0-9]* tex-[0-9]* dvips-[0-9]* xdvi-[0-9]*

.include <bsd.port.pre.mk>

.if defined(WITH_LETTERSIZE)
FLAVOR+=	letter
DEPENDS_ARGS+=	WITH_LETTERSIZE=true
PAPERSIZE=	letter
.else
PAPERSIZE=	a4
.endif

TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCAL_LSR=	${LOCALBASE}/share/texmf-local/ls-R

# XXX: this does not work
#.if defined(FLAVOR)
#PKGNAMESUFFIX=	${FLAVOR:S,^,-,:Q:S,\\ ,,g:S,\\-,-,g}
#.endif

do-build:
	@${DO_NADA}

do-install: #emtpy
	@${DO_NADA}

.include <bsd.port.post.mk>
