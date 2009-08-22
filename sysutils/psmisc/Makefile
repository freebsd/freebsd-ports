# New ports collection makefile for:    psmisc
# Date created:         10 March 1998
# Whom:                 rantapaa@uswest.net
#
# $FreeBSD$
#

PORTNAME=	psmisc
PORTVERSION=	21.9
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the Linux pstree, killall and pidof commands

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes

CONFLICTS=	pstree-2.* \
		pidof-*

PLIST_FILES=	bin/killall \
		bin/pidof \
		bin/pstree bin/pstree.x11

MAN1=		pstree.1 killall.1

post-install:
	@${LN} -sf killall ${PREFIX}/bin/pidof

.include <bsd.port.mk>
