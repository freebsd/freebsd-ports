# New ports collection makefile for:	tklregexp
# Date created:        2 May 2000
# Whom:                Patrick Seal <patseal@hyperhost.net>
#
# $FreeBSD$
#

PORTNAME=	tkregexp
PORTVERSION=	3.0
PORTREVISION=	3
CATEGORIES=	misc tk
MASTER_SITES=	http://laurent.riesterer.free.fr/regexp/
DISTNAME=	visual_regexp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive regexp design tool

USE_TK_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/tkregexp

post-patch:
	@${REINPLACE_CMD} 's|wish8.3|${WISH}|' ${WRKSRC}/visual_regexp.tcl

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/visual_regexp.tcl ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
