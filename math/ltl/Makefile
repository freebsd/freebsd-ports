# ex:ts=8
# Ports collection makefile for:	ltl
# Date created:			Sep 11, 2006
# Whom:				rossiya
#
# $FreeBSD$
#

PORTNAME=	ltl
PORTVERSION=	1.7.10
CATEGORIES=	math
MASTER_SITES=	http://www.mpe.mpg.de/~drory/ltl/

MAINTAINER=	rossiya@gmail.com
COMMENT=	A C++ class SSE library for scientific computing

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ARGS=	--with-cxx=gcc --disable-doxygen --prefix=${PREFIX} --includedir=${PREFIX}/include/LTL
MAKE_ENV=	prefix=${PREFIX} exec_prefix=${PREFIX}
MAKE_ARGS+=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALL_TARGET=	install install-data check distdir

PORTDOCS=	doc/html/*[h.][tp][mn][lg]
PLIST_FILES=	`ls ${WRKSRC}/doc/html/*[h.][tp][mn][lg] | ${SED} -e 's!${WRKSRC}/doc/html/!%%PORTDOCS%%%%DOCSDIR%%/!g'`

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && pwd && ${INSTALL_DATA} -v  ${PORTDOCS} ${DOCSDIR}
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
