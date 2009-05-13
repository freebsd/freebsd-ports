# New ports collection makefile for:	polymake
# Date created:				21 December 2004
# Whom:					Ewgenij Gawrilow <gawrilow@math.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	polymake
PORTVERSION=	2.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.tu-berlin.de/pub/combi/polymake/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}-install.diff

MAINTAINER=	gawrilow@math.tu-berlin.de
COMMENT=	A framework for experimental discrete geometry

LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	5.8.1+
USE_GCC=	3.4

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install-devel
NO_INSTALL_MANPAGES=	yes

PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501000
BROKEN=		Does not build with perl >= 5.10
.endif

do-configure:
	cd ${WRKSRC}; \
	${RM} -f build*/conf.make; \
	{ ${ECHO_CMD} CC='${CC}'; \
	  ${ECHO_CMD} CXX='${CXX}'; \
	  ${ECHO_CMD} Cflags='${CFLAGS} -I${PREFIX}/include'; \
	  ${ECHO_CMD} CXXflags='${CXXFLAGS} -I${PREFIX}/include'; \
	  ${ECHO_CMD} LDflags='-L${PREFIX}/lib'; \
	  ${ECHO_CMD} PREFIX='${PREFIX}'; \
	  ${ECHO_CMD} InstallTop='$${PREFIX}/share/polymake'; \
	  ${ECHO_CMD} InstallArch='$${PREFIX}/libexec/polymake'; \
	  ${ECHO_CMD} InstallDoc='$${PREFIX}${DOCSDIR:S,^${PREFIX},,}'; \
	  ${ECHO_CMD} InstallLinks='$${PREFIX}/bin'; \
	  ${ECHO_CMD} PerlExe='${PERL}'; \
	  ${ECHO_CMD} Arch=; \
	  ${ECHO_CMD} ProcessDep=none; \
	} | ${GMAKE} configure

pre-install:
	${RM} -f `find ${WRKSRC} -name '*.orig'`
	${SED} -e s,%%PERL_REAL_ARCH%%,`${PERL} -e 'use Config; print $$Config{archname}'`, <${.CURDIR}/pkg-plist > ${PLIST}

post-install:
	${CP} -p ${PREFIX}/libexec/polymake/Makefile ${PREFIX}/libexec/polymake/Makefile.devel

.include <bsd.port.post.mk>
