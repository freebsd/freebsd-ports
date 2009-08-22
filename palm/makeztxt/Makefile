# New ports collection makefile for:	makeztxt
# Date created:		Oct 19, 2002
# Whom:			Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	makeztxt
PORTVERSION=	1.62
CATEGORIES=	palm
MASTER_SITES=	SF/gutenpalm/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command line utility to create GutenPalm's zTXT format databases

PLIST_FILES=	bin/makeztxt
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GMAKE=	yes

MAKE_ENV+=	USEPOSIX=1 LONG_OPTS=1

post-patch:
	${REINPLACE_CMD} 's/-O2//' ${WRKSRC}/libztxt/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makeztxt ${LOCALBASE}/bin/

.include <bsd.port.mk>
