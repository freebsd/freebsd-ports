# New ports collection makefile for:	libwww
# Version required:	5.1l
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $Id: Makefile,v 1.8 1998/03/25 12:33:26 tg Exp $
#

PKGNAME=	libwww-5.1l
DISTNAME=	w3c-${PKGNAME}
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.w3.org/pub/libwww/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
DOCDIR=		${PREFIX}/share/doc/libwww

post-install:
	@${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
