# New ports collection makefile for:   cdargs
# Date created:        1 May 2004
# Whom:                Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cdargs
PORTVERSION=	1.31
CATEGORIES=	sysutils
MASTER_SITES=	http://www.skamphausen.de/software/cdargs/

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	Navigate the filesystem using a menu interface or a bookmark system

GNU_CONFIGURE=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
CFLAGS+=	-DHAVE_DECL_GETOPT

MAN1=	cdargs.1

PLIST_FILES=	bin/cdargs

post-patch:
	@${REINPLACE_CMD} -e 's,CXXFLAGS =,CXXFLAGS +=,' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
