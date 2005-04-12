# New ports collection makefile for:	netcdf
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	3.6.0p1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/-p/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for machine-independent, array-oriented data access

WRKSRC=		${WRKDIR}/${DISTNAME}/src

CONFLICTS=	hdf-4.*

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-fPIC -DPIC -Df2cFortran"
INSTALLS_SHLIB=	yes

MAN1=	ncdump.1 ncgen.1
MAN3=	netcdf.3 netcdf.3f

post-build:
	@(cd ${WRKSRC}/libsrc && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)
	@(cd ${WRKSRC}/cxx && \
		${SETENV} ${MAKE_ENV} ${MAKE} linux_shared_library)

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ncdump
	@${STRIP_CMD} ${PREFIX}/bin/ncgen
	${INSTALL_DATA} ${WRKSRC}/libsrc/libnetcdf.so ${PREFIX}/lib/libnetcdf.so.1
	${LN} -sf libnetcdf.so.1 ${PREFIX}/lib/libnetcdf.so
	${INSTALL_DATA} ${WRKSRC}/cxx/libnetcdf_c++.so ${PREFIX}/lib/libnetcdf_c++.so.1
	${LN} -sf libnetcdf_c++.so.1 ${PREFIX}/lib/libnetcdf_c++.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYRIGHT README RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
