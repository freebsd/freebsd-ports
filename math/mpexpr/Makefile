# New ports collection makefile for:	mpexpr
# Date created:		20 April 2001
# Whom:			Chuck Hein <geekdude@pacbell.net>
#
# $FreeBSD$
#

PORTNAME=	mpexpr
PORTVERSION=	1.0
CATEGORIES=	math tcl83
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mpexpr

MAINTAINER=	geekdude@pacbell.net
COMMENT=	Multiple precision math for Tcl

WRKSRC=		${WRKDIR}/mpexpr-1.0/unix

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}

USE_TCL=	83
USE_TCL_BUILD=	83
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MANN=		mpexpr.n

.include <bsd.port.mk>
