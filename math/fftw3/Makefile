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

MAINTAINER=	bf@FreeBSD.org
COMMENT?=	Fast C routines to compute the Discrete Fourier Transform

# current flavors: default, float, and long
FFTW3_FLAVOR?=	default
FFTW3_SUFX=

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--enable-shared --enable-threads
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

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
CFLAGS+=	-O3 -ffast-math -fstrict-aliasing
.  if !defined(WITH_DEBUG)
CFLAGS+=	-fomit-frame-pointer
.  endif
.  if empty(CC:Mclang)
CODELET_OPTIM +=	-fno-schedule-insns -fno-web -fno-loop-optimize \
			--param inline-unit-growth=1000 \
			--param large-function-growth=1000
.  endif
.  if ${ARCH} == "i386"
CFLAGS+=	-malign-double
CODELET_OPTIM +=	-O
.  endif
CONFIGURE_ENV +=	CODELET_OPTIM="${CODELET_OPTIM}"
WITHOUT_NO_STRICT_ALIASING=	yes
.  if !empty(MACHINE_CPU:Msse)
.    if ${FFTW3_FLAVOR} == "default"
CONFIGURE_ARGS+=--enable-sse2
.    elif ${FFTW3_FLAVOR} == "float"
CONFIGURE_ARGS+=--enable-sse
.    endif
.  elif !empty(ARCH:Mpowerpc*)
#users should set ALTIVEC_ARG to be empty if sysctl hw.altivec=0 on the target machine
ALTIVEC_ARG?=	--enable-altivec
CONFIGURE_ARGS+=	${ALTIVEC_ARG}
.  endif
.endif # end WITH_OPTIMIZED_CFLAGS

.if defined(FFTW3_FLAVOR)
.if ${FFTW3_FLAVOR}=="float"
FFTW3_SUFX=	f
FFTW3_PKGNAMESUFFIX=	-float
CONFIGURE_ARGS+=--enable-float
.else
.if ${FFTW3_FLAVOR}=="long"
. if ${OSVERSION} < 800000
ONLY_FOR_ARCHS =	i386 sparc64
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
