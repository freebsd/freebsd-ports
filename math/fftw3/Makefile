# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	fftw3
PORTVERSION=	3.0.1
PORTREVISION?=	3
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ 		\
		http://www.fftw.org/ 			\
		ftp://theory.lcs.mit.edu/pub/fftw/	\
		ftp://pm.cse.rmit.edu.au/pub/dsp/fftw/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	ahze@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

# current flavors: default, float, and long
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	CPPLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(FFTW3_FLAVOR) && ${FFTW3_FLAVOR}=="default"
MAN1=	fftw-wisdom-to-conf.1 fftw-wisdom.1
INFO=	fftw3
.else
MAN1=	fftw${FFTW3_SUFX}-wisdom.1
INSTALL_TARGET=	install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif

OPTIONS=	OPTIMIZED_CFLAGS "Enable optimized CFLAGS" off \
		SMP_THREADS "Enable FFTW SMP threads library" off \
		OPTIMIZED_ATHLON "Enable AMD Athlon/3dNow! optimizations" off \
		SSE "Enable SSE optimized routines" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS) && !defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O2 -ffast-math -fomit-frame-pointer"
.endif

.if ${ARCH}=="i386"
.if defined(WITH_OPTIMIZED_ATHLON)
CONFIGURE_ARGS+=--enable-k7
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O3 -fomit-frame-pointer -fno-schedule-insns \
		-malign-double -fstrict-aliasing -mpreferred-stack-boundary=4 \
		-ffast-math"
.endif

.if defined(WITH_SSE)
.if ${OSVERSION} < 500000
USE_GCC=	3.4
.endif
.if ${FFTW3_FLAVOR}=="default"
CONFIGURE_ARGS+=--enable-sse2
.else
.if ${FFTW3_FLAVOR}=="float"
CONFIGURE_ARGS+=--enable-sse
.endif
.endif
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O2"
.endif
.endif #end i386 only options

.if defined(WITH_SMP_THREADS)
CONFIGURE_ARGS+=--enable-threads
.endif

.if defined(FFTW3_FLAVOR)
.if ${FFTW3_FLAVOR}=="float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.else
.if ${FFTW3_FLAVOR}=="long"
LIB_DEPENDS+=	ml.0:${PORTSDIR}/math/ldouble
FFTW3_SUFX=	l
FFTW3_PKGNAMESUFFIX=	-long
CONFIGURE_ARGS+=--enable-long-double
.endif
.endif
.endif

.if ${FFTW3_FLAVOR}=="default"
PLIST_SUB+=	DEF=""
.else
PLIST_SUB+=	DEF="@comment "
.endif

PLIST_SUB+=	FFTW3_SUFX="${FFTW3_SUFX}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|/etc/fftw|${PREFIX}/etc/fftw|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/api/import-system-wisdom.c \
		${WRKSRC}/doc/fftw3* \
		${WRKSRC}/tools/*
	@${FIND} ${WRKSRC} -name \*.bak -type f -exec ${RM} -f {} \;
.if defined(FFTW3_FLAVOR) && ${FFTW3_FLAVOR}!="default"
	@${REINPLACE_CMD} -e \
		's|EXTRA_DIST = fftw-wisdom-to-conf.in||; \
		s|fftw-wisdom-to-conf.in||; \
		s|fftw-wisdom-to-conf: $(top_builddir)/config.status||; \
		s|bin_SCRIPTS = fftw-wisdom-to-conf||' \
			${WRKSRC}/tools/Makefile.in
.if ${FFTW3_FLAVOR}=="long"
	@${REINPLACE_CMD} -e 's|cosl sinl tanl||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|@LIBS@|-lml @LIBS@|'
.endif
.endif

.if defined(FFTW3_FLAVOR) && ${FFTW3_FLAVOR}!="default"
post-install:
	@${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.post.mk>
