# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	makeztxt
PORTVERSION=	1.62
CATEGORIES=	sysutils
MASTER_SITES=	SF/gutenpalm/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility to create GutenPalm's zTXT format databases

LICENSE=	GPLv2

PLIST_FILES=	bin/makeztxt
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		gmake

MAKE_ENV+=	USEPOSIX=1 LONG_OPTS=1

post-patch:
	${REINPLACE_CMD} 's/-O2//' ${WRKSRC}/libztxt/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${STAGEDIR}${LOCALBASE}/bin/

.include <bsd.port.mk>
