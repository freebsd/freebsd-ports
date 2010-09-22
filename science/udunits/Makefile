# New ports collection makefile for:	udunits
# Date created:		31 December 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udunits
PORTVERSION=	2.1.19
CATEGORIES=	science math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/udunits/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A library for manipulating units of physical quantities

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_header_CUnit_CUnit_h=no
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
USE_PERL5=	yes

INFO=		udunits2 udunits2lib udunits2prog

.include <bsd.port.mk>
