# New ports collection makefile for:   dieharder
# Date created:        14 November 2008
# Whom:                bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	dieharder
PORTVERSION=	3.31.0
CATEGORIES=	math
MASTER_SITES=	http://www.phy.duke.edu/~rgb/General/dieharder/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A random number generator testsuite

LIB_DEPENDS=	gsl:${PORTSDIR}/math/gsl

MAKE_JOBS_UNSAFE=	yes

USE_DOS2UNIX=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
USE_LDCONFIG=	yes
MAN1=		dieharder.1
MAN3=		libdieharder.3

LICENSE=	GPLv2

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64 or sparc64
.endif

check test: build
	${WRKSRC}/dieharder/dieharder -a

.include <bsd.port.post.mk>
