# Created by: chuckr@freebsd.org
# $FreeBSD$

PORTNAME=	transfig
PORTVERSION=	3.2.5d
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/mcj/mcj-source/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools to convert Xfig's .fig files

RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

MAKE_JOBS_SAFE=	yes

USES=		imake
CFLAGS+=	-Wno-return-type
USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	xpm
MAN1=		fig2dev.1 fig2ps2tex.1 pic2tpic.1 transfig.1

CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTBINFLAGS="${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

.include <bsd.port.mk>
