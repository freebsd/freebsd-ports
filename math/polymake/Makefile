# New ports collection makefile for:	polymake
# Date created:				21 December 2004
# Whom:					Ewgenij Gawrilow <gawrilow@math.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	polymake
PORTVERSION=	2.1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.tu-berlin.de/pub/combi/polymake/

MAINTAINER=	gawrilow@math.tu-berlin.de
COMMENT=	A framework for experimental discrete mathematics

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install-devel
NO_INSTALL_MANPAGES=	yes

PLIST_SUB=	PERL=${PERL}

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		does not configure with perl 5.0
.endif

do-configure:
	cd ${WRKSRC}; \
	{ echo CC='${CC}'; \
	  echo CXX='${CXX}'; \
	  echo Cflags='${CFLAGS} -I${PREFIX}/include'; \
	  echo CXXflags='${CXXFLAGS} -I${PREFIX}/include'; \
	  echo LDflags='-L${PREFIX}/lib'; \
	  echo InstallTop='$${PREFIX}/share/polymake'; \
	  echo InstallArch='$${PREFIX}/libexec/polymake'; \
	  echo InstallDoc='$${PREFIX}${DOCSDIR:S,^${PREFIX},,}'; \
	  echo InstallLinks='$${PREFIX}/bin'; \
	  echo PerlExe='${PERL}'; \
	} | gmake configure

post-install:
	${PERL} -i -p -e 'print "PREFIX=${PREFIX}\n" if /InstallTop=/;' ${PREFIX}/libexec/polymake/Makefile

.include <bsd.port.post.mk>
