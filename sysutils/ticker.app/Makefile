# New ports collection makefile for:	ticker.app
# Date created:				Sun Oct 14 15:14:24 EDT 2001
# Whom:                                 Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	ticker.app
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://seiichisato.jp/dockapps/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ticker dockapp for Window Maker

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_BZIP2=	yes
USE_XORG=	x11 xpm
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

MAN1=		ticker.app.1
PORTDOCS=	ChangeLog README
PLIST_FILES=	bin/ticker.app

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
