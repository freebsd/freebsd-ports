# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stp
PORTVERSION=	1407
CATEGORIES=	math
MASTER_SITES=	http://people.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
DISTNAME=	stp-fast-prover-r${PORTVERSION}

MAINTAINER=	6yearold@gmail.com
COMMENT=	A Decision Procedure for Bitvectors and Arrays

LICENSE=	MIT

USES=		bison gmake perl5
USE_BZIP2=	yes
USE_PERL5=	build

CONFIGURE_SCRIPT=	scripts/configure
CONFIGURE_ARGS=		--with-prefix=${PREFIX} \
			--with-gcc=${CC} \
			--with-g++=${CXX} \
			--with-fpic

PLIST_FILES=	bin/stp \
		include/stp/c_interface.h \
		include/stp/fdstream.h \
		lib/libstp.a
PLIST_DIRS=	include/stp

NO_STAGE=	yes
post-patch:
	@${ECHO_CMD} ${PORTVERSION} > ${WRKSRC}/src/main/versionString.stamp
	@${REINPLACE_CMD} -e 's/bash/sh/' ${WRKSRC}/scripts/Makefile.common
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's/-DNDEBUG//; s/-O3/-O0/; s/-fomit-frame-pointer//' \
		${WRKSRC}/scripts/Makefile.common
.endif

do-configure:
	cd ${WRKSRC} && ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}

.include <bsd.port.pre.mk>

.if (${OSVERSION} < 802502)
IGNORE=	stp needs log2(3)
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: unrecognized command line option -march=native
.endif

.include <bsd.port.post.mk>
