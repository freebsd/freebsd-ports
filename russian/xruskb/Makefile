PORTNAME=	xruskb
PORTVERSION=	1.15.4
PORTREVISION=	4
CATEGORIES=	russian x11
MASTER_SITES=	ftp://ftp.yars.free.net/pub/source/xruskb/ \
		http://lav.yar.ru/download/xruskb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Keyboard layout switcher and indicator
WWW=		http://lav.yar.ru/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2 xorg
USE_XORG=	x11 ice xt xmu xext sm

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${PREFIX}/share

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	MOTIF DOCS

MOTIF_USES=	motif
MOTIF_CONFIGURE_ON=	--with-toolkit=motif
MOTIF_CONFIGURE_OFF=	--with-toolkit=none

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Xrus.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/Xrus

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ NEWS README* TODO xrus.doc-* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
