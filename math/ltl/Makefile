# ex:ts=8
# Ports collection makefile for:	ltl
# Date created:			Sep 11, 2006
# Whom:				rossiya
#
# $FreeBSD$
#

PORTNAME=	ltl
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.mpe.mpg.de/~drory/ltl/

MAINTAINER=	rossiya@gmail.com
COMMENT=	A C++ class SSE library for scientific computing

LIB_DEPENDS=	lapack.4:${PORTSDIR}/math/lapack \
		blas.2:${PORTSDIR}/math/blas

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-cxx=gcc --disable-doxygen --prefix=${PREFIX} --includedir=${PREFIX}/include/LTL
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALL_TARGET=	install install-data distdir

PORTDOCS=	*.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/html/${docs} ${DOCSDIR}
.endfor
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
