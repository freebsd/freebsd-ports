# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	ezfm
PORTVERSION=	0.4.3
PORTREVISION=	7
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTNAME=	EZFM-${PORTVERSION:R}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EZWGL-based file manager for X Window System

LICENSE=	GPLv2

LIB_DEPENDS=	libEZ.so:graphics/EZWGL

USES=		gmake jpeg tar:tgz

WRKSRC=		${WRKDIR}/EZFM-${PORTVERSION}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezfm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for file in ezfmExtension ezfmMagic ezfmrc
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/ezfmIcons
	(cd ${WRKSRC}/ezfmIcons && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ezfmIcons)
	${INSTALL_MAN} ${WRKSRC}/ezfm.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
