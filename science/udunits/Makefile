# New ports collection makefile for:	udunits
# Date created:		31 December 2004
# Whom:			Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	udunits
PORTVERSION=	2.1.9
CATEGORIES=	science math
MASTER_SITES=	ftp://ftp.unidata.ucar.edu/pub/${PORTNAME}/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|glewis/udunits|}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library for manipulating units of physical quantities

GNU_CONFIGURE=	yes
USE_PERL5=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
CFLAGS+=	-fPIC

.include <bsd.port.mk>
