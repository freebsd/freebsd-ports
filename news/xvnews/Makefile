# New ports collection makefile for:	xvnews
# Date created:		31 Jul 1996
# Whom:			shanee@augusta.de
#
# $FreeBSD$
#

PORTNAME=	xvnews
PORTVERSION=	2.3.2
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	shanee@augusta.de

BROKEN=		"Does not compile on -current; manpage does not build on -stable"

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes
MAN1=		xvnews.1

post-install:
	${INSTALL_MAN} $(WRKSRC)/xvnews.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
