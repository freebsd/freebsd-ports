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

.include <bsd.port.mk>
