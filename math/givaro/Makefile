# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

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

GNU_CONFIGURE=	yes
CONFIGURE_ARGS =	--with-gmp="${LOCALBASE}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOXYGEN

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS +=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --with-docdir="${DOCSDIR}"
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/DEFAULT_CFLAGS=/{s/-O2 //;s/-pipe//;}' \
		-e '/DEBUG_CFLAGS=.*-DNDEBUG/s/$${DEBUG_CFLAGS} //' \
		-e '/^WARN_CFLAGS="-Wall"/d' \
		-e '/if test "x$$WARN" = "xyes"/s/$$/ WARN_CFLAGS="-Wall" ;/' \
		${WRKSRC}/configure
.if ${PORT_OPTIONS:MDOXYGEN}
	@${REINPLACE_CMD} -e 's/sed -i/& ""/' ${WRKSRC}/docs/Makefile.in
.endif

.if ${PORT_OPTIONS:MDOXYGEN}
post-install:
	@${TOUCH} ${DOCSDIR}/givaro-dev-html/.keep-me

.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${_MAKE_JOBS} \
	${MAKE_ARGS} check

.include <bsd.port.mk>
