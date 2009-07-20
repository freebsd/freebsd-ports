# New ports collection makefile for: ifdepd
# Date created:         03 03 2005
# Whom:                 Alexander Hausner <alex@hugo.bmg.gv.at>
# $FreeBSD$

PORTNAME=	ifdepd
PORTVERSION=	20050420
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://alex.bmg.gv.at/programs/

MAINTAINER=	alex@hugo.bmg.gv.at
COMMENT=	Interface Dependancy daemon

MAN8=		ifdepd.8

PLIST_FILES=	bin/ifdepd

USE_RC_SUBR=	${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
