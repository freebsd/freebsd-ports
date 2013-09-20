# Created by: Jim Mock <jim@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rtfreader
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.fiction.net/blong/programs/
DISTNAME=	ms-rtf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable application/ms-rtf parser

ALL_TARGET=	rtfreader
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
PLIST_FILES=	bin/rtfreader

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rtfreader ${PREFIX}/bin

.include <bsd.port.mk>
