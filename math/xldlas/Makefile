# Created by: Pedro Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	xldlas
PORTVERSION=	0.85
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	SUNSITE/apps/graphics/visualization
EXTRACT_SUFX=	-source.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XForms-based statistics package

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms

WRKSRC=		${WRKDIR}/xldlas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xldlas ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xldlas.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -R ${WRKSRC}/help ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
