# New ports collection makefile for:	orpie
# Date created:		 4 August 2004
# Whom:			Dylan Simon <dylan@dylex.net>
#
# $FreeBSD$
#

PORTNAME=	orpie
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES+=	math
MASTER_SITES=	http://pessimization.com/software/orpie/

MAINTAINER=	dylan@dylex.net
COMMENT=	A fullscreen RPN calculator for the console

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS=	gsl.14:${PORTSDIR}/math/gsl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc

MAN1=		orpie.1 orpie-curses-keys.1
MAN5=		orpierc.5

.include <bsd.port.mk>
