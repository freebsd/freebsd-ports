# New ports collection makefile for:	wb0
# Date created:				2001-01-31
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	wb0
PORTVERSION=	000324
PORTREVISION=	1
CATEGORIES=	www graphics
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/clock/wb0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web browser for svgalib which can show pictures

RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-current
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		vga.1:${PORTSDIR}/graphics/svgalib \
		png.5:${PORTSDIR}/graphics/png

USE_REINPLACE=	yes

PORTDOCS=	AUTHORS Changelog README
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/wb0|${LOCALBASE}/etc|g ; \
		s|/usr/local/src/wb0/font/bit|${LOCALBASE}/share/wb0/|g' \
		${WRKSRC}/wb0.c

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/wb0/wb0.config.README ${DOCSDIR}
.endif

.include <bsd.port.mk>
