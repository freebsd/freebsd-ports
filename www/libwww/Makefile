# New ports collection makefile for:	libwww
# Version required:	5.1m1
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.14 1999/01/26 03:00:34 steve Exp $
#

PKGNAME=	libwww-5.2.1
DISTNAME=	w3c-${PKGNAME}
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
