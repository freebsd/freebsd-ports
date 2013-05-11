# Created by: Bernd Rosauer <br@netland.inka.de>
# $FreeBSD$

PORTNAME=	teTeX
PORTVERSION=	3.0
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A meta port for teTeX suite

RUN_DEPENDS=	${LOCALBASE}/share/fonts/cm-super/README:${PORTSDIR}/print/cm-super

USE_TEX=	base texmf dvipsk dvipdfmx
OPTIONS_DEFINE=	LETTERSIZE X11
LETTERSIZE_DESC=	Use letter size by default

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_TEX+=	xdvik
.endif

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

.if ${PORT_OPTIONS:MLETTERSIZE}
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

.include <bsd.port.mk>
