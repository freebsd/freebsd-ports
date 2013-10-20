# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	y4mscaler
PORTVERSION=	9.0
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mir.com/DMG/Software/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Y4mscaler scales, crops, and shifts Y'CbCr video

LIB_DEPENDS=	liblavjpeg-2.0.so:${PORTSDIR}/multimedia/mjpegtools

USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCS=		COPYING ChangeLog INSTALL README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|COPT = -O2|#|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|CXXFLAGS =|CXXFLAGS = ${CXXFLAGS} |' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/y4mscaler ${STAGEDIR}${PREFIX}/bin/y4mscaler
	${INSTALL_MAN} ${WRKSRC}/y4mscaler.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
