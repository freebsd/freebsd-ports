# New ports collection makefile for:	libwww
# Version required:	5.1m1
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.9 1998/04/11 03:20:03 jseger Exp $
#

PKGNAME=	libwww-5.1m1
DISTNAME=	w3c-${PKGNAME}
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
DOCDIR=		${PREFIX}/share/doc/libwww

WRKSRC=		${WRKDIR}/w3c-libwww-5.1m
post-install:
	@${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
