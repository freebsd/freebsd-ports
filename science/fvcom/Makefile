# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	fvcom
PORTVERSION=	2.7.1
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://fvcom.smast.umassd.edu/FVCOM/index.html/
DISTNAME=	sourcecode1
DIST_SUBDIR=	fvcom

MAINTAINER=	jwbacon@tds.net
COMMENT=	Unstructured Grid Finite Volume Coastal Ocean Model

# Check netcdf lib for Fortran support!
LIB_DEPENDS+=	netcdff:${PORTSDIR}/science/netcdf-ftn \
		lapack:${PORTSDIR}/math/lapack \
		blas:${PORTSDIR}/math/lapack

USES=		fortran
WRKSRC=		${WRKDIR}/FVCOM2.7.1/FVCOM_source

PLIST_FILES=	bin/${PORTNAME}${PKGNAMESUFFIX}

RESTRICTED=	may not be redistributed because of licensing reasons

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DIST_SUBDIR}/${DISTFILES})
IGNORE=	may not be redistributed because of licensing reasons.\
	Please register at http://fvcom.smast.umassd.edu/FVCOM/index.html\
	in order to download the source code ${DISTFILES}\
	and place it in ${DISTDIR}/${DIST_SUBDIR}/
.endif

post-extract:
	${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

pre-build:
	(cd ${WRKSRC}/../METIS_source && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcom \
		${PREFIX}/bin/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.post.mk>
