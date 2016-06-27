# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	dieharder
PORTVERSION=	3.31.1
PORTREVISION=	3
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/ LOCAL/bf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Random number generator testsuite

LICENSE=	GPLv2

LIB_DEPENDS=	libgsl.so:math/gsl

MAKE_JOBS_UNSAFE=	yes

USES=		dos2unix libtool tar:tgz
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.endif

check test: build
	${WRKSRC}/dieharder/dieharder -a

.include <bsd.port.post.mk>
