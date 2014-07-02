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
COMMENT=	meta port for teTeX suite

RUN_DEPENDS=	${LOCALBASE}/share/fonts/cm-super/README:${PORTSDIR}/print/cm-super

USE_TEX=	base texmf dvipsk dvipdfmx
OPTIONS_DEFINE=	LETTERSIZE X11
LETTERSIZE_DESC=	Use letter size by default

NO_BUILD=	yes
NO_MTREE=	yes
NO_INSTALL=	yes

X11_USE=	TEX=xdvik

# XXX: We always build in batch mode to disable OPTIONS
#      in print/teTeX-base.
DEPENDS_ARGS+=	BATCH=yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLETTERSIZE}
DEPENDS_ARGS+=	WITH_LETTERSIZE=true
PAPERSIZE=	letter
.endif

TEXMFDISTDIR=	share/texmf-dist
TEXMFLOCAL_LSR=	${LOCALBASE}/share/texmf-local/ls-R

.include <bsd.port.mk>
