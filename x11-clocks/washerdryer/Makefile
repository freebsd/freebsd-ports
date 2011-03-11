# New ports collection makefile for:	washerdryer
# Date Created:				Thu Nov  8 00:07:24 EST 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	washerdryer
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://lucille.dhs.org/
DISTNAME=	washerDryer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A dockapp that keeps track of the loads in your washer and dryer

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

WRKSRC=		${WRKDIR}/${DISTNAME}/washerDryer
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk12
USE_XORG=	x11 xau xdmcp xext xi xpm

MANCOMPRESSED=	yes
MAN1=		washerDryer.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/washerDryer ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/washerDryer.1.gz ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/wdryerrc ${DOCSDIR}/wdryerrc.example
.endif

post-install:
	@${SED} 's|%%EXAMPLE%%|${DOCSDIR}/wdryerrc.example|' ${PKGMESSAGE}

.include <bsd.port.mk>
