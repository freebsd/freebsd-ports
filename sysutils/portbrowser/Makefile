# New ports collection makefile for:	portbrowser
# Date created:		8 November, 2004
# Whom:			hrs
#
# $FreeBSD$

PORTNAME=	portbrowser
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.bytelabs.org/
DISTNAME=	pb-browser-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Graphical frontend for the BSD ports system

USE_GNOME=	gtk20
USE_REINPLACE=	yes
MAKE_ENV=	MANDIR=${PREFIX}/man/man \
		BINDIR=${PREFIX}/bin \
		NOMANCOMPRESS=YES
PLIST_FILES=	bin/pbrowser

MAN1=		pbrowser.1

post-patch:
	@${REINPLACE_CMD} -e 's|"INDEX"|"${INDEXFILE}"|' \
		${WRKSRC}/src/pkgobject.h

.include <bsd.port.mk>
