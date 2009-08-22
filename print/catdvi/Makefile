# ex:ts=8
# Ports collection makefile for:	catdvi
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	catdvi
PORTVERSION=	0.14
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DVI to text/plain translator

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
MAKEFILE=	GNUmakefile
ALL_TARGET=	# empty

MAN1=		catdvi.1
PLIST_FILES=	bin/catdvi

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdvi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdvi.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
