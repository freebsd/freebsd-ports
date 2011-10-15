# New ports collection makefile for:	givaro
# Date created: 	5 Oct 2011
# Whom: 	b.f. <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	givaro
PORTVERSION=	3.5.0
CATEGORIES=	math
MASTER_SITES=	https://forge.imag.fr/frs/download.php/133/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	A C++ library for computer algebra

LICENSE=	CeCILL-Bv1
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] B license, version 1
LICENSE_FILE=	${WRKSRC}/Licence_CeCILL-B_V1-en.txt
LICENSE_PERMS=	auto-accept

LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

OPTIONS=	DOCS "build HTML documents (requires doxygen)" off

GNU_CONFIGURE=	yes
CONFIGURE_ARGS =	--with-gmp="${LOCALBASE}"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_DOCS)  && !defined(NOPORTDOCS)
BUILD_DEPENDS +=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --with-docdir="${DOCSDIR}"
.elifndef(NOPORTDOCS)
NOPORTDOCS=	yes
.endif

.if ${LOCALBASE} == "/usr/local"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/{s/-O2 //;s/-pipe//;}' \
		-e '/DEBUG_CFLAGS=.*-DNDEBUG/s/$${DEBUG_CFLAGS} //' \
		-e '/^WARN_CFLAGS="-Wall"/d' \
		-e '/if test "x$$WARN" = "xyes"/s/$$/ WARN_CFLAGS="-Wall" ;/' \
		${WRKSRC}/configure
.if defined(WITH_DOCS)  && !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/sed -i/& ""/' ${WRKSRC}/docs/Makefile.in
.endif

.if defined(WITH_DOCS)  && !defined(NOPORTDOCS)
post-install:
	@${TOUCH} ${DOCSDIR}/givaro-dev-html/.keep-me

.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.include <bsd.port.post.mk>
