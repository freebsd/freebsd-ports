# New ports collection makefile for:	cvc3
# Date created:		Mar. 24, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	cvc3
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.cs.nyu.edu/acsys/cvc3/download/${PORTVERSION}/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	An automatic theorem prover for the SMT problem

LIB_DEPENDS=	gmp:${PORTSDIR}/math/libgmp4

CONFIGURE_ARGS=	--enable-dynamic \
		--with-arith=gmp \
		--with-build=optimized \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib
CXXFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PERL5=	yes

.include <bsd.port.mk>
