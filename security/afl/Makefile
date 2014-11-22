# Created by: Fabian Keil <fk@fabiankeil.de>
# $FreeBSD$

PORTNAME=	afl
PORTVERSION=	0.61b
CATEGORIES=	security
MASTER_SITES=	http://lcamtuf.coredump.cx/afl/releases/

MAINTAINER=	fk@fabiankeil.de
COMMENT=	Fast instrumented fuzzer

USES=		compiler gmake tar:tgz

OPTIONS_DEFINE=			DEBUG DOCS TEST_INSTRUMENTATION
TEST_INSTRUMENTATION_DESC=	Execute tests expected to fail in jails
OPTIONS_DEFAULT=		DOCS

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	Uses binary instrumentation

# XXX replace with bsd.port.options.mk once 8.4-RELEASE is EOL
# COMPILER_TYPE is defined in .pre without /usr/share/mk/bsd.compiler.mk
.include <bsd.port.pre.mk>

.if (${COMPILER_TYPE} == "clang" && ${ARCH} == "i386")
# Clang i386 emits .cfi_sections which base as(1) doesn't understand
BUILD_DEPENDS +=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
RUN_DEPENDS +=		${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
.endif

post-patch:
.if ! ${PORT_OPTIONS:MTEST_INSTRUMENTATION}
# afl needs shmget() which usually isn't available in jails. Disabling
# the instrumentation tests makes sure building packages in jails works
# by default anyway.
	${REINPLACE_CMD} -e 's@^\(all.*\) test_build@\1@' ${WRKSRC}/Makefile
.endif
	${REINPLACE_CMD} -e 's@ -O3@@; s@ -g@@' \
		-e 's@install -m 755@${INSTALL_PROGRAM}@' \
		${WRKSRC}/Makefile
.if (${COMPILER_TYPE} == "clang" && ${ARCH} == "i386")
	${REINPLACE_CMD} -e 's@\(  as_params\[0\] = "\)@\1${LOCALBASE}/bin/@' \
		${WRKSRC}/afl-as.c
.endif
# XXX remove once 8.4-RELEASE is EOL
# GNU as 2.15 doesn't understand lahf/sahf on amd64
	${REINPLACE_CMD} -e 's@ifdef.*\(__OpenBSD__\)@if defined(\1) || \
		(defined(__FreeBSD__) \&\& __FreeBSD__ < 9)@' \
		${WRKSRC}/afl-as.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/COPYING ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
