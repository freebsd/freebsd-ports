# New ports collection makefile for:	p5-NetCDF
# Date created:				2003-11-17
# Whom:	      				Douglas K. Rand (rand@meridian-enviro.com)
#
# $FreeBSD$
#

PORTNAME=	NetCDF
PORTVERSION=	1.2.2
CATEGORIES=	math perl5
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	netcdf-perl-${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	rand@meridian-enviro.com
COMMENT=	Perl5 module to read and write netCDF files

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPP_NETCDF=-I${LOCALBASE}/include LD_NETCDF=-lnetcdf \
		PERL_MANDIR=${MAN1PREFIX}/man PERL=${PERL5}

MAN1=		netCDFPerl.1

pre-install:
	@${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' ${WRKSRC}/perl/Makefile

.include <bsd.port.mk>
