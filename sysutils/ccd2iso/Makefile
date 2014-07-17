# Created by: Sergey A. Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ccd2iso
PORTVERSION=	0.9
PORTREVISION?=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	CloneCD to ISO converter

PLIST_FILES=	bin/ccd2iso

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ccd2iso ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
