# $FreeBSD$

PORTNAME=	mdynamix
DISTVERSION=	5.2.8
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://www.fos.su.se/~sasha/${PORTNAME}/versions/
DISTNAME=	md${DISTVERSION:S/.//g}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	General purpose molecular dynamics code

LICENSE=	GPLv2+

LIB_DEPENDS=	libmpich.so:net/mpich

USES=		fortran gmake

ALL_TARGET=	default mpi
MAKE_ARGS=	FFLAGS="${FFLAGS} -ffast-math" LDFLAGS="${LDFLAGS}"
BINARY_ALIAS=	make=gmake gfortran=gfortran${GCC_DEFAULT}

PLIST_FILES=	bin/md bin/mdp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/md ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mdp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
