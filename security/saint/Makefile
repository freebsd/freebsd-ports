# New ports collection makefile for:	SAINT
# Version required:	1.5
# Date created:		27 Jan 2000
# Whom:			Carl Johan Madestrand <calle.madestrand@norrgarden.se>
#
# $FreeBSD$
#

DISTNAME=	saint-1.5
CATEGORIES=	security
MASTER_SITES=	http://www.wwdsi.com/saint/downloads/

MAINTAINER=	calle.madestrand@norrgarden.se

USE_PERL5=	yes
WRKSRC=		${WRKDIR}/saint-1.5
MAKE_ENV=	XFLAGS="DAUTH_GID_T=int -DSYS_ERRLIST_DECLARED -DFDSETSIZE=2048"
ALL_TARGET=	freebsd
INSTALL_TARGET=	all

pre-configure:
		@ cd ${WRKSRC}; ${SETENV} ${PERL5} ${WRKSRC}/reconfig

pre-install:
		${MKDIR} ${PREFIX}/saint-1.5
		${TAR} --directory ${WRKSRC} -cf - . --exclude src --exclude Makefile | \
			${TAR} --directory ${PREFIX}/saint-1.5 -xf -

.include <bsd.port.mk>
