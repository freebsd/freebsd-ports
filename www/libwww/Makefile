# New ports collection makefile for:	libwww
# Version required:	5.1m1
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.13 1998/11/02 02:48:27 jseger Exp $
#

PKGNAME=	libwww-5.2.1
DISTNAME=	w3c-${PKGNAME}
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/

MAINTAINER=	jseger@FreeBSD.org

FETCH_BEFORE_ARGS=	-b
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
