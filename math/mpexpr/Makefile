# New ports collection makefile for:	mpexpr
# Date created:		20 April 2001
# Whom:			Chuck Hein <geekdude@pacbell.net>
#
# $FreeBSD$
#

PORTNAME=	mpexpr
PORTVERSION=	1.0
CATEGORIES=	math tcl83
MASTER_SITES=	http://www.neosoft.com/tcl/ftparchive/sorted/math/Mpexpr-1.0/1.0/

MAINTAINER=	geekdude@pacbell.net
COMMENT=	Multiple precision math for Tcl

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83

WRKSRC=		${WRKDIR}/mpexpr-1.0/unix

CONFIGURE_ARGS= --prefix=${PREFIX} \
		--exec-prefix=${PREFIX}

GNU_CONFIGURE=	yes
#INSTALLS_SHLIB= yes

MANN=		mpexpr.n

.include <bsd.port.mk>
