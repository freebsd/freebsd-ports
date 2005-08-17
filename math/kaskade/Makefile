# New ports collection makefile for:	Kaskade
# Date created:		19 Sept. 1997
# Whom:			Pedro Giffuni
#
# $FreeBSD$
#

PORTNAME=	kaskade
PORTVERSION=	3.2.1
CATEGORIES=	math science
MASTER_SITES=	ftp://ftp.zib.de/pub/kaskade/3.x/
DISTNAME=	${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptive linear scalar elliptic and parabolic problem solver

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DIST_SUBDIR=	kaskade
WRKSRC=		${WRKDIR}/3.2.1

post-patch:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}
	${CP} ${FILESDIR}/configure ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.cmd ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.dat ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.ex ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.geo ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/kaskade.init ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/data/*.mat ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
