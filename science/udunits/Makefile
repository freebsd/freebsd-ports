# New ports collection makefile for:	udunits
# Date created:		31 December 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udunits
PORTVERSION=	2.1.16
CATEGORIES=	science math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/udunits/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	A library for manipulating units of physical quantities

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USE_PERL5=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_header_CUnit_CUnit_h=no
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

INFO=		udunits2 udunits2lib udunits2prog

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
