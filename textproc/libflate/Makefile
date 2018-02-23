# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libflate
PORTVERSION=	2.0.1
CATEGORIES=	textproc devel
MASTER_SITES=	http://flate.dead-inside.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Template library used to deal with html code in CGI applications

PLIST_FILES=	lib/${PORTNAME}.a bin/checktpl

MAKE_ARGS+=	CC="${CC}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/checktpl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.a ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
