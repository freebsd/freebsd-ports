# Created by: chuckr@FreeBSD.org
# $FreeBSD$

PORTNAME=	transfig
PORTVERSION=	3.2.5e
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF/mcj/mcj-source/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Tools to convert Xfig .fig files

RUN_DEPENDS=	ppmtogif:graphics/netpbm
LIB_DEPENDS=	libpng.so:graphics/png

USES=		alias ghostscript:run imake
CFLAGS+=	-Wno-return-type
USE_XORG=	xpm

MAKE_ARGS+=	INSTALLFLAGS="${COPY}" \
		INSTPGMFLAGS="${STRIP}" \
		INSTBINFLAGS="-m ${BINMODE}" \
		INSTDATFLAGS="-m ${SHAREMODE}" \
		INSTMANFLAGS="-m ${MANMODE}"

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
