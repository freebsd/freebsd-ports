# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.10
CATEGORIES=	www
MASTER_SITES=	http://www.httrack.com/

MAINTAINER=	dirk@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX=${PREFIX} BINPATH=${PREFIX}/bin
INSTALLS_SHLIB=	yes
.if defined(NOPORTDOCS)
INSTALL_TARGET=	bininstall
.endif

post-install:
	${LN} -sf libhttrack.so.1 ${PREFIX}/lib/libhttrack.so

.include <bsd.port.mk>
