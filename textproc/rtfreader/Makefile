# New ports collection makefile for:	rtfreader
# Date created:			14 Jan 2002
# Whom:				Jim Mock <jim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtfreader
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.fiction.net/blong/programs/
DISTNAME=	ms-rtf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable application/ms-rtf parser

ALL_TARGET=	rtfreader
PLIST_FILES=	bin/rtfreader

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rtfreader ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
