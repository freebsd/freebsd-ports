# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.1.8
CATEGORIES=	math devel
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Class Library for Numbers

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_GCC=	3.3
USE_GNOME=	gnomehack gnometarget lthack pkgconfig
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--infodir=${PREFIX}/info --mandir=${MANPREFIX}/man \
		--with-gmp
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		cln-config.1
INFO=		cln

STRIP=		# none

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/dvi
	${INSTALL_DATA} ${WRKSRC}/doc/*.dvi ${DOCSDIR}/dvi
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
