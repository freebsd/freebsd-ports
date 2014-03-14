# Created by: bf <bf2006a@yahoo.com>
# $FreeBSD$

PORTNAME=	TestU01
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.iro.umontreal.ca/~simardr/testu01/:0 \
		http://www.iro.umontreal.ca/~lecuyer/myftp/papers/:1
DISTFILES=	${PORTNAME}${EXTRACT_SUFX}:0 testu01.pdf:1
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Utilities for statistical testing of uniform random number generators

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp

USES=		gmake zip
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir="${PREFIX}/include/${PORTNAME}"
MAKE_ARGS=	docdir="${DOCSDIR}" exdir="${EXAMPLESDIR}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
CFLAGS+=	-fPIC
PLIST_SUB=	PORTNAME="${PORTNAME}"
CONFLICTS=	emboss-[0-9]*

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|return|& (0)|' ${WRKSRC}/testu01/fftc.c
.ifdef(NOPORTDOCS)
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ doc / /' ${WRKSRC}/Makefile.in
	@${FIND} -X ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} \
	-e '/^install-data-am\: /s/install-docDATA//'
.endif
.ifdef(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -e  '/^SUBDIRS \=/s/ examples / /' ${WRKSRC}/Makefile.in
.endif

.ifndef(NOPORTDOCS)
post-install:
	@${INSTALL_DATA} ${DISTDIR}/testu01.pdf ${DOCSDIR}
.endif

check regression-test test: build
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
