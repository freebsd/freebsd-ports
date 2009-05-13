# ex:ts=8
# New ports collection makefile for:   cln
# Date created:                Fab 11, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cln
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.ginac.de/CLN/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/cln/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Class Library for Numbers

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_AUTOTOOLS=	libtool:15
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-gmp
MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes

INFO=		cln

STRIP=		# none

CFLAGS+=	-fPIC
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" || ${ARCH} == "ia64"
BROKEN=		Does not compile on sparc64 or ia64
.endif

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile.in

pre-build:
.if exists(${LOCALBASE}/lib/libcln.so.3)
BROKEN=		Does not compile when older version is installed. Please pkg_delete old cln first
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/dvi
	${INSTALL_DATA} ${WRKSRC}/doc/*.dvi ${DOCSDIR}/dvi/
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html/
	@${MKDIR} ${DOCSDIR}/html/cln
	${INSTALL_DATA} ${WRKSRC}/doc/cln/*.html ${DOCSDIR}/html/cln/
.endif

.include <bsd.port.post.mk>
