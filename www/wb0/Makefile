# New ports collection makefile for:	wb0
# Date created:				2001-01-31
# Whom:					Trevor Johnson <trevor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wb0
PORTVERSION=	000324
PORTREVISION=	3
CATEGORIES=	www graphics
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/local/clock/wb0/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web browser for svgalib which can show pictures

RUN_DEPENDS=	lynx:${PORTSDIR}/www/lynx-current
LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		vga.1:${PORTSDIR}/graphics/svgalib \
		png.5:${PORTSDIR}/graphics/png

DOCS=		AUTHORS Changelog README etc/wb0/wb0.config.README
PORTDOCS=	${DOCS:T}
ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/wb0|${LOCALBASE}/etc|g ; \
		s|/usr/local/src/wb0/font/bit|${LOCALBASE}/share/wb0/|g ; \
		s|^static ||' ${WRKSRC}/wb0.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
