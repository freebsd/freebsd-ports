# Created by: andreas@marvin.robin.de
# $FreeBSD$

PORTNAME=	mgdiff
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical front end to the Unix diff command

USES=		imake motif
USE_XORG=	ice sm x11 xext xmu xp xt
MAN1=		mgdiff.1

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/mgdiff
	@${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m ${PREFIX}/lib/X11/mgdiff
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
