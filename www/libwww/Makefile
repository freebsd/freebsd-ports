# New ports collection makefile for:	libwww
# Version required:	5.2.6
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PKGNAME=	libwww-5.2.6
DISTNAME=	w3c-${PKGNAME}
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static
DOCDIR=		${PREFIX}/share/doc/libwww
MAKE_ENV=	objformat=${PORTOBJFORMAT}

post-install:
	${INSTALL_DATA} ${WRKSRC}/modules/expat/xmlparse/xmlparse.h \
		${PREFIX}/include/w3c-libwww/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}/User
	${CP} -R ${WRKSRC}/Library/User/* ${DOCDIR}/User
	@${MKDIR} ${DOCDIR}/src
	${CP} ${WRKSRC}/Library/src/*.html ${DOCDIR}/src
.endif

.include <bsd.port.mk>
