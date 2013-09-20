# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	transfig
PORTVERSION=	3.2.5e
CATEGORIES=	print
MASTER_SITES=	SF/mcj/mcj-source/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Tools to convert Xfig .fig files

RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png


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

NO_STAGE=	yes
.include <bsd.port.mk>
