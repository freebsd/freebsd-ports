# New ports collection makefile for:	libwww
# Version required:	5.1j
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.7 1998/03/15 17:34:41 jseger Exp $
#

DISTNAME=	w3c-libwww-5.1j
PKGNAME=	libwww-5.1j
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${MKDIR} ${PREFIX}/include/www
	${INSTALL_DATA} ${WRKSRC}/Library/src/*.h ${PREFIX}/include/www
	${INSTALL_DATA} ${WRKSRC}/config.h ${PREFIX}/include/www
	@${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
