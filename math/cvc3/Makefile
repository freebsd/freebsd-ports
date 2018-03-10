# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	cvc3
PORTVERSION=	2.4.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://www.cs.nyu.edu/acsys/cvc3/download/${PORTVERSION}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Automatic theorem prover for the SMT problem

LIB_DEPENDS=	libgmp.so:math/gmp

CONFIGURE_ARGS=	--enable-dynamic \
		--with-arith=gmp \
		--with-build=optimized \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib
CXXFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
USES=		bison gmake pathfix perl5
PATHFIX_MAKEFILEIN=	Makefile
USE_CXXSTD=	gnu++98
USE_GCC=	any
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/Makefile.std
	${REINPLACE_CMD} -e 's,.*$$(LDCONFIG).*,,' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_PROGRAM} `readlink ${WRKSRC}/bin/cvc3` ${STAGEDIR}${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcvc3.so.5.0.0

.include <bsd.port.mk>
