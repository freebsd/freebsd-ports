# New ports collection makefile for:	cvcl
# Date created:		2006-09-15
# Whom:			Li-wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	cvcl
PORTVERSION=	2.5.1
CATEGORIES=	math
MASTER_SITES=	http://www.cs.nyu.edu/acsys/cvcl/download/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An automatic theorem prover for the SMT problem

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

DEPRECATED=	CVC Lite is no longer supported. Please use CVC3 (math/cvc3) for all your validity checking needs!
EXPIRATION_DATE=	2007-06-30

CONFIGURE_ARGS=	--with-arith=gmp \
		--with-extra-libs=${LOCALBASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-build=optimized
CXXFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/cvcl-20060527

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=	Broken with gcc 4.2
.endif

.include <bsd.port.post.mk>
