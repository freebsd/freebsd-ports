# New ports collection makefile for:	vbidecode
# Version required:	0.6.971023
# Date created:		Tue June 8 15:11:00 BST 1999
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	videotext-0.6.971023
CATEGORIES=	misc
MASTER_SITES=	http://elektra.e-technik.uni-ulm.de/~mbuck/download/

MAINTAINER=	roger@freebsd.org

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png \
		xview.3:${PORTSDIR}/x11-toolkits/xview

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAN1=		videotext.1 tunerctl.1

.include <bsd.port.pre.mk>

pre-install:
.if !exists(${X11BASE}/lib/X11/fonts/local)
	@${ECHO} "*********************************************************"
	@${ECHO} "Please update your XFree86 to version 3.3.3 or later"
	@${ECHO} "or add ${X11BASE}/lib/X11/fonts/local to your font path"
	@${ECHO} "in /etc/XF86Config."
	@${ECHO} "*********************************************************"
.endif

.include <bsd.port.post.mk>
