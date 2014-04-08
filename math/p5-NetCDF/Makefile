# Created by: Douglas K. Rand (rand@meridian-enviro.com)
# $FreeBSD$

PORTNAME=	NetCDF
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/netcdf-perl/
PKGNAMEPREFIX=	p5-
DISTNAME=	netcdf-perl-${PORTVERSION}

MAINTAINER=	rand@meridian-enviro.com
COMMENT=	Perl5 module to read and write netCDF files

NETCDF_VER?=	4

.if (${NETCDF_VER} == 4)
LIB_DEPENDS=	libnetcdf.so.7:${PORTSDIR}/science/netcdf4
.else
LIB_DEPENDS=	libnetcdf.so.4:${PORTSDIR}/science/netcdf
.endif

USES=		perl5

WRKSRC=		${WRKDIR}/${DISTNAME}/src
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPP_NETCDF=-I${LOCALBASE}/include LD_NETCDF=-lnetcdf \
		PERL_MANDIR=${STAGEDIR}${MAN1PREFIX}/man PERL=${PERL5}

pre-install:
	@${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' ${WRKSRC}/perl/Makefile

post-install:
	-@[ -d ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto ] && ${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto -name .packlist -exec ${SED} -i '' 's|^${STAGEDIR}||' '{}' \;

.include <bsd.port.mk>
