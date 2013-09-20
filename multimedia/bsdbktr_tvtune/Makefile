# Created by: Mina Naguib <webmaster@topfx.com>
# $FreeBSD$

PORTNAME=	bsdbktr_tvtune
PORTVERSION=	0.02
CATEGORIES=	multimedia
MASTER_SITES=	http://mina.naguib.ca/dist/

MAINTAINER=	mina.website@naguib.ca
COMMENT=	A console Brooktree (bktr) TV tuner

ONLY_FOR_ARCHS=	alpha i386
PLIST_FILES=	bin/bsdbktr_tvtune
WRKSRC=	${WRKDIR}/${PORTNAME}
ALL_TARGET=	bsdbktr_tvtune

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsdbktr_tvtune ${PREFIX}/bin/

.include <bsd.port.mk>
