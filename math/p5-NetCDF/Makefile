# New ports collection makefile for:	p5-NetCDF
# Date created:				2003-11-17
# Whom:	      				Douglas K. Rand (rand@meridian-enviro.com)
#
# $FreeBSD$
#

PORTNAME=	NetCDF
PORTVERSION=	1.2.2
CATEGORIES=	math perl5
MASTER_SITES=	http://www.unidata.ucar.edu/packages/netcdf-perl/
PKGNAMEPREFIX=	p5-
# No version number in distribution file, sigh.
DISTFILES=	netcdf-perl.tar.Z

MAINTAINER=	rand@meridian-enviro.com
COMMENT=	Perl5 module to read and write netCDF files

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf

USE_PERL5=	yes

WRKSRC=		${WRKDIR}/netcdf-perl-${PORTVERSION}/src
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	CPP_NETCDF=-I${PREFIX}/include LD_NETCDF=-lnetcdf PERL_MANDIR=${PREFIX}/lib/perl5/${PERL_VERSION}/man

MAN1PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		netCDFPerl.1

.include <bsd.port.mk>
