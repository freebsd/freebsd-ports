# New ports collection makefile for:	libwww
# Date created:		18 Feb 1996
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	libwww
PORTVERSION= 	5.2.8
CATEGORIES=	www devel
MASTER_SITES=	http://www.w3.org/Library/Distribution/
DISTNAME=	w3c-${PKGNAME}

MAINTAINER=	jseger@FreeBSD.org

USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--enable-shared --enable-static --with-zlib
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
