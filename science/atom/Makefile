# $FreeBSD$

PORTNAME=	atom
DISTVERSION=	4.2.7-100
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	https://departments.icmab.es/leem/siesta/Pseudopotentials/Code/ \
		https://departments.icmab.es/leem/siesta/Pseudopotentials/:lic
PKGNAMESUFFIX=	-chemistry
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} atom_licence.html:lic
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program for DFT calculations in atoms

LICENSE=	ATOM_LICENSE
LICENSE_NAME=	ATOM ACADEMIC LICENCE
LICENSE_FILE=	${DISTDIR}/${DIST_SUBDIR}/atom_licence.html
LICENSE_PERMS=	# none

LIB_DEPENDS=	libGridXC.so:science/libgridxc \
		libxc.so:science/libxc \
		libxmlf90.so:textproc/xmlf90

USES=		fortran gmake tar:tgz

MAKE_ENV=	XMLF90_ROOT=${LOCALBASE} GRIDXC_ROOT=${LOCALBASE} LIBXC_ROOT=${LOCALBASE}
MAKE_ARGS=	FC=gfortran${GCC_DEFAULT} LDFLAGS="${LDFLAGS}"
ALL_TARGET=	default

PLIST_FILES=	bin/atm

post-patch:
	@${CP} ${WRKSRC}/arch.make.sample ${WRKSRC}/arch.make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atm ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
