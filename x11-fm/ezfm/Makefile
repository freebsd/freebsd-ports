# Created by: Andrey Zakhvatov <andy@icc.surw.chel.su>
# $FreeBSD$

PORTNAME=	ezfm
PORTVERSION=	0.4.3
PORTREVISION=	7
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTNAME=	EZFM-${PORTVERSION:R}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	EZWGL-based file manager for X Window System

LICENSE=	GPLv2

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libEZ.so:${PORTSDIR}/graphics/EZWGL

WRKSRC=		${WRKDIR}/EZFM-${PORTVERSION}
USES=		gmake

MAN1=		ezfm.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezfm ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/ezfm
.for file in ezfmExtension ezfmMagic ezfmrc
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/ezfm
.endfor
	@${MKDIR} ${PREFIX}/share/ezfm/ezfmIcons
	${TAR} -C ${WRKSRC}/ezfmIcons -cf - . | ${TAR} -xf - -C \
		${PREFIX}/share/ezfm/ezfmIcons
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
