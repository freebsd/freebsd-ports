# Created by: Mina Naguib <webmaster@topfx.com>
# $FreeBSD$

PORTNAME=	bsdbktr_tvtune
PORTVERSION=	0.02
CATEGORIES=	multimedia
MASTER_SITES=	http://mina.naguib.ca/dist/

MAINTAINER=	mina.website@naguib.ca
COMMENT=	Console Brooktree (bktr) TV tuner

LICENSE=	NONE

ONLY_FOR_ARCHS=	i386
PLIST_FILES=	bin/bsdbktr_tvtune
WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	bsdbktr_tvtune

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdbktr_tvtune ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
