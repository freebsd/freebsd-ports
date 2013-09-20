# Created by: ijliao
# $FreeBSD$

PORTNAME=	catdvi
PORTVERSION=	0.14
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DVI to text/plain translator

USE_TEX=	latex
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
ALL_TARGET=	# empty
MAKE_JOBS_UNSAFE=	yes

MAN1=		catdvi.1
PLIST_FILES=	bin/catdvi

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/catdvi ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/catdvi.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
