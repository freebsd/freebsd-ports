# New ports collection makefile for:	smu
# Date created:		2011-03-07
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smu
PORTVERSION=	1.3
CATEGORIES=	textproc
MASTER_SITES=	http://s01.de/~tox/files/smu/ \
		http://mirror.4bit.ws/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A simple interpreter for a simplified markdown dialect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MAN1=	smu.1
PLIST_FILES=	bin/smu

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/smu ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/smu.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
