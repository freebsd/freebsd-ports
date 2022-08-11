PORTNAME=	nauty
PORTVERSION=	2.7r3
PORTEPOCH=	1
CATEGORIES=	math
MASTER_SITES=	https://users.cecs.anu.edu.au/~bdm/nauty/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	moritz@schmi.tt
COMMENT=	Nauty & Traces are programs for computing graph automorphism

LICENSE=	APACHE20

USES=		gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-tls # this makes nauty thread-safe, math/libnormaliz requires nauty with tls

MAKEFILE=	makefile
MAKE_ARGS=	includedir=${PREFIX}/include/${PORTNAME} # place headers into a dedicated directory

TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS NATIVE

NATIVE_DESC=		Build with native optimizations (-march=native, etc)
NATIVE_CONFIGURE_ON=	--disable-generic --enable-clz --enable-popcnt
NATIVE_CONFIGURE_OFF=	--enable-generic --disable-clz --disable-popcnt

post-build: # build shared libraries: based on how static libraries are created
	# rebuild .o files with -fPIC
	@cd ${WRKSRC} ; \
		objects=$$(ls *.o) ; \
		${RM} $${objects} ; \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} FREEBSD_EXTRA_CFLAGS="-fPIC" $${objects}
	# build libraries
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnauty.so -Wl,-soname,libnauty.so \
		nauty.o nautil.o nausparse.o naugraph.o schreier.o naurng.o traces.o gtools.o naututil.o \
		nautinv.o gutil1.o gutil2.o gtnauty.o naugroup.o nautycliquer.o
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnauty1.so -Wl,-soname,libnauty1.so \
		nauty1.o nautil1.o nausparse.o naugraph1.o schreier.o naurng.o traces.o gtools.o naututil1.o \
		nautinv1.o gutil1.o gutil2.o gtnauty.o naugroup.o nautycliquer.o
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnautyW.so -Wl,-soname,libnautyW.so \
		nautyW.o nautilW.o nausparseW.o naugraphW.o schreierW.o naurng.o traces.o gtoolsW.o naututilW.o \
		nautinvW.o gutil1W.o gutil2W.o gtnautyW.o naugroupW.o nautycliquerW.o
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnautyW1.so -Wl,-soname,libnautyW1.so \
		nautyW1.o nautilW1.o nausparseW.o naugraphW1.o schreierW.o naurng.o traces.o gtoolsW.o naututilW1.o \
		nautinvW1.o gutil1W1.o gutil2W1.o gtnautyW1.o naugroupW.o nautycliquerW.o
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnautyL.so -Wl,-soname,libnautyL.so \
		nautyL.o nautilL.o nausparseL.o naugraphL.o schreierL.o naurng.o traces.o gtoolsL.o naututilL.o \
		nautinvL.o gutil1L.o gutil2L.o gtnautyL.o naugroupL.o nautycliquerL.o
	cd ${WRKSRC} && ${CC} ${LDFLAGS} -shared -o libnautyL1.so -Wl,-soname,libnautyL1.so \
		nautyL1.o nautilL1.o nausparseL.o naugraphL1.o schreierL.o naurng.o traces.o gtoolsL.o naututilL1.o \
		nautinvL1.o gutil1L1.o gutil2L1.o gtnautyL1.o naugroupL.o nautycliquerL.o

post-install:
	# install shared libraries
.for l in libnauty.so libnauty1.so libnautyW.so libnautyW1.so libnautyL.so libnautyL1.so
	${INSTALL_LIB} ${WRKSRC}/${l} ${STAGEDIR}${PREFIX}/lib
.endfor
	# correct the include path in .pc files
	@${REINPLACE_CMD} -i '' -e 's|-I$${includedir}|&/${PORTNAME}|' ${STAGEDIR}${PREFIX}/libdata/pkgconfig/*.pc
	# strip executables
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/nug27.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
