# New ports collection makefile for:	AtomicParsley
# Date created:		2008-04-08
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	AtomicParsley
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}%20v${PORTVERSION}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	Command line program for reading parsing and setting MP4/M4A metadata

USE_ZIP=	yes

PLIST_FILES=	bin/AtomicParsley

do-build:
	cd ${WRKSRC} && ./build
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/AtomicParsley ${PREFIX}/bin

.include <bsd.port.mk>
