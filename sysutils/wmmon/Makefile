# New ports collection makefile for:   wmmon
# Version required:    1.0b2
# Date created:        27 November 1998
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

DISTNAME=	wmmon-1.0b2
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	ftp://ftp.tecnogi.com/pub/linux/WindowMaker/ \
		http://www.physics.adelaide.edu.au/~kkennawa/ \
		ftp://ftp.deva.net/pub/sources/X11/windowmaker/dockapps/

MAINTAINER=	sk-ports@vegamuse.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=   yes

WRKSRC=		${WRKDIR}/wmmon.app/wmmon

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${PREFIX}/share/doc/wmmon
	${INSTALL_MAN} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/wmmon
.endif

.include <bsd.port.post.mk>
