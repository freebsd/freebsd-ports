# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.1.11
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.ginac.de/CLN/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/cln/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Class Library for Numbers

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--infodir=${PREFIX}/info --mandir=${MANPREFIX}/man \
		--with-gmp
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

MAN1=		cln-config.1
INFO=		cln

STRIP=		# none

CFLAGS+=	-fPIC
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on sparc64 or ia64"
.endif

pre-build:
.if exists(${LOCALBASE}/lib/libcln.so.3)
BROKEN=		"Does not compile when older version is installed. Please pkg_delete old cln first"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/dvi
	${INSTALL_DATA} ${WRKSRC}/doc/*.dvi ${DOCSDIR}/dvi
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
