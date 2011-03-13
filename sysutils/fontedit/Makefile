# New ports collection makefile for:	fontedit
# Date created:		21 June 2000
# Whom:			Ben Smithurst <ben@scientia.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	fontedit
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bensmithurst.com/tarballs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for creating and editing console (syscons) font files

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

PLIST_FILES=	bin/fontdump bin/fontmake

do-install:
	@cd ${WRKSRC} && \
		${INSTALL_PROGRAM} fontdump fontmake ${PREFIX}/bin

.include <bsd.port.mk>
