# New ports collection makefile for:	wmtop
# Date created:				15 May 2000
# Whom:					Dan Piponi <wmtop@tanelorn.demon.co.uk>
#
# $FreeBSD$

PORTNAME=	dog
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://jl.photodex.com/dog/

MAINTAINER=	rooneg@electricjellyfish.net
COMMENT=	Dog writes the contents of each given file, URL, or stdin

USE_GMAKE=	yes
ALL_TARGET=	dog

MAN1=		dog.1
PLIST_FILES=	bin/dog

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dog ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/dog.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
