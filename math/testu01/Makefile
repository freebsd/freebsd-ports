# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	TestU01
PORTVERSION=	1.2.3
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://www.iro.umontreal.ca/~simardr/testu01/:0 \
		http://www.iro.umontreal.ca/~lecuyer/myftp/papers/:1
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}:0 testu01.pdf:1
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for statistical testing of uniform random number generators

LICENSE=	TestU01
LICENSE_NAME=	TestU01 license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

LIB_DEPENDS=	libgmp.so:math/gmp

CONFLICTS=	emboss-[0-9]*

USES=		gmake zip libtool localbase
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}"
MAKE_ARGS=	docdir="${DOCSDIR}" exdir="${EXAMPLESDIR}"
USE_LDCONFIG=	 yes
INSTALL_TARGET=	install-strip

CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|return|& (0)|' ${WRKSRC}/testu01/fftc.c

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ doc / /' ${WRKSRC}/Makefile.in
	@${FIND} -X ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
	-e '/^install-data-am\: /s/install-docDATA//'


post-patch-EXAMPLES-off:
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ examples / /' ${WRKSRC}/Makefile.in


post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/testu01.pdf ${STAGEDIR}${DOCSDIR}

do-test:
	@cd ${WRKSRC}/examples ; \
	for f in [mx]*.c ; do \
		${CC} ${CFLAGS} -c $${f} -I. -I../include ; \
	done ; \
	for t in [befs]*.c; do \
		case $${t} in \
			ex3.c) x="my16807.o" ;; \
			ex7.c) x="mrg32k3a.o xorshift.o" ;; \
			scat.c) continue ;; \
			*) x="" ;; \
		esac ; \
		${CC} ${CFLAGS} ${LDFLAGS} -o $${t%.c} $${t} -I. -I../include \
			-Wl,--as-needed $${x} ../testu01/.libs/libtestu01.so \
			../probdist/.libs/libprobdist.so ../mylib/.libs/libmylib.so -lm ; \
		${ECHO_CMD} "Running $${t%.c}..." ; \
		${SETENV} \
			LD_LIBRARY_PATH=../testu01/.libs:../probdist/.libs:../mylib/.libs \
			./$${t%.c} ; \
	done

.include <bsd.port.mk>
