# New ports collection makefile for:	libwww
# Version required:	5.1i
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1998/02/08 02:24:44 jseger Exp $
#

DISTNAME=	w3c-libwww-5.1i
PKGNAME=	libwww-5.1i
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	${INSTALL_DATA} ${WRKSRC}/Library/src/*.h ${PREFIX}/include
	@${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
