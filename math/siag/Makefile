# New ports collection makefile for:	siag (Scheme In A Grid)
# Version required:	2.80
# Date created:		27 Jan 1998
# Whom:			ports@freebsd.org
#
# $Id: Makefile,v 1.8 1998/09/26 04:41:35 itojun Exp $
#

DISTNAME=	siag-2.80
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.edu.stockholm.se/pub/siag/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tsiag-2.80.tar.gz

MAINTAINER=	ports@freebsd.org

BROKEN=		build

LIB_DEPENDS=	Xaw3d.6:${PORTSDIR}/x11-toolkits/Xaw3d

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/siag

do-build:
	(cd ${WRKSRC}; ${XMKMF}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE} Makefiles; \
	 ${SETENV} ${MAKE_ENV} ${MAKE} depend; \
	 ${SETENV} ${MAKE_ENV} ${MAKE})
	(cd ${WRKSRC}/tsiag; ${XMKMF}; \
	 ${SETENV} ${MAKE_ENV} ${MAKE} depend; \
	 ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	-(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} install install-misc)
	-(cd ${WRKSRC}/tsiag; ${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
