# New ports collection makefile for:	mudix
# Date created:		26 Mar 2000
# Whom:			will
#
# $FreeBSD$
#

PORTNAME=	mudix
PORTVERSION=	4.3
CATEGORIES=	net
MASTER_SITES=	http://dw.nl.eu.org/mudix/

MAINTAINER=	scorpio@drkshdw.org
COMMENT=	Ncurses-based MUD client with triggers, aliases, colors

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/mudix
ALL_TARGET=	# none

pre-patch:
	@${REINPLACE_CMD} -e 's|-O -g|\@CFLAGS\@|g ; \
		 s|mudix.h conf.h||g' ${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mudix ${PREFIX}/bin

.include <bsd.port.mk>
