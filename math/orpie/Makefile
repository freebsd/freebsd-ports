# New ports collection makefile for:	orpie
# Date created:		 4 August 2004
# Whom:			Dylan Simon <dylan@dylex.net>
#
# $FreeBSD$
#

PORTNAME=	orpie
PORTVERSION=	1.3.1
CATEGORIES+=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/orpie/

MAINTAINER=	dylan@dylex.net
COMMENT=	A fullscreen RPN calculator for the console

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
LIB_DEPENDS= 	gsl.6:${PORTSDIR}/math/gsl

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/orpie bin/orpie-curses-keys etc/orpierc

MAN1=		orpie.1 orpie-curses-keys.1
MAN5=		orpierc.5

.include <bsd.port.mk>
