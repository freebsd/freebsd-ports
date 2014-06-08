# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	transfig
PORTVERSION=	3.2.5e
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	SF/mcj/mcj-source/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools to convert Xfig .fig files

RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		imake
CFLAGS+=	-Wno-return-type
USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	xpm

CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP} ${_BINOWNGRP} -m ${BINMODE}" \
		INSTBINFLAGS="${_BINOWNGRP} -m ${BINMODE}" \
		INSTDATFLAGS="${_SHROWNGRP} -m ${SHAREMODE}" \
		INSTMANFLAGS="${_MANOWNGRP} -m ${MANMODE}"

post-install:
	for i in hr_HR hu_HU pl_PL ro_RO; do \
		${LN} -sf cs_CZ.ps ${STAGEDIR}${PREFIX}/lib/X11/fig2dev/$${i}.ps; \
	done
	for i in ja ja_JP.EUC ja_JP.eucJP ja_JP ja_JP.ujis ; do \
		${LN} -sf japanese.ps ${STAGEDIR}${PREFIX}/lib/X11/fig2dev/$${i}.ps; \
	done
	for i in ko ko_KR.EUC ko_KR.eucKR ko_KR ko_KR.ujis; do \
		${LN} -sf korean.ps ${STAGEDIR}${PREFIX}/lib/X11/fig2dev/$${i}.ps; \
	done

.include <bsd.port.mk>
