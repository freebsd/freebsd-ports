# Created by: michael johnson <ahze@ahze.net>
# $FreeBSD$

PORTNAME=	y4mscaler
PORTVERSION=	9.0
PORTREVISION=	9
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mir.com/DMG/Software/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Y4mscaler scales, crops, and shifts Y'CbCr video

BROKEN=		Conflicts with mjpegtools on /usr/local/bin/y4mscaler
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

LIB_DEPENDS=	liblavjpeg.so:${PORTSDIR}/multimedia/mjpegtools

USES=		gmake tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCS=		COPYING ChangeLog INSTALL README TODO

OPTIONS_DEFINE=	DOCS

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
