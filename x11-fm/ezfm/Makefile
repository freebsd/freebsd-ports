# New ports collection makefile for:	ezfm
# Version required:			0.1
# Date created:				27 July 1998
# Whom:					Andrey Zakhvatov
#
# $Id$
#

DISTNAME=	EZFM-0.1-src
PKGNAME=	ezfm-0.1
CATEGORIES=	x11-fm
MASTER_SITES=	ftp://ftp.ma.utexas.edu/pub/mzou/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		EZ\\.1\\.:${PORTSDIR}/graphics/EZWGL

WRKSRC=		${WRKDIR}/EZFM-0.1
USE_X_PREFIX=	yes

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
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/ezfm
	@ ${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/ezfm
.endif

.include <bsd.port.mk>
