# Created by: NAKATA, Maho <maho@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libint
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.files.chem.vt.edu/chem-dept/valeev/software/libint/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Evaluate the integrals in modern atomic and molecular theory

# USE_GCC=yes is required because libint is used with mpqc which is built
# by gfortran48 (from lang/gcc) and these two libraries each try to pull in
# a different version of libgcc_s.so which fails.  Forcing this port to
# build with lang/gcc as well resolves the conflict that manifests in
# science/libghemical

USES=		perl5 gmake libtool
USE_GCC=	yes
USE_LDCONFIG=	yes
ALL_TARGET=	# empty

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared

post-patch:
	@${REINPLACE_CMD} -e 's| -rpath|${LDFLAGS} -rpath|g' \
		${WRKSRC}/src/lib/MakeVars.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
