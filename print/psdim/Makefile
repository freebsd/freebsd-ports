# New ports collection makefile for:    psdim
# Date created:         22 Apr 2005 17:00:00 CEST
# Whom:                 e-masson@kisoft-services.com
#
# $FreeBSD$
#

PORTNAME=	psdim
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.mathstat.dal.ca/~selinger/psdim/download/

MAINTAINER=	e-masson@kisoft-services.com
COMMENT=	Utility that calculates the optimal placement of the pages for n-up printing

#
# define WITH_GHOSTSCRIPT_AFPL=yes for AFPL Postscript interpreter
# instead of GNU one
#
USE_GHOSTSCRIPT=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN1=		psdim.1

.include <bsd.port.mk>
