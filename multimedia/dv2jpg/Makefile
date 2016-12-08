# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dv2jpg
PORTVERSION=	1.1
PORTREVISION=	13
CATEGORIES=	multimedia
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Type-2 DV codec-encoded AVI streams to mjpeg-encoded AVI

LICENSE=	GPLv2+

LIB_DEPENDS=	libdv.so:multimedia/libdv

USE_GNOME=	gdkpixbuf
MAKEFILE=	makefile

PORTDOCS=	README.avilib README.dv2jpg.html
PLIST_FILES=	bin/avijoin bin/dv2jpg

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	VIDEO-FORMAT
OPTIONS_SINGLE_VIDEO-FORMAT=	NTSC PAL
OPTIONS_DEFAULT=	NTSC

VIDEO-FORMAT_DESC=	Use default video format
NTSC_DESC=	Default video format NTSC
PAL_DESC=	Default video format PAL

post-extract:
	@${INSTALL_DATA} ${FILESDIR}/makefile ${WRKSRC}
	@${RM} ${WRKSRC}/avijoin ${WRKSRC}/dv2jpg ${WRKSRC}/*.o

post-patch:
	@${REINPLACE_CMD} -e 's|/opt/vidpb/lib/avilib.h|avilib.h|' \
		${WRKSRC}/avijoin.c

post-patch-PAL-on:
	@${REINPLACE_CMD} -e 's|VIDEO=NTSC|# VIDEO=NTSC|; \
		s|# VIDEO=PAL|VIDEO=PAL|' \
		${WRKSRC}/${MAKEFILE}

do-install:
.for f in avijoin dv2jpg
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
