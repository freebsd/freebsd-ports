# New ports collection makefile for:	siag (Scheme In A Grid)
# Version required:	2.80
# Date created:		27 Jan 1998
# Whom:			Jun-ichiro itojun Itoh <itojun@itojun.org>
#
# $Id: Makefile,v 1.4 1998/07/06 17:41:14 itojun Exp $
#

DISTNAME=	siag-2.80
CATEGORIES=	math
# Since 2.67 (latest version on 3/7/1998) is seriously broken, I asked
# asami-san to put 2.80 into ftp.freebsd.org.  Thanks.
MASTER_SITES=	ftp://ftp.edu.stockholm.se/pub/siag/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tsiag-2.80.tar.gz

MAINTAINER=	itojun@itojun.org

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
