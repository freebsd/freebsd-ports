# New ports collection makefile for:	netcdf
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netcdf
PORTVERSION=	3.6.2
CATEGORIES=	science
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf/%SUBDIR%/ \
		http://sunpoet.net/distfiles/
MASTER_SITE_SUBDIR=	. old

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Library for machine-independent, array-oriented data access

CONFLICTS=	hdf-4.*

CONFIGURE_ARGS=	--enable-shared --mandir=${PREFIX}/man --disable-f77
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include -fPIC -DPIC -Df2cFortran"

USE_BZIP2=	YES

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	ncdump.1 ncgen.1
MAN3=	netcdf.3

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/ncdump ${PREFIX}/bin/ncgen
	${LN} -fs libnetcdf.so.4 ${PREFIX}/lib/libnetcdf.so
	${LN} -fs libnetcdf_c++.so.4 ${PREFIX}/lib/libnetcdf_c++.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in COPYRIGHT README RELEASE_NOTES
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
