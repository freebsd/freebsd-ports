# New ports collection makefile for:	httrack
# Date created:		Sun Jun 17 10:28:52 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httrack
PORTVERSION=	3.20.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dirk
DISTNAME=	httrack-3.20-2

MAINTAINER=	dirk@FreeBSD.org
COMMENT=	Easy-to-use offline browser utility and website copier

WRKSRC=		${WRKDIR}/httrack-3.20/src
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--nouseftime --noinaddrt
CONFIGURE_ENV=	PREFIX=${PREFIX} BINPATH=${PREFIX}/bin
INSTALLS_SHLIB=	yes
.if defined(NOPORTDOCS)
INSTALL_TARGET=	bininstall libinstall config
.else
INSTALL_TARGET=	install config
.endif

post-install:
	${LN} -sf libhttrack.so.1 ${PREFIX}/lib/libhttrack.so

.include <bsd.port.mk>
