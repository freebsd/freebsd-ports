# New ports collection makefile for:    psmisc
# Date created:         10 March 1998
# Whom:                 rantapaa@uswest.net
#
# $FreeBSD$
#

PORTNAME=	psmisc
PORTVERSION=	21.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	psmisc

MAINTAINER=	pav@FreeBSD.org
COMMENT=	A port of the Linux pstree, killall and pidof commands

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes
USE_GETOPT_LONG=yes

CONFLICTS=	pstree-2.* \
		pidof-*

PLIST_FILES=	bin/killall \
		bin/pidof \
		bin/pstree bin/pstree.x11

MAN1=		pstree.1 killall.1

post-install:
	@${LN} -sf killall ${PREFIX}/bin/pidof

.include <bsd.port.mk>
