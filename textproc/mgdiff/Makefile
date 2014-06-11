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
SUB_FILES=	pkg-message

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/X11/mgdiff
	@${INSTALL_DATA} ${WRKSRC}/mgdiff.x[bp]m ${STAGEDIR}${PREFIX}/lib/X11/mgdiff

.include <bsd.port.mk>
