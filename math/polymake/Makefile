# New ports collection makefile for:	polymake
# Date created:				21 December 2004
# Whom:					Ewgenij Gawrilow <gawrilow@math.tu-berlin.de>
#
# $FreeBSD$
#

PORTNAME=	polymake
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.math.tu-berlin.de/pub/combi/polymake/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}-${PORTVERSION}-p1.diff.bz2 ${PORTNAME}-${PORTVERSION}-p2.diff.bz2

MAINTAINER=	gawrilow@math.tu-berlin.de
COMMENT=	A framework for experimental discrete mathematics

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PERL5=	yes

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install install-devel
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BROKEN=		does not configure with perl 5.0
.endif

do-configure:
	cd ${WRKSRC}; \
	rm -f build*/conf.make; \
	{ echo CC='${CC}'; \
	  echo CXX='${CXX}'; \
	  echo Cflags='${CFLAGS} -I${PREFIX}/include'; \
	  echo CXXflags='${CXXFLAGS} -I${PREFIX}/include'; \
	  echo LDflags='-L${PREFIX}/lib'; \
	  echo PREFIX='${PREFIX}'; \
	  echo InstallTop='$${PREFIX}/share/polymake'; \
	  echo InstallArch='$${PREFIX}/libexec/polymake'; \
	  echo InstallDoc='$${PREFIX}${DOCSDIR:S,^${PREFIX},,}'; \
	  echo InstallLinks='$${PREFIX}/bin'; \
	  echo PerlExe='${PERL}'; \
	} | gmake configure

pre-install:
	rm -f `find ${WRKSRC} -name '*.orig'`

post-install:
	cp -p ${PREFIX}/libexec/polymake/Makefile ${PREFIX}/libexec/polymake/Makefile.devel
	rm ${PREFIX}/bin/polymake
	${SED} -e '/^use lib/ s|"[^"]*/perlx"|"${PREFIX}/libexec/polymake/perlx"|' \
	   ${PREFIX}/share/polymake/perl/polymake >${PREFIX}/bin/polymake
	chmod 755 ${PREFIX}/bin/polymake
	mkdir ${PREFIX}/libexec/polymake/perlx
	eval `${PERL} -V:archname`; \
	mv ${PREFIX}/share/polymake/perlx/$$archname ${PREFIX}/libexec/polymake/perlx/${PERL_ARCH}; \
	${REINPLACE_CMD} -e "s|/share/polymake/perlx/$$archname/|/libexec/polymake/perlx/${PERL_ARCH}/|g" ${PREFIX}/libexec/polymake/perlx/${PERL_ARCH}/auto/Poly/Ext/.packlist
	rm -f ${PREFIX}/libexec/polymake/perlx/${PERL_ARCH}/auto/Poly/Ext/.packlist.bak
	rmdir ${PREFIX}/share/polymake/perlx

.include <bsd.port.post.mk>
