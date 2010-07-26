# New ports collection makefile for: fftw
# Date created:		Dec 28 1998
# Whom:			Lars Koeller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#    $MCom: ports-experimental/math/fftw3/Makefile,v 1.1 2006/03/28 00:08:57 ahze Exp $

PORTNAME=	fftw3
PORTVERSION=	3.2.2
PORTREVISION?=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.fftw.org/pub/fftw/ \
		ftp://ftp.fftw.org/pub/fftw/old/
PKGNAMESUFFIX=	${FFTW3_PKGNAMESUFFIX}
DISTNAME=	fftw-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

# current flavors: default, float, and long
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --enable-threads
CONFIGURE_ENV=	CPPLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(FFTW3_FLAVOR) && ${FFTW3_FLAVOR}=="default"
MAN1=	fftw-wisdom-to-conf.1 fftw-wisdom.1
INFO=	fftw3
.else
MAN1=	fftw${FFTW3_SUFX}-wisdom.1
INSTALL_TARGET=	install-pkgconfigDATA install-libLTLIBRARIES install-exec
.endif

OPTIONS=	OPTIMIZED_CFLAGS "Enable optimized CFLAGS" off

.include <bsd.port.pre.mk>

.if defined(WITH_OPTIMIZED_CFLAGS)
CONFIGURE_ENV+=	CFLAGS="${CFLAGS:N-O:N-O*} -O2 -ffast-math -fomit-frame-pointer"
.if ${FFTW3_FLAVOR}=="default" && ${MACHINE_CPU:Msse}
# !!Detect SSE and not SSE2!!
CONFIGURE_ARGS+=--enable-sse2
.else
.if ${FFTW3_FLAVOR}=="float" && ${MACHINE_CPU:Msse}
CONFIGURE_ARGS+=--enable-sse
.endif
.endif
.if ${MACHINE_CPU:M3dnow}
.if ${FFTW3_FLAVOR}!="float"
CONFIGURE_ARGS+=--enable-k7
.endif
CFLAGS_3DNOW=	${CFLAGS:N-O:N-O*} -O3 -fomit-frame-pointer -fno-schedule-insns \
		-fstrict-aliasing -mpreferred-stack-boundary=4 -ffast-math
.if ${ARCH} != "amd64"
CFLAGS_3DNOW+=	-malign-double
.endif
CONFIGURE_ENV+=	CFLAGS="${CFLAGS_3DNOW}"
.endif
.endif # end WITH_OPTIMIZED_CFLAGS

.if defined(FFTW3_FLAVOR)
.if ${FFTW3_FLAVOR}=="float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.else
.if ${FFTW3_FLAVOR}=="long"
. if ${OSVERSION} < 800000
ONLY_FOR_ARCHS= i386 sparc64
LIB_DEPENDS+=	ml.0:${PORTSDIR}/math/ldouble
. endif
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
.if ${FFTW3_FLAVOR}=="long" && ${OSVERSION} < 800000
	@${REINPLACE_CMD} -e 's|cosl sinl tanl||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
		's|@LIBS@|-lml @LIBS@|'
.endif
.endif

post-configure:
	@echo "#define F77_FUNC(name,NAME) name ## _" >>${WRKSRC}/config.h
	@echo "#define F77_FUNC_(name,NAME) name ## _" >>${WRKSRC}/config.h
	@echo "#define F77_FUNC_EQUIV 1" >>${WRKSRC}/config.h

.if defined(FFTW3_FLAVOR) && ${FFTW3_FLAVOR}!="default"
post-install:
	@${INSTALL_MAN} ${WRKSRC}/tools/fftw${FFTW3_SUFX}-wisdom.1 ${PREFIX}/man/man1
.endif

regression-test: build
	@cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} smallcheck

.include <bsd.port.post.mk>
