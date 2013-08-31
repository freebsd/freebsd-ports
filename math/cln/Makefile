# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cln
PORTVERSION=	1.3.2
CATEGORIES=	math devel
MASTER_SITES=	http://www.ginac.de/CLN/ \
		http://www.mirrors.wiretapped.net/security/cryptography/libraries/math/cln/ \
		ftp://ftpthep.physik.uni-mainz.de/pub/gnu/

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Class Library for Numbers

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gmp
USE_LDCONFIG=	yes

INFO=		cln
MAN1=		pi.1

STRIP=		# none

CFLAGS+=	-fPIC
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|' ${WRKSRC}/Makefile.in

pre-build:
.if exists(${LOCALBASE}/lib/libcln.so.3)
BROKEN=		Does not compile when older version is installed. Please pkg_delete old cln first
.endif

.include <bsd.port.post.mk>
