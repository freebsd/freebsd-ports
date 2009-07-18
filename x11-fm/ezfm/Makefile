# New ports collection makefile for:	ezfm
# Date created:				27 July 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	ezfm
PORTVERSION=	0.4.3
PORTREVISION=	4
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
DISTNAME=	EZFM-0.4-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	EZWGL-based file manager for X Window System

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		EZ.1:${PORTSDIR}/graphics/EZWGL

WRKSRC=		${WRKDIR}/EZFM-${PORTVERSION}
USE_GMAKE=	yes

MAN1=		ezfm.1

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/ezfm ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/ezfm
.for file in ezfmExtension ezfmMagic ezfmrc
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/ezfm
.endfor
	@ ${MKDIR} ${PREFIX}/share/ezfm/ezfmIcons
	@ cd ${WRKSRC}/ezfmIcons; tar -cf - . | (cd ${PREFIX}/share/ezfm/ezfmIcons; tar -xf - )
	@ ${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
.endif

.include <bsd.port.mk>
