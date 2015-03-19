# Created by: past@ebs.gr
# $FreeBSD$

PORTNAME=	mgopen
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://pub.ellak.gr/fonts/${PORTNAME}/files/
DISTNAME=	MgOpen

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MgOpen greek fonts collection

USES=		fonts

NO_BUILD=	yes

FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
